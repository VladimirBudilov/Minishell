#include "../../includes/minishell_structs.h"


t_array_list *createArrayList()
{
	t_array_list *list = (t_array_list *) malloc(sizeof(t_array_list));
	list->size = 0;
	list->capacity = 1000;
	list->array = (void **) malloc(list->capacity * sizeof(void *));
	return list;
}

void add_element(t_array_list *list, void *element)
{
	if (list->size == list->capacity)
	{
		list->capacity *= 2;
		list->array = ft_realloc(list->array, list->capacity * sizeof(void *));
	}
	list->array[list->size] = element;
	list->size++;
}

void delete_element(t_array_list *list, int index)
{
	if (index >= list->size)
	{
		return;
	}
	while (index < list->size - 1)
	{
		list->array[index] = list->array[index + 1];
		index++;
	}
	list->size--;
}

//free all elements in list
void free_arrayList(t_array_list *list)
{
	int i;
	i = 0;
	while (i < list->size)
	{
		free(list->array[i]);
		i++;
	}
	free(list->array);
	free(list);
}





