#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("\nReceived SIGINT (Ctrl+C)\n");
        exit(0);
    } else if (signal == SIG_IGN) {
        printf("\nReceived SIGTSTP (Ctrl+D)\n");
        // Действия при получении сигнала Ctrl+D (EOF)
    } else if (signal == SIGQUIT) {
        printf("\nReceived SIGQUIT (Ctrl+\\)\n");
        // Действия при получении сигнала Ctrl+\
    
	}
}

void shell() {
    // Установка обработчиков сигналов
    
    while(1)
    {
        signal(SIGINT, handle_signal);
        signal(SIGTERM, SIG_IGN);
        signal(SIGQUIT, handle_signal);
    }
}

int main() {
    shell();
    
    return 0;
    
}