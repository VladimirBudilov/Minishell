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
} t_array_list;

/*MAIN*/
t_array_list* createArrayList();
void add_element(t_array_list* list, void *element);
void delete_element(t_array_list* list, int index);
void free_arrayList(t_array_list* list);

/*HELPERS*/
char *get_value_by_key(t_array_list* list, char *key);
void print_all_tokens(t_array_list *list);
void *find_element_by_index(t_array_list* list, int index);
int contain_key(t_array_list* list, char *key);
void change_value_by_key(t_array_list* list, char *key, char *value);
void add_element_by_index(t_array_list* list, void *element, int index);

/*UTILS*/
int	ft_strcmp(const char *s1, const char *s2);
t_hashmap *create_hashmap(char *string);
void *ft_realloc(void *ptr, size_t size);


#endif //MINI_ARRAYLIST_H
