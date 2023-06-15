#include "../../includes/minishell.h"

char *get_element_by_key(ArrayList* list, char *key)
{
    int i;
    i = 0;
    while (i < list->size)
    {
        if (ft_strcmp(((t_hashmap *)list->array[i])->key, key) == 0)
            return ((t_hashmap *)list->array[i])->value;
        i++;
    }
    return NULL;
}

int contain_key(ArrayList* list, char *key)
{
    int i;
    i = 0;
    while (i < list->size)
    {
        if (ft_strcmp(((t_hashmap *)list->array[i])->key, key) == 0)
            return 1;
        i++;
    }
    return 0;
}

void change_value_by_key(ArrayList* list, char *key, char *value)
{
    int i;
    i = 0;
    while (i < list->size)
    {
        if (ft_strcmp(((t_hashmap *)list->array[i])->key, key) == 0)
        {
            ((t_hashmap *)list->array[i])->value = value;
            return;
        }
        i++;
    }
}