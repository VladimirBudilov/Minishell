#include "../../includes/minishell_structs.h"

t_array_list *add_env(char **envp)
{
    int i;
    i = 0;
    t_array_list *env;

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

    hashmap = malloc(sizeof(t_hashmap));
    array = ft_split(string, '=');
	if(get_array_size(array) > 2)
	{
		hashmap->value = array[1];
		int i = 2;
		while(array[i])
		{
			hashmap->value = ft_strjoin(hashmap->value, "=");
			hashmap->value = ft_strjoin(hashmap->value, array[i]);
			free(array[i]);
			i++;
		}
	}
	else
		hashmap->value = array[1];
    hashmap->key = array[0];
    hashmap->value = array[1];
    if (!ft_strncmp(hashmap->key, "OLDPWD", 6))
	{
		hashmap->value = NULL;
	}
    return hashmap;
}


