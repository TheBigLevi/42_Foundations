#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

//#include <sys/types.h>
//#include <sys/file.h>
//#include <sys/stat.h>
//#include <sys/errno.h>

void	minishell_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	line = readline("Command: ");
	add_history(line);
	//args = ft_split();
	status = 1;
	free(line);
	free(args);
	// while (status)
	// {
	// 	line = readline("Command: ");
	// 	add_history(line);
	// 	status = 1;
	// }
}

int main(void)
{
	minishell_loop();
	return (1);
}