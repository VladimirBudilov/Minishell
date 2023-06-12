#include "../../includes/minishell.h"


void add_argument(char *s)
{
	add_element()
}

char *concatenate(char *s1, char *s2)
{
	int len = ft_strlen(s1) + strlen(s2) + 1;
	char *res = malloc(len);
	*res = 0;
	strcat(res, s1);
	strcat(res + strlen(s1), s2);
	return res;
}

// struct state {
// 	variables
// }

char **parse(/* struct state *s, */ t_shell *shell)
{
	int i = 0;

	while ((t_token *)shell->tokens_array->array[i] != END)
	{
		struct token t = *shell;

		switch (t.type)
		{
			// case DOLLAR:
			case STRING:
			{
				// parse_strings
				char *final_string = strdup("");
				while (shell->type == STRING)
				{ // May be wrong because of DOLLAR.
					char *new = concatenate(final_string, shell->content);
					free(final_string);
					final_string = new;
					shell++;
				}
				add_argument(final_string);
			}
				break;
			case WHITE_SPACE:
				// Skip.
				shell++;
				break;
			default:
				assert(0);
		}
	}

	return arguments;
}

