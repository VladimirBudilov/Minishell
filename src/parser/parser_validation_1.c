#include "../../includes/minishell.h"

void find_build_in(ArrayList *parser_tokens)
{
    int i;
    t_parser_token **tokens;

    tokens = (t_parser_token **) parser_tokens->array;
    i = 0;
    while (i < parser_tokens->size)
    {
        if(tokens[i]->main_type == WORDLIST)
        {
            add_echo(tokens[i]);
            add_cd(tokens[i]);
            add_pwd(tokens[i]);
            add_exprt(tokens[i]);
            add_unset(tokens[i]);
            add_envp(tokens[i]);
            add_exit(tokens[i]);
        }
        i++;
    }
}
/*
void validate_tokens(ArrayList *parser_tokens) {


}

void find_execver(ArrayList *parser_tokens) {


}
*/
