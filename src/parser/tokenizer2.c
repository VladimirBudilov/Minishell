// #include "../../includes/minishell.h"

// int is_breaking_character(char c)
// {
// 	char breaking_characters[] = "'\"<>|$ \n\t"; // & if bonus.

// 	int size = sizeof breaking_characters / sizeof *breaking_characters - 1;
// 	for (int i = 0; i < size; i++)
// 	{
// 		if (c == breaking_characters[i])
// 			return 1;
// 	}
// 	return 0;
// }

// struct tokenizer_output tokenize_white_space(char *input, int index)
// {
// 	t_tokenizer_output po;
// 	int i;

// 	i = start;
// 	while (input[i] && input[i] == ' ')
//     {
//         po.token.content[i] = input[i];
// 		i++;
//     }
// 	po.token.type = WHITE_SPACE;
// 	return po;
// }



// struct tokenizer_output tokenize_bare_word(char *input, int i)
// {
// 	t_tokenizer_output po;
// 	t_token *template_token;
//     char *tmp;
// 	if (is_breaking_character(*input))
// 		bug("Expected a bare word, but found a breaking character.");

// 	while (input[i] && !is_breaking_character(input[i]))
//     {
//         tmp[i] = input[i];
// 		i++;
//     }
// 	t = malloc(sizeof(t_token*));
	
//     po.token = *temlate_token;
// 	template_token->type = STRING;
// 	template_token->content = ft_strdup(tmp);
	
// 	return po;
// }



// void tokenize(t_shell *shell)
// {
//     char *input = shell->input;

//     int i = 0;
//     int start = 0;

//     while(input[i])
//     {
//         if (input[i] == ' ')
//         {
//             add_token(shell, (tokenize_white_space(input, i)));
//             i = start;
//         }
//         else if (input[i] == '\'')
//         {

//         }
//         else if (input[i] == '\"')
//         {

//         }
//         else if (input[i] == '<')
//         {

//         }
//         else if (*input == '>')
//         {

//         }
//         else if (*input == '|')
//         {

//         }
//         else if (ft_isascii(*input) && !is_breaking_character(*input))
//         {
//             add_token(shell, (tokenize_bare_word(input, i)));
//         }
//         else
//             break;
//         i++;
//     }

// }