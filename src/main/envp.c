#include "../../includes/minishell_structs.h"

ArrayList *add_env(char **envp)
{
    int i;
    i = 0;
    ArrayList *env;

    env = createArrayList();
    while(envp[i])
    {
        add_element(env, create_hashmap(envp[i]));
        i++;
    }
    return env;
}

t_hashmap *create_hashmap(char *string)
{
    t_hashmap *hashmap;
    char **array;

    hashmap = (t_hashmap *)malloc(sizeof(t_hashmap));
    array = ft_split(string, '=');
    hashmap->key = array[0];
    hashmap->value = array[1];
    return hashmap;
}