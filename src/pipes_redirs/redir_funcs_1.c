#include "../../includes/minishell.h"

int remove_space(t_array_list *parser_tokens, int index);

int redir_out_append_func(t_array_list *parser_tokens, int i)
{
	int				fd;
	t_parser_token	**token_key;

	token_key = (t_parser_token **)parser_tokens->array;
	fd = open(token_key[i]->file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd < 0)
	{
		ft_putstr_fd("shell: ", 2);
		ft_putstr_fd(token_key[i + 1]->content, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	delete_parse_element(parser_tokens, i);
	remove_space(parser_tokens, i);
	return (i);
}

int redir_out_func(t_array_list *parser_tokens, int i)
{
	int				fd;
	t_parser_token	**token_key;

	token_key = (t_parser_token **)parser_tokens->array;
	fd = open(token_key[i]->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        exit(0);
    }
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("index: %d\n", i);
	printf("file: %s\n", token_key[i]->file);
	delete_parse_element(parser_tokens, i);
	remove_space(parser_tokens, i);
	return (i);
}

int redir_in_func(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;

    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(token_key[i]->file, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        exit(0);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
	printf("index: %d\n", i);
	delete_parse_element(parser_tokens, i);
	//remove_space(parser_tokens, i);
	return (i);
}

int remove_space(t_array_list *parser_tokens, int index) {
	t_parser_token	**array;

	array = (t_parser_token **)parser_tokens->array;

	if (array[index]->main_type == NEW_SPACE)
	{
		delete_element(parser_tokens, index);
		return (1);
	}
	return (0);
}

int redir_heredoc(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;
    char *input;
    token_key = (t_parser_token **)parser_tokens->array;
    token_key[i]->heredoc = gen_random_name();
    fd = open(token_key[i]->heredoc, O_CREAT | O_APPEND | O_EXCL | O_RDWR, 0400 | 0200 | 0040 | 0004);
    if (fd < 0) {
        ft_putstr_fd("shell heredoc: ", 2);
        ft_putstr_fd(token_key[i]->heredoc, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        exit(0);
    }
    while (1) {
        input = readline("> ");
        if (ft_strcmp(input, token_key[i]->file) == 0)
            break;
        write(fd, input, ft_strlen(input));
        write(fd, "\n", 1);
    }
    close(fd);
    fd = open(            token_key[i]->heredoc, O_RDONLY);
    if (fd == -1) {
        ft_putstr_fd("shell heredoc: ", 2);
        ft_putstr_fd(                token_key[i]->heredoc, 2);
        ft_putstr_fd(": Failed to open file\n", 2);
        free(                token_key[i]->heredoc);
        return (0);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
	delete_parse_element(parser_tokens, i);
	i -= remove_space(parser_tokens, i);
	return (i);
}
