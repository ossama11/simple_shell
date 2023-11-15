#include "main.h"


/**
* main - main function for the shell
*
* Return: 0 on success
*/

int main(void)
{
	char cmd[MAX_CMD_LEN];

	char *argv[MAX_NUM_ARGS];

	char *full_path;

	while (1)
	{
		if (checker())
			printf(PROMPT);
		if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)  /* End of file (Ctrl+D) */
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		cmd[strlen(cmd) - 1] = '\0';  /* Remove newline character */
		if (strlen(cmd) == 0)
			continue;  /* Empty command, just print prompt again */

		parse_command(cmd, argv);
		handle_exit(argv);
		full_path = get_full_path(argv);
		if (full_path == NULL)
			continue;


		if (run_command(argv, full_path))
			return (1);

		free(full_path);
	}
	return (0);
}
