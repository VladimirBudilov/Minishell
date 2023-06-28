#include "../../includes/minishell_structs.h"


void delete_hashmap(t_hashmap *hashmap);

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
        if(ft_strcmp(hashmap->key, "OLDPWD") == 0)
        {
            delete_hashmap(hashmap);
            i++;
            continue;
        }
        add_element(env, hashmap);
        i++;
    }
    return env;
}

void delete_hashmap(t_hashmap *hashmap) {
    free(hashmap->key);
    free(hashmap->value);
    free(hashmap);
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
	else
		hashmap->value = array[1];
    return hashmap;
}


