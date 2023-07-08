#include<stddef.h>
#include<readline/readline.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
#include<stdlib.h>
#include<fcntl.h>
void	execute_heredoc(int i, char *delimiter)
{
	char			*input;

	input = NULL;
	while (1)
	{
		input = readline("> ");
		if (strcmp(input, delimiter) == 0)
			break ;
		write(i, input, strlen(input));
		write(i, "\n", 1);
		free(input);
	}
}
int main() {
	int fds[2];
	assert(pipe(fds) >= 0);

	switch (fork()) {
	case 0: // Child. cat << a
		{ // Heredoc.
			int fd = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC);
			assert(fd >= 0);
			execute_heredoc(fd, "a");
			assert(close(fd) >= 0);

			fd = open("heredoc", O_RDONLY);
			dup2(fd, STDIN_FILENO);
		}

		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);

		assert(execlp("cat", "", "-e", 0) >= 0);
	break;
	case -1: assert(0);
	break;
	} // Father.

	switch (fork()) {
	case 0: // Child. tr [:lower:] [:upper:]
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		assert(execlp("tr", "", "[:lower:]", "[:upper:]", 0) >= 0);
	break;
	case -1: assert(0);
	break;
	} // Father.

	close(fds[0]);
	close(fds[1]);

	while (wait(&(int){0}) > 0)
		;
}
