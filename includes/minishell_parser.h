//
// Created by Vladimir Budilov on 6/10/23.
//

#ifndef MINI_PARSER_H
#define MINI_PARSER_H

#include "minishell_structs.h"

enum token_type {
	END,
	STRING,
	WHITE_SPACE,
	LESS_THAN_LESS_THAN,
	LESS_THAN,
	DOLLAR, // Content.
	GREATER_THAN,
	GREATER_THAN_GREATER_THAN,
	BARE_WORD,
	SINGLE_QUOTES,
	DOUBLE_QUOTES,
};

struct token {
	enum token_type type;
	void *content;
};

struct tokenizer_output {
	char *string;
	struct token token;
};

#endif //MINI_PARSER_H
