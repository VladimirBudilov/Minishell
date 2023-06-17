#include "../../includes/minishell.h"

//првоерить по тест кейсам
//зафришить

void change_path(t_hashmap **hashmap_key, char *path)
{
    char *pwd;
    char buf[PATH_MAX];
    int i;

    i = 0;
    pwd = getcwd(buf, PATH_MAX);
    while(hashmap_key[i])
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
    while(hashmap_key[i])
    {
        if (!ft_strncmp(hashmap_key[i]->key, "PWD", 3))
            hashmap_key[i]->value = ft_strdup(pwd);
        i++;
    }  
}

char *find_path(t_hashmap **hashmap_key, int task)
{
    int i;
    char *path;

    i = 0;
    while(hashmap_key[i])
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

void to_home(t_hashmap **hashmap_key)
{
    char *path;
    path = ft_strdup(find_path(hashmap_key, 3));
    if (path == NULL)
    {
        ft_putstr_fd("minishell: cd: HOME not set\n", 2);
        free(path);
    }
    change_path(hashmap_key, path);
}

void change_old_path(t_hashmap **hashmap_key, char *path)
{
    ft_putstr_fd(path, 1);
    write(1, "\n", 1);
    change_path(hashmap_key, path);
}


void cd_func(t_hashmap **hashmap_key, t_parser_token **token_key, int size)
{
    char *path;

    if (size <= 2 || !ft_strncmp(token_key[2]->content, "~", 2))
    {
        to_home(hashmap_key);
        return ;
    }
    else if (!ft_strncmp(token_key[2]->content, "-", 2))
    {
        path = ft_strdup(find_path(hashmap_key, 2));
        if (path == NULL)
        {
            ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
            return ;
        }
        change_old_path(hashmap_key, path);
    }
    else
    {
        if (ft_strchr(token_key[2]->content, '~'))
        {
            path = ft_strdup(find_path(hashmap_key, 3));
            path = ft_strjoin(path, ft_strchr(token_key[2]->content, '/'));
        }
        else
            path = ft_strdup(token_key[2]->content);
        change_path(hashmap_key, path);
    }
    free(path);
}