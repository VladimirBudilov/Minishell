#include "../../includes/minishell.h"
void clean_all(t_shell *shell) {
    free_env(shell->env);

}

void free_env(ArrayList *tokens) {
    int i;
    i = 0;
    while (i < tokens->size) {
        free(((t_hashmap *) tokens->array[i])->key);
        free(((t_hashmap *) tokens->array[i])->value);
        free(tokens->array[i]);
        i++;
    }
    free(tokens->array);
    free(tokens);

}

void print_all_args(ArrayList *list)
{
    int i;
    i = 0;
    while (i < list->size)
    {
        printf("parser type %d parser content : %s\n", ((t_parser_token *) list->array[i])->main_type,
               ((t_parser_token *) list->array[i])->content);
        i++;
    }
    printf("\n");
}

void clean_array(t_shell *minishell)
{
    free_tokenizer_output_array(minishell->tokenizer_array);
    free_parser_tokens(minishell->parser_tokens_array);
    minishell->lexer_tokens_array->size = 0;
    minishell->parser_tokens_array->size = 0;
    minishell->tokenizer_array->size = 0;
    free(minishell->input);

}

void free_parser_tokens(ArrayList *tokens) {
    int i;
    t_parser_token *po;
    t_parser_token **array;

    i = 0;
    array = (t_parser_token **) tokens->array;
    while (i < tokens->size)
    {
        po = array[i];
        free(po->content);
        free(po);
        i++;
    }

}

void free_tokenizer_output_array(ArrayList *tokens) {
    int i;
    t_tokenizer_output *po;
    t_tokenizer_output **array;

    i = 0;
    array = (t_tokenizer_output **) tokens->array;
    while (i < tokens->size)
    {
        po = array[i];
        free(po->token.content);
        free(po);
        i++;
    }

}