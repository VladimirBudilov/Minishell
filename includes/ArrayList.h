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

/*MAIN*/
ArrayList* createArrayList();
void add_element(ArrayList* list, void *element);
void delete_element(ArrayList* list, int index);
void free_arrayList(ArrayList* list);

/*HELPERS*/
char *get_element_by_key(ArrayList* list, char *key);
void print_all_tokens(ArrayList *list);
void *find_element_by_index(ArrayList* list, int index);
int contain_key(ArrayList* list, char *key);

/*UTILS*/
int	ft_strcmp(const char *s1, const char *s2);
t_hashmap *create_hashmap(char *string);


#endif //MINI_ARRAYLIST_H
