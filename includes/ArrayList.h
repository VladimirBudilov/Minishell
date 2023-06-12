#ifndef MINI_ARRAYLIST_H
#define MINI_ARRAYLIST_H

#include "minishell_structs.h"
#include "minishell_funk.h"

typedef struct s_hashmap
{
    char *key;
    char *value;
}				t_hashmap;

typedef struct s_arrayList
{
    void **array;
    int size;
    int capacity;
} ArrayList;


ArrayList* createArrayList();
void add_element(ArrayList* list, void *element);
void delete_element(ArrayList* list, int index);
t_hashmap *find_element_by_key(ArrayList* list, char *key);
void free_arrayList(ArrayList* list);
t_hashmap *create_hashmap(char *string);
void print_env_from_arraylist(ArrayList *env);
int				ft_strcmp(const char *s1, const char *s2);


#endif //MINI_ARRAYLIST_H
