/*

#include "../../includes/minishell.h"

// struct state {
// 	variables
// }

char **parse( struct state *s, t_shell *shell)
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
*/

