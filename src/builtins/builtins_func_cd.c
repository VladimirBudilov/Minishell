#include "../../includes/minishell.h"



void save_old_pwd_path(t_hashmap **hashmap_key)
{
    int i;
    char *pwd_key;

    i = -1;
    while (hashmap_key[++i])
        if (!ft_strncmp (hashmap_key[i]->key, "PWD", 3))
            pwd_key = hashmap_key[i]->value;
    i = -1;
    while (hashmap_key[++i])
    {
        if (!ft_strncmp (hashmap_key[i]->key, "OLDPWD", 6))
        {
            if (hashmap_key[i]->value == NULL)
            {
                hashmap_key[i]->value = calloc(1, 1);
                hashmap_key[i]->value = ft_strdup(pwd_key);
            }
            else
            {
                free(hashmap_key[i]->value);
                hashmap_key[i]->value = ft_strdup(pwd_key);
            }
        }
    }
}



void change_path(t_hashmap **hashmap_key, char *path)
{
    char *pwd;
    char buf[PATH_MAX];
    int i;

    i = 0;
    pwd = getcwd(buf, PATH_MAX);
    printf("pwd = %s\n", pwd);
    while(hashmap_key[i])
    {
        if (!ft_strncmp(hashmap_key[i]->key, "OLDPWD", 6))
        {
            //free(hashmap_key[i]->value);
            hashmap_key[i]->value = pwd;
            free(pwd);
        }
        i++;
    }    
    if (chdir(path) != 0)
    {
        ft_putstr_fd("cd: ", 2);
        ft_putstr_fd(path, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
    }
    pwd = getcwd(buf, PATH_MAX);
    printf("pwd 2 = %s\n", pwd);
    while(hashmap_key[i])
    {
        if (!ft_strncmp(hashmap_key[i]->key, "PWD", 3))
        {
            //free(hashmap_key[i]->value);
            hashmap_key[i]->value = pwd;
            free(pwd);
        }
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
        ft_putstr_fd("cd: HOME not set\n", 2);
        free(path);
    }
    change_path(hashmap_key, path);
}


void cd_func(t_hashmap **hashmap_key, t_token **token_key, int size)
{

   // char *path;

    if (size <= 2 || token_key[3]->content[0] == '~')
    {
        to_home(hashmap_key);
        return ;
    }

    //save_old_pwd_path(hashmap_key);
}