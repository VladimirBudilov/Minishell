#include "../../includes/minishell.h"

void create_pipe_list(t_shell *shell)
{
    int index;
    int prev_index;
    int pipe_count;
    t_parser_token **parser_tokens;

    index = 0;
    prev_index = 0;
    pipe_count = 0;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;

    while (index < shell->parser_tokens_array->size)
    {
        if(parser_tokens[index]->main_type == PIPELINE)
        {
                add_command(shell, &index, &prev_index);
                index++;
                pipe_count++;
                continue;
        }
        if(pipe_count == shell->number_of_pipes) {
            add_last_command(shell, &index);
            index++;
            break;
        }
        index++;
    }
}




