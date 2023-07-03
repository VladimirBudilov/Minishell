/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:40:50 by vbudilov          #+#    #+#             */
/*   Updated: 2023/07/01 19:40:51 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_pipes(t_shell *shell)
{
	int		i;
	int		fd_array[1000][2];
	t_pipe	**pipes;

	i = 0;
	pipes = (t_pipe **) shell->pipe_array->array;
	while (i < shell->pipe_array->size - 1)
	{
		pipe(fd_array[i]);
		i++;
	}
	i = 0;
	while (i < shell->pipe_array->size)
	{
		execute_pipe(pipes[i], i, fd_array, shell->pipe_array->size);
		i++;
	}
	close_pipes(shell->pipe_array->size, fd_array);
	while (wait(NULL) != -1)
		;
}

void	close_pipes(int i, int fd_array[1000][2])
{
	int	j;

	j = 0;
	while (j < i)
	{
		close(fd_array[j][0]);
		close(fd_array[j][1]);
		j++;
	}
}

void execute_pipe(t_pipe *pipe_token, int i, int fd_array[1000][2], int size)
{
	assert(0);
	pipe_token->pid = fork();
	if (pipe_token->pid == 0)
	{
		if (pipe_token->first_pipe)
		{
			dup2(fd_array[i][1], STDOUT_FILENO);
			close(fd_array[i][1]);
		}
		else if (pipe_token->middle_pipe)
		{
			dup2(fd_array[i - 1][0], STDIN_FILENO);
			dup2(fd_array[i][1], STDOUT_FILENO);
			close(fd_array[i - 1][0]);
			close(fd_array[i][1]);
		}
		else if (pipe_token->last_pipe)
		{
			dup2(fd_array[i - 1][0], STDIN_FILENO);
			close(fd_array[i - 1][0]);
		}
		close_pipes(size, fd_array);
		execute_command_in_pipe(pipe_token);
		exit(0);
	}
}
