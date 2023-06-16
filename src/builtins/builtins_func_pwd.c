#include "../../includes/minishell.h"

//проверить по тесткейсам

void pwd_func(void)
{
    char *pwd;
    char buf[PATH_MAX];

    pwd = getcwd(buf, PATH_MAX);
    if (pwd)
    {
        ft_putstr_fd(pwd, 1);
        write(1, "\n", 1);
    }
}