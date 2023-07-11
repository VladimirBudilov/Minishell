/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:06:05 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/03 13:34:39 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**new_arr(t_array_list *line)
{
	int				i;
	t_parser_token	**token_key;
	char			**arr;

	i = 0;
	token_key = (t_parser_token **)line->array;
	arr = (char **)malloc(sizeof(char *) * ((line->size) + 1));
	while (i < line->size)
	{
		arr[i] = ft_strdup(token_key[i]->content);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int execve_wrapper(char *path, char **argv, t_array_list *internal_env) {
	int size = internal_env->size;
	t_hashmap **array = (t_hashmap **)(internal_env->array);

	char **envp = malloc(sizeof(char *) * (size + 1));
	if (envp == 0) exit(1);

	envp[size] = 0;
	for (int i = 0; i < size; i++) {
		if (asprintf(&envp[i], "%s=%s", array[i]->key, array[i]->value) < 0)
			exit(1);
	}

	return execve(path, argv, envp);
}

void	absolute_path(
	t_parser_token **token_key,
	char **argv,
	t_array_list *internal_env
)
{
	int	pid;
	int	status;

	pid = fork();
	define_signals();
	if (pid == 0)
	{
		execve_wrapper(token_key[0]->content, argv, internal_env);
		free_arr(argv);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	g_err_no = WEXITSTATUS(status);
}

void	relative_path(t_parser_token **t, \
		char **argv, char **path, t_array_list *internal_env)
{
	int		pid;
	int		status;
	int		i;
	char	*s;

	s = NULL;
	pid = fork();
	define_signals();
	i = -1;
	if (pid == 0)
	{
		while (++i < get_array_size(path))
		{
			s = ft_strjoin(ft_strjoin(ft_strdup(path[i]), "/"), t[0]->content);
			if (access(s, X_OK) == 0)
			{
				execve_wrapper(s, argv, internal_env);
				break ;
			}
		}
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	free(s);
	g_err_no = WEXITSTATUS(status);
}

void	ex_func(t_array_list *line, t_shell *shell)
{
	char			**argv;
	char			**path;
	t_parser_token	**token_key;

	token_key = (t_parser_token **)line->array;
	argv = new_arr(line);
	if (token_key[0]->main_type == EXECUTABLE)
	{
		absolute_path(token_key, argv, shell->env);
		free_arr(argv);
		return ;
	}
	path = ft_split(get_value_by_key(shell->env, "PATH"), ':');
	relative_path(token_key, argv, path, shell->env);
	free_arr(path);
	free_arr(argv);
}
