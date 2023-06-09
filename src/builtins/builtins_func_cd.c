#include "../../includes/minishell.h"



// void cd_func(t_token **token)
// {
//     if (ft_lstsize((t_list *)*token) != 2) {
//         printf("Использование: cd <директория>\n");
//         return ;
//     }

//     if (chdir(token->token->next) != 0) {
//         printf("Ошибка: не удалось изменить текущий каталог\n");
//         return ;
//     }
// }