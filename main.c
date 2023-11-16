#include "main.h"

/**
* main - main
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
		if (read == -1)
		{
			free(cmd);
			write(0, "\n", 1);
			return (0);
		}
		if (cmd[read - 1] == '\n')
			cmd[read - 1] = '\0';

		if (my_strlen(cmd) == 0)
			continue;

		parse_command(cmd, argv);
		handle_exit(cmd, argv);
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
