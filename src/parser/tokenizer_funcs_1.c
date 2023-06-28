#include "../../includes/minishell.h"

t_tokenizer_output *tokenize_white_space(char *input, t_shell *shell)
{
	t_tokenizer_output *po;
	t_lexer_token *t;
	int i;

	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	add_element(shell->tokenizer_array, po);
	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	po->string = (input + i);
	t->type = WHITE_SPACE;
	t->content = ft_strdup(" ");
	po->token = *t;
    free(t);
	return po;
}

t_tokenizer_output *tokenize_single_quote(char *input, t_shell *shell)
{
	int i;
	t_tokenizer_output *po;
	t_lexer_token *t;

	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	add_element(shell->tokenizer_array, po);
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
    free(t);
	return po;
}


t_tokenizer_output *tokenize_double_quote(char *input, t_shell *shell)
{
	int i;
	t_tokenizer_output *po;
	t_lexer_token *t;
    char *temp;

	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	add_element(shell->tokenizer_array, po);
	input++;
	i = 0;
	t->content = ft_strdup("");
	while (input[i] && input[i] != '\"')
	{
		if (input[i] == '$')
		{
            i += open_dollar(input + i, shell, t);
            continue;
		}
        t->content = ft_strjoin(t->content, (temp = ft_strndup(input + i, 1)));
        free(temp);
		i++;
	}
    if (input[0] == 0)
        error("Unclosed double quote.");
	po->string = input + i + 1;
	t->type = DOUBLE_QUOTES;
	po->token = *t;
    free(t);
	return po;
}

t_tokenizer_output *tokenize_bare_word(char *input, t_shell *shell)
{
	t_tokenizer_output *po;
	t_lexer_token *t;

	int i = 0;
	while (input[i] && !is_breaking_character(input[i]))
		i++;
	t = malloc(sizeof(t_lexer_token));
	po = malloc(sizeof(t_tokenizer_output));
	add_element(shell->tokenizer_array, po);
	t->type = BARE_WORD;
	t->content = ft_strndup(input, i);
	po->string = input + i;
	po->token = *t;
    free(t);
	return po;
}