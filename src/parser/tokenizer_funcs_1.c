#include "../../includes/minishell.h"

t_tokenizer_output *tokenize_white_space(char *input)
{
	t_tokenizer_output *po;
	t_lexer_token *t;
	int i;

	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	po->string = (input + i);
	t->type = WHITE_SPACE;
	t->content = ft_strdup(" ");
	po->token = *t;
	return po;
}

t_tokenizer_output *tokenize_single_quote(char *input)
{
	int i;
	t_tokenizer_output *po;
	t_lexer_token *t;

	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	i = 0;
	input++;
	while (input[i] && input[i] != '\'')
		i++;
	if (input[i] == 0)
		error("Unclosed single quote.");
	po->string = input + i + 1;
	t->type = SINGLE_QUOTES;
	t->content = ft_strndup(input, i);
	po->token = *t;
	return po;
}

t_tokenizer_output *tokenize_double_quote(char *input, t_shell *shell)
{
	int i;
	t_tokenizer_output *po;
	t_lexer_token *t;

	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	input++;
	i = 0;
	while (input[i] && input[i] != '\"')
		i++;
	if (input[i] == 0)
		error("Unclosed double quote.");
	i = 0;
	t->content = ft_strdup("");
	while (input[i] && input[i] != '\"')
	{
		if (input[i] == '$')
		{
			t->content = ft_strjoin(t->content, ft_strndup(input, i));
			input = open_dollar(input + i + 1, shell, t);
			i = 0;
			continue;
		}
		i++;
	}
	po->string = input + i + 1;
	t->type = DOUBLE_QUOTES;
	t->content = ft_strjoin(t->content, ft_strndup(input, i));
	po->token = *t;
	return po;
}

t_tokenizer_output *tokenize_bare_word(char *input)
{
	t_tokenizer_output *po;
	t_lexer_token *t;

	if (is_breaking_character(*input))
		bug("Expected a bare word, but found a breaking character.");
	int i = 0;

	while (input[i] && !is_breaking_character(input[i]))
		i++;
	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	t->type = BARE_WORD;
	t->content = ft_strndup(input, i);
	po->string = input + i;
	po->token = *t;

	return po;
}