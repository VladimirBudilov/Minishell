#include "../../includes/minishell.h"


void execute_redir(t_array_list *parser_array) {

    t_parser_token **token_key;
    int i;

    i = 0;
    token_key = (t_parser_token **)parser_array->array;
    while(i < parser_array->size)
    {
        if(token_key[i]->main_type == REDIRECT_OUTPUT)
            redir_out_func(parser_array, i);
        else if(token_key[i]->main_type == REDIRECT_APPEND_OUTPUT)
            redir_out_append_func(parser_array, i);
        else if(token_key[i]->main_type == REDIRECT_INPUT)
            redir_in_func(parser_array, i);
        else if(token_key[i]->main_type == HEREDOC)
            redir_heredoc(parser_array, i);
        i++;
    }
}

void redir_in_func(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;

    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(token_key[i]->file, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    delete_element(parser_tokens, i);
    delete_element(parser_tokens, i);
}

void redir_out_append_func(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;

    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(token_key[i]->file, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    delete_element(parser_tokens, i);
}

void redir_out_func(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;

    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(token_key[i]->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    delete_element(parser_tokens, i);
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

char    *generate_random_name(void)
{
    char			buff[4];
    char			*name;
    int				fd;
    int				nbr;

    name = ft_calloc(1, sizeof(char));
    fd = open("/dev/urandom", O_RDONLY);
    if (fd < -1)
        return ("ERROR");
    read(fd, buff, 4);
    nbr = *(int *)buff;
    if (nbr < 0)
        nbr++;
    if (nbr < 0)
    {
        nbr = nbr * (-1);
        *name = ('a' + nbr % 26);
    }
    return (name);
}

void redir_heredoc(t_array_list *parser_tokens, int i) {
    int fd;
    char *random_name;
    t_parser_token **token_key;
    char *input;

    random_name = generate_random_name();
    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(random_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }

    while(1)
    {
        input = readline("> ");
        ft_putstr_fd(input, fd);
        if (ft_strcmp(input, token_key[i]->file) == 0)
            break;
        write(fd, input, ft_strlen(input));
        write(fd, "\n", 1);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    delete_element(parser_tokens, i);
}
