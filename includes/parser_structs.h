//
// Created by Vladimir Budilov on 6/10/23.
//

#ifndef MINI_PARSER_H
#define MINI_PARSER_H

#include "minishell.h"

enum token_type {
	END,
	STRING,
	WHITE_SPACE,
	LESS_THAN_LESS_THAN,
	LESS_THAN,
	DOLLAR, // Content.
	PIPE,
	GREATER_THAN,
	GREATER_THAN_GREATER_THAN,
	BARE_WORD,
	SINGLE_QUOTES,
	DOUBLE_QUOTES,
};

typedef struct token {
	enum token_type type;
	char *content;
} t_token;

typedef struct tokenizer_output {
	char *string;
	struct token token;
} t_tokenizer_output;

/*
struct token_inside_double_quotes {
	_Bool is_dollar;
	char *string;
};

// "abc $?$$foo$kek$/something$"
(token){
	.type = DOUBLE_QUOTES,
	.content = (struct token_inside_double_quotes[]){
		{
			.is_dollar = 0,
			.string = "abc ",
		},
		{
			.is_dollar = 1,
			.string = "?"
		},
		{
			.is_dollar = 1,
			.string = "",
		},
		{
			.is_dollar = 1,
			.string = "foo",
		},
		{
			.is_dollar = 1,
			.string = "kek"
		},
		{
			.is_dollar = 1,
			.string = "",
		},
		{
			.is_dollar = 0,
			.string = "/something",
		},
		{
			.is_dollar = 1,
			.string = "",
		}
	}
};
*/

#endif //MINI_PARSER_H
