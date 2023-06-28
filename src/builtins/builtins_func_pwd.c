#include "../../includes/minishell.h"

void pwd_func(void)
{
    char *pwd;
    char buf[PATH_MAX];

	err_no = 0;
    pwd = getcwd(buf, PATH_MAX);
    if (pwd)
    {
        ft_putstr_fd(pwd, 1);
        write(1, "\n", 1);
    }
}