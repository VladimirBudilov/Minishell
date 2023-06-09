#include "../includes/minishell_structs.h"

void print_env_from_arraylist(ArrayList *env) {
    int i;
    i = 0;
    while (i < env->size)
    {
        printf("%s\n", ((t_hashmap *)env->array[i])->key);
        printf("%s\n", ((t_hashmap *)env->array[i])->value);
        i++;
    }
}

ArrayList *add_env(t_shell *minishell, char **envp)
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