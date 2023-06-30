#include "../../includes/minishell.h"


void create_pipe_list(t_shell *shell)
{
    int index;
    int prev_index;
    int last_pipe;
    t_parser_token **parser_tokens;
    if(shell->cant_execute)
        return ;
    if(shell->number_of_pipes > 250) {
        shell->cant_execute = 1;
        printf("fork: Resource temporarily unavailable\n");
        return ;
    }
    index = 0;
    last_pipe = 0;
    prev_index = 0;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;

    while (index < shell->parser_tokens_array->size)
    {
        if(parser_tokens[index]->main_type == PIPELINE)
        {
            last_pipe = index;
            last_pipe++;
            add_command(shell, index, prev_index);
            index++;
            prev_index = index;
            continue;
        }
        index++;
    }
    add_last_command(shell, last_pipe);
    //system("leaks -fullContent minishell");
}

