#include "../../includes/minishell.h"


void	signal_handler(int signal)
{
	err_no = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signal;
}

void signal_handler_sigint(int signal)
{
	(void)signal;
	err_no = 130;
	write(1, "\n", 1);
}

void	signal_hendler_sigquit(int signal)
{
	(void)signal;
	err_no = 131;
	ft_putstr_fd("Quit: 3\n", 2);
}

void define_signals(void)
{
	signal(SIGINT, signal_handler_sigint);
	signal(SIGQUIT, signal_hendler_sigquit);
}