#include "../../includes/minishell.h"

//првоерить по тест кейсам
//зафришить

void change_path(t_hashmap **hashmap_key, char *path, t_shell *shell)
{
    char *pwd;
    char buf[PATH_MAX];
    int i;

    i = 0;
    pwd = getcwd(buf, PATH_MAX);
    while(i < shell->env->size)
    {
        if (!ft_strncmp(hashmap_key[i]->key, "OLDPWD", 6))
            hashmap_key[i]->value = ft_strdup(pwd);
        i++;
    }    
    if (chdir(path) != 0)
    {
        ft_putstr_fd("minishell: cd: ", 2);
        ft_putstr_fd(path, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
    }
    pwd = getcwd(buf, PATH_MAX);
    i = 0;
    while(i < shell->env->size)
    {
        if (!ft_strncmp(hashmap_key[i]->key, "PWD", 3))
            hashmap_key[i]->value = ft_strdup(pwd);
        i++;
    }
}

char *find_path(t_hashmap **hashmap_key, t_shell *shell, int task)
{
    int i;
    char *path;

    i = 0;
    while(i < shell->env->size)
    {
        if (!ft_strncmp(hashmap_key[i]->key, "PWD", 3) && task == 1)
            path = hashmap_key[i]->value;
        if (!ft_strncmp(hashmap_key[i]->key, "OLDPWD", 6) && task == 2)
            path = hashmap_key[i]->value;
        if (!ft_strncmp(hashmap_key[i]->key, "HOME", 4) && task == 3)
            path = hashmap_key[i]->value;
        i++;
    }
    return (path);
}

void to_home(t_hashmap **hashmap_key, t_shell *shell)
{
    char *home_path;
	home_path = ft_strdup(find_path(hashmap_key, shell, 3));
	if (home_path == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		free(home_path);
	} else
		change_path(hashmap_key, home_path, shell);

}

void change_old_path(t_hashmap **hashmap_key, char *path, t_shell *shell)
{
    ft_putstr_fd(path, 1);
    write(1, "\n", 1);
    change_path(hashmap_key, path, shell);
}


void cd_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell)
{
    char *path;
	int i;

	t_parser_token **token_key;
	i = 2;
	token_key = (t_parser_token **)line->array;
	if (token_key[0]->main_type == NEW_SPACE)
		i++;
    if (line->size <= 2 || !ft_strncmp(token_key[i]->content, "~", 2))
    {
        to_home(hashmap_key, shell);
        return ;
    }
    else if (!ft_strncmp(token_key[i]->content, "-", 2))
    {
        path = ft_strdup(find_path(hashmap_key, shell, 2));
        if (path == NULL)
        {
            ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
            return ;
        }
        change_old_path(hashmap_key, path, shell);
    }
    else
    {
        if (ft_strchr(token_key[i]->content, '~'))
        {
            path = ft_strdup(find_path(hashmap_key, shell, 3));
            path = ft_strjoin(path, ft_strchr(token_key[i]->content, '/'));
        }
        else
            path = ft_strdup(token_key[i]->content);
        change_path(hashmap_key, path, shell);
    }
    free(path);
}