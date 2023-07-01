#include "../../includes/minishell.h"

void free_tmp(char **tmp)
{
	int i;

	i = 1;
	while(tmp[i])
		free(tmp[i++]);
	free(tmp);
}


void print_command_export(t_hashmap **hashmap_key, t_shell *shell, t_array_list *line)
{
    int i;

    i = 0;
    if (line->size <= 1)
    {
        while(i < shell->env->size)
        {

            ft_putstr_fd("declare -x ", 1);
            ft_putstr_fd(hashmap_key[i]->key, 1);
            if (hashmap_key[i]->value != NULL)
            {
                write(1, "=\"", 2);
                ft_putstr_fd(hashmap_key[i]->value, 1);
                write(1, "\"", 1);
            }
            write(1, "\n", 1);
            i++;
        }
    }
}

int check_key(char *str, t_hashmap **hashmap_key, t_shell *shell)
{
    int i;
	char **tmp;
	char *parse_str;

	i = 0;
	if (ft_strchr(str, '='))
	{
		tmp = ft_split(str, '=');
		parse_str = tmp[0];
		free_tmp(tmp);
	}
	else
		parse_str = ft_strdup(str);

    while(i < shell->env->size)
    {
        if(!ft_strncmp(hashmap_key[i]->key, parse_str, ft_strlen(str))) {
			free(parse_str);
			return 1;
		}
        i++;
    }
	free(parse_str);
    return 0;
}

void save_value_in_key(char *string, t_shell *shell)
{
	char *value;
	char **tmp;
	char *parse_string;

	value = NULL;
	if ((value = ft_strchr(string, '=')))
	{
		value++;
		tmp = ft_split(string, '=');
		parse_string = tmp[0];
		change_value_by_key(shell->env, parse_string, value);
		free_array(tmp);
	}
}

void check_double_arguments(t_hashmap **hashmap_key, t_parser_token **token_key, t_shell *shell, t_array_list *line)
{
    int i;

    i = 2;
    if (line->size > 2)
    {
        while(i < line->size)
        {
            if (token_key[i]->main_type != NEW_SPACE)
			{
				if (!check_key(token_key[i]->content, hashmap_key, shell))
					add_element(shell->env, create_hashmap(token_key[i]->content));
				else
					save_value_in_key(token_key[i]->content, shell);
			}
            i++;
        }
    }
}



void export_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell)
{
	t_parser_token **token_key;

	token_key = (t_parser_token **)line->array;
    print_command_export(hashmap_key, shell, line);
    if(!check_valid_arguments(token_key, shell))
        return ;
    check_double_arguments(hashmap_key, token_key, shell, line);
	err_no = 0;
}
