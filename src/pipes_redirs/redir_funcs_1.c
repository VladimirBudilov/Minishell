#include "../../includes/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *gen_random_name(void) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int name_length = 10;  // Adjust the desired length of the random name
    char *name = (char *)malloc((name_length + 1) * sizeof(char));

    if (name == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    srand(time(NULL));

    for (int i = 0; i < name_length; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        name[i] = charset[index];
    }

    name[name_length] = '\0';  // Null-terminate the string

    return name;
}

int has_redir(t_array_list *tokens) {
    int i;

    i = 0;
    while(i < tokens->size)
    {
        if(is_redir(((t_parser_token **)tokens->array)[i]))
            return (1);
        i++;
    }
    return (0);
}