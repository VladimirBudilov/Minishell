#include "../../includes/minishell_structs.h"

t_array_list *add_env(char **envp)
{
    int i;
    i = 0;
    t_array_list *env;
    t_hashmap *hashmap;
    env = createArrayList();
    while(envp[i])
    {
        hashmap =  create_hashmap(envp[i]);
        add_element(env, hashmap);
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
    hashmap->key = array[0];
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
	else if(ft_strncmp(array[0], "OLDPWD", 6) == 0)
		hashmap->value = NULL;
    else
        hashmap->value = array[1];
    return hashmap;
}


