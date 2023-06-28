#include "../../includes/minishell.h"

void error(char *message)
{
    fprintf(stderr, "Error. %s\n", message);
}
