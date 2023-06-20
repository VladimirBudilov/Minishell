#include "../../includes/minishell.h"

void clean_flags_n(ArrayList *tokens_array, int index);

int is_flag(const char *content);

void add_cd(t_parser_token *token) {
    char *temp;

    temp = ft_str_to_lower(token->content);
    if (ft_strcmp(temp, "cd") == 0) {
        token->main_type = BIlD_IN;
        token->sub_type = CD;
    }
    free(temp);
}

void add_echo(t_parser_token *token, ArrayList *tokens_array, int index) {
    char *temp;

    temp = ft_str_to_lower(token->content);
    if (ft_strcmp(temp , "echo") == 0) {
        token->main_type = BIlD_IN;
        token->sub_type = ECHO;
        clean_flags_n(tokens_array, index);
    }
    free(temp);
}

void clean_flags_n(ArrayList *tokens_array, int index) {
    int flag;
    t_parser_token *token;

    index += 2;
    flag = 0;
    while (index < tokens_array->size) {
        token = find_element_by_index(tokens_array, index);
        if (is_flag(token->content)) {
            if (!flag) {
                flag = 1;
                index++;
                continue;
            }
            delete_element(tokens_array, index - 1);
            index--;
            delete_element(tokens_array, index);
        }
        index++;
    }

}

int is_flag(const char *content) {
    int i;

    i = 0;
    if (content[i++] == '-')
        while (content[i]) {
            if (content[i] != 'n')
                return (0);
            i++;
        }
    else
        return (0);
    return (1);
}



