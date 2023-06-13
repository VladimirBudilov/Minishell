#include "../../includes/minishell_structs.h"

ArrayList* createArrayList() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->size = 0;
    list->capacity = 10;
    list->array = (void **)malloc(list->capacity * sizeof(void *));
    return list;
}

void add_element(ArrayList* list, void *element)
{
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = realloc(list->array, list->capacity * sizeof(void *));
    }
    list->array[list->size] = element;
    list->size++;
}

void print_all_tokens_arraylist(ArrayList *list)
{
    int i;
    i = 0;
    while (i < list->size)
    {
        printf("%d\n", ((int)((t_token *)list->array[i])->type));
        printf("%s\n", ((t_token *)list->array[i])->content);
        i++;
    }
}

void delete_element(ArrayList* list, int index)
{
    if (index >= list->size) {
        return;
    }
    while(index < list->size - 1) {
        list->array[index] = list->array[index + 1];
        index++;
    }
    list->size--;
}

t_hashmap *find_element_by_key(ArrayList* list, char *key)
{
    int i;
    i = 0;
    while (i < list->size)
    {
        if (ft_strcmp(((t_hashmap *)list->array[i])->key, key) == 0)
            return list->array[i];
        i++;
    }
    return NULL;
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

void *find_element_by_index(ArrayList* list, int index)
{
    if (index >= list->size) {
        return NULL;
    }
    return list->array[index];
}

int				ft_strcmp(const char *s1, const char *s2)
{
    int			i;
    const char	*str1;
    const char	*str2;

    i = 0;
    str1 = s1;
    str2 = s2;
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return ((unsigned char)str1[i] - (unsigned char)str2[i]);
        i++;
    }
    return (0);
}

