#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	int status;

	while (1)
	{
		printf("simple_shell$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[_strlen(input) - 1] = '\0';

		pid_t pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			if (execlp(input, input, NULL) == -1)
			{
				perror(input);
				exit(1);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				if (WEXITSTATUS(status) != 0)
					printf("Command exited with status %d\n", WEXITSTATUS(status));
			}
		}
		else if (WIFSIGNALED(status))
			printf("Command terminated by signal %d\n", WTERMSIG(status));
	}
	return (0);
}
