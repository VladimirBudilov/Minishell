#include "../../includes/minishell.h"

void *find_element_by_index(ArrayList *list, int index) {
    if (index >= list->size) {
        return NULL;
    }
    return list->array[index];
}

void print_all_tokens(ArrayList *list) {
    int i;
    i = 0;
    while (i < list->size) {
        printf("%d\n", ((int) ((t_token *) list->array[i])->type));
        printf("%s\n", ((t_token *) list->array[i])->content);
        i++;
    }
}

int ft_strcmp(const char *s1, const char *s2) {
    int i;
    const char *str1;
    const char *str2;

    i = 0;
    str1 = s1;
    str2 = s2;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i])
            return ((unsigned char) str1[i] - (unsigned char) str2[i]);
        i++;
    }
    return (0);
}