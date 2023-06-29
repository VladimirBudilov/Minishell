#include "../../includes/minishell.h"

void	validate_tokens(t_array_list *parser_tokens, t_shell *shell)
{
	if (has_only_new_space(parser_tokens))
	{
		handle_cant_execute(shell);
		return ;
	}
	if (ends_with_pipeline(parser_tokens) || ends_with_redir(parser_tokens)
		|| has_consecutive_redirs(parser_tokens)
		|| has_redir_before_pipeline(parser_tokens))
	{
		handle_syntax_error(shell);
		return ;
	}
}

int	has_only_new_space(t_array_list *parser_tokens)
{
	t_parser_token	**array;

	array = (t_parser_token **)parser_tokens->array;
	return (parser_tokens->size == 1 && array[0]->main_type == NEW_SPACE);
}

int	ends_with_pipeline(t_array_list *parser_tokens)
{
	t_parser_token	**array;

	array = (t_parser_token **)parser_tokens->array;
	return (array[parser_tokens->size - 1]->main_type == PIPELINE);
}