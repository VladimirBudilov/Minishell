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
        list->array = ft_realloc(list->array, list->capacity * sizeof(void *));
    }
    list->array[list->size] = element;
    list->size++;
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




