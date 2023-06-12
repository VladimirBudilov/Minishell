#include "../../includes/minishell.h"

void to_home(void)
{
    char *home_path;

	home_path = ft_strdup(find_to_element_(g_minishell.env, "HOME"));
	if (home_path == NULL)
	{
		error_message("cd", NO_HOME, 1);
		free(path);
		return ;
	}
	change_dir_to_path(home_path);
	free(home_path);
}


void cd_func(t_token **token)
{
    if (!(*token)->next == NULL)
    {
        to_home();
        return ;
    }
    else if (!(ft_strncmp((*token)->next->data), "-", 1))
    {
       
    }
    else
    {
        
    }
}