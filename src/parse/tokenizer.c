#include <tclDecls.h>
#include "../../includes/minishell.h"

_Bool is_breaking_character(char c)
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
	int i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	return (struct tokenizer_output) {
			.string = input + i,
			.token = (struct token) {
					.type = WHITE_SPACE,
			},
	};
}

void error(char *message)
{
	fprintf(stderr, "Error. %s\n", message);
	exit(1);
}

void bug(char *message)
{
	fprintf(stderr, "Bug. %s\n", message);
	exit(2);
}

struct tokenizer_output tokenize_single_quote(char *input)
{
	int i = 0;

	input++;

	while (input[i] && input[i] != '\'')
		i++;

	if (input[i] == 0)
		error("Unclosed single quote."); // Maybe can read line here instead.

	char *content = strndup(input, i);
	return (struct tokenizer_output) {
			.string = input + i + 1 /* For closing single quote. */,
			.token = (struct token) {
					.type = STRING,
					.content = content,
			},
	};
}

struct tokenizer_output tokenize_bare_word(char *input)
{
	if (is_breaking_character(*input))
		bug("Expected a bare word, but found a breaking character.");

	int i = 0;

	while (input[i] && !is_breaking_character(input[i]))
		i++;

	char *content = strndup(input, i);
	assert(content);
	// printf("Content: %s\n", content);
	return (struct tokenizer_output) {
			.string = input + i,
			.token = (struct token) {
					.type = STRING,
					.content = content,
			},
	};
}


void add_token(struct token t, t_shell *shell)
{
	add_element(shell->tokens_array, &t);
}

void tokenize(t_shell *shell)
{
	char *input = shell->input;

	while (*input)
	{
		if(*input == ' ')
		{ // White space.
			struct tokenizer_output po = tokenize_white_space(input);
			input = po.string;
			add_token(po.token, shell);
		}
		else if(*input == '\'')
		{ // Single quote.
			struct tokenizer_output po = tokenize_single_quote(input);
			input = po.string;
			add_token(po.token, shell);
		}

		// case '<': {
		// 	if (input[1] && input[1] == '<')
		// 		tokenize_less_less(...)
		// 	else
		// 		tokenize_less(...)
		// }
		else if(ft_isascii(*input) && !is_breaking_character(*input))
		{ // Bare word.
			struct tokenizer_output po = tokenize_bare_word(input);
			input = po.string;
			add_token(po.token, shell);
		}
	}
	add_token((struct token) {.type = END}, shell);
}


// char* cmd[] = {"echo", "\"hello\"", "worldquote"};


