#include "../../includes/minishell.h"

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
