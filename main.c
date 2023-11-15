#include "main.h"

/**
* main - main function for the shell
*
* Return: 0 on success
*/
int main(void)
{
	char *cmd = NULL;
	size_t cmd_len = 0;
	ssize_t read;
	char *argv[MAX_NUM_ARGS];

	char *full_path;

	while (1)
	{
		if (checker())
			write(STDOUT_FILENO, PROMPT, my_strlen(PROMPT));

		read = getline(&cmd, &cmd_len, stdin);
		if (read == -1) /* End of file (Ctrl+D) */
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}

		if (cmd[read - 1] == '\n')
			cmd[read - 1] = '\0'; /* Remove newline character */

		if (my_strlen(cmd) == 0)
			continue; /* Empty command, just print prompt again */

		parse_command(cmd, argv);
		handle_exit(argv);
		handle_env(argv);

		full_path = get_full_path(argv);
		if (full_path == NULL)
			continue;

		if (run_command(argv, full_path))
			return (1);

		free(full_path);
	}

	return (0);
}
