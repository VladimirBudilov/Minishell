#include "../../includes/minishell.h"


void clean_all(t_shell *shell) {
    free_env(shell->env);

}

void free_env(t_array_list *tokens) {
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

void clean_array(t_shell *minishell)
{
    minishell->cant_execute = 0;
    free(minishell->input);
    free_tokenizer_output_array(minishell->tokenizer_array);
    free_parser_tokens(minishell->parser_tokens_array);
    minishell->lexer_tokens_array->size = 0;
    minishell->parser_tokens_array->size = 0;
    minishell->tokenizer_array->size = 0;
    minishell->pipe_array->size = 0;
    clean_pipe_commands(minishell);
    minishell->number_of_pipes = 0;


}

void clean_pipe_commands(t_shell *shell) {
    int i;
    t_pipe **pipes;

    i = 0;
    pipes = (t_pipe **) shell->pipe_array->array;
    while (i < shell->pipe_array->size) {

        pipes[i]->commands->size = 0;
        i++;
    }
}

void free_parser_tokens(t_array_list *tokens) {
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

void free_tokenizer_output_array(t_array_list *tokens) {
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

int ft_is_ascii(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(!ft_isascii(str[i]))
            return (0);
        i++;
    }
    return (1);
}
