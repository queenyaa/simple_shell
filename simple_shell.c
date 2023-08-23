#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * r_shell - entry point
 * Return: 0
 */
int r_shell(void)
{
	char intk[MAX_INPUT_SIZE];
	pid_t pid;
	int status;

	while (1)
	{
		printf("simple_shell$ ");
		if (fgets(intk, sizeof(intk), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		intk[_strlen(intk) - 1] = '\0';

		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			if (execlp(intk, intk, NULL) == -1)
			{
				perror(intk);
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
			else if (WIFSIGNALED(status))
			printf("Command terminated by signal %d\n", WTERMSIG(status));
		}
	}
	return (0);
}
