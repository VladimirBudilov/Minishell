#include "../../includes/minishell.h"

void clean_size(t_shell *shell);

void free_env(ArrayList *list)
{
	int i;
	i = 0;
	while (i < list->size)
	{
		free(((t_hashmap *) list->array[i])->key);
		free(((t_hashmap *) list->array[i])->value);
		free(list->array[i]);
		i++;
	}
	free(list->array);
	free(list);
}

void clean_arrays(t_shell *minishell)
{
	//clen_parser_tokens(minishell->parser_tokens_array);
	//clean_lexer_tokens(minishell->lexer_tokens_array);
	//clean_size(minishell);
	free(minishell->input);
}

void clean_size(t_shell *shell)
{
	int i;
	i = 0;
	while (i < shell->lexer_tokens_array->size)
	{
		free(shell->lexer_tokens_array->array[i]);
		i++;
	}
	free(shell->lexer_tokens_array->array);
	free(shell->lexer_tokens_array);
}

void clean_lexer_tokens(ArrayList *tokens)
{
	int i;
	i = 0;
	while (i < tokens->size)
	{
		free(((t_lexer_token *) tokens->array[i])->content);
		free(tokens->array[i]);
		i++;
	}
}

void clen_parser_tokens(ArrayList *tokens)
{
	int i;
	i = 0;
	while (i < tokens->size)
	{
		free(((t_parser_token *) tokens->array[i])->content);
		free(tokens->array[i]);
		i++;
	}
	free(tokens->array);
}
