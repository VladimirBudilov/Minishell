#include "../../includes/minishell.h"

int is_breaking_character(char c)
{
	char breaking_characters[] = "'\"<>|$ \n\t"; // & if bonus.

	int size = sizeof breaking_characters / sizeof *breaking_characters - 1;
	for (int i = 0; i < size; i++)
	{
		if (c == breaking_characters[i])
			return 1;
	}
	return 0;
}

struct tokenizer_output tokenize_white_space(char *input)
{
	t_tokenizer_output po;
	int i;

	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	po.string = input + i;
	po.token.type = WHITE_SPACE;
	return po;
}

struct tokenizer_output tokenize_single_quote(char *input)
{
	int i;
	t_tokenizer_output po;

	i = 0;

	input++;

	while (input[i] && input[i] != '\'')
		i++;

	if (input[i] == 0)
		error("Unclosed single quote."); // Maybe can read line here instead.

	char *content = strndup(input, i);
	po.string = input + i + 1;
	po.token.type = STRING;
	po.token.content = content;
	return po;

}

struct tokenizer_output tokenize_double_quote(char *input)
{
	int i;
	t_tokenizer_output po;

	i = 0;
	input++;

	while (input[i] && input[i] != '\"')
		i++;
	if (input[i] == 0)
		error("Unclosed single quote."); // Maybe can read line here instead.
	char *content = strndup(input, i);
	po.string = input + i + 1;
	po.token.type = STRING;
	po.token.content = content;
	return po;
}

struct tokenizer_output tokenize_bare_word(char *input)
{
	t_tokenizer_output po;
	t_token *t;

	if (is_breaking_character(*input))
		bug("Expected a bare word, but found a breaking character.");

	int i = 0;

	while (input[i] && !is_breaking_character(input[i]))
		i++;
	t= malloc(sizeof(t_token*));
	char *content = strndup(input, i);

	t->type = STRING;
	t->content = content;

	po.string = input + i;
	po.token = *t;

	return po;
}


char *add_token(t_shell *shell, struct tokenizer_output po)
{
	add_element(shell->tokens_array, &po.token);
	//printf("Content: %s\n", (char *)po.token.content);
	//printf("%s\n", po.string);
	return po.string;
}

void tokenize(t_shell *shell)
{
	char *input = shell->input;

	while (*input)
	{
		if(*input == ' ')
		{ // White space.
			
			input = add_token(shell, (tokenize_white_space(input)));
		}
		else if(*input == '\'')
		{ // Single quote.
			input = add_token(shell, (tokenize_single_quote(input)));
		}

		/*if(*input == '<')
		{
		 	if (*(input+1) && *(input+1) == '<')
		 		tokenize_less_less()
		 	else
		 		tokenize_less()
		}*/
		else if(ft_isalpha(*input) && !is_breaking_character(*input))
		{ // Bare word.
			printf("1\n");
			input = add_token(shell, (tokenize_bare_word(input)));
			printf("%s\n", input);
		}
		else
			break;
	}
	//add_token((struct token) {.type = END}, shell);
}


// char* cmd[] = {"echo", "\"hello\"", "worldquote"};


