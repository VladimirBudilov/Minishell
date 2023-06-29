#include "../../includes/minishell.h"

int	get_array_size(char **string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_str_to_lower(char *content)
{
	char	*str;
	int		i;

	str = ft_strdup(content);
	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}