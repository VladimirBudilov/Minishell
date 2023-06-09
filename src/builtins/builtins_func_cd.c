#include "../../includes/minishell.h"



void cd_func(t_token **token)
{
    // printf("%s\n", (*token)->next->data);
    if (((*token)->next != NULL)) {
        printf("Использование: cd <директория>\n");
        return ;
    }

    // if (chdir(*(token)->next->data) != 0) {
    //     printf("Ошибка: не удалось изменить текущий каталог\n");
    //     return ;
    // }
}