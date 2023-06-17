#include "../../includes/minishell.h"


int get_array_size(char **string);

/*
 Open quote
 redo arraylist
 check build in
 check func in bin(execver)
 check pipe
 check redir

*/

void parse_tokens(t_shell *shell) {
    t_lexer_token **lexer_tokens;
    ArrayList *parser_tokens;
    int size;

    lexer_tokens = (t_lexer_token **) shell->lexer_tokens_array->array;
    parser_tokens = shell->parser_tokens_array;
    size = shell->lexer_tokens_array->size;
    if (size == 0)
        return;
    create_parser_tokens(lexer_tokens, parser_tokens, size);
    find_build_in(parser_tokens);
    find_execver(parser_tokens, shell);
    //validate_tokens(parser_tokens);

}

void find_execver(ArrayList *parser_tokens_array, t_shell *shell)
{
    t_parser_token **parser_tokens;
    char **paths;
    struct stat s;
    int size;

    int i;
    int j;
    parser_tokens = (t_parser_token **)(parser_tokens_array->array);
    i = 0;
    paths = ft_split(ft_strdup(get_value_by_key(shell->env,"PATH")), ':');
    size = get_array_size(paths);
    if(size == 0)
    {
        error("PATH is not set");
        return ;
    }
    while(i < parser_tokens_array->size)
    {
        j = 0;
        while (j < size){
            if (access(ft_strjoin(ft_strjoin(paths[j], "/"), parser_tokens[i]->content), X_OK) != -1)
            {
                stat(ft_strjoin(ft_strjoin(paths[j], "/"), parser_tokens[i]->content), &s);
                if((s.st_mode & S_IEXEC) == 0)
                {
                    parser_tokens[i]->main_type = EXECUTABLE;
                    break ;
                }
                else
                {
                    parser_tokens[i]->main_type = DIRECTORY;
                    break ;
                }
            }
            j++;
        }
    i++;
    }
}

int get_array_size(char **string) {
    int i;

    i = 0;
    while (string[i])
        i++;
    return i;
}















