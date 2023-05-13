#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_data
{
	int	fd[2];
	int	saved_stdin;
	int	saved_stdout;
}	t_data;


int	ft_putstr_fd(char *str, char *arg)
{
	for (int i = 0; str[i]; i++)
		write(2, &str[i], 1);
	if (arg)
	{
		for (int i = 0; arg[i]; i++)
			write(2, &arg[i], 1);
	}
	write(2, "\n", 1);
	return (1);
}



int	ft_exec(t_data *data, char *av[], int i, char *env[])
{
	av[i+1] = NULL;
	dup2(data->saved_stdin, STDIN_FILENO);
	close(data->saved_stdin);
	printf("av[0] = %s\n", av[0]);
	execve(av[0], av, env);
	return (ft_putstr_fd("error: fatal", NULL));
}

int main(int ac, char *av[], char *env[])
{
	t_data data;
	(void) ac;
	int	i = 0;
	data.saved_stdin = dup(STDIN_FILENO);
	if (av[i + 1] == NULL)
		return (ft_putstr_fd("end has been reached", NULL));
	else
	{
		av = &av[i + 1];
		i = 0;
		while (av[i])
		{
			printf("i = %d\n", i);
			if (strcmp(av[i], "cd") == 0)
			{
				if (av[i + 1] == NULL)
					ft_putstr_fd("error: cd: bad arguments", NULL);
				else if (chdir(av[i + 1]) != 0)
					ft_putstr_fd("error: cd: cannot change directory to ", av[i + 1]);
			}
			else if (av[i] && (av[i + 1] == NULL || strcmp(av[i + 1], ";") == 0))
			{
				if (fork() == 0)
				{
					if (ft_exec(&data, av, i, env))
						return (1);
				}
				else
				{
					close(data.saved_stdin);
					waitpid(-1, NULL, 0);
					data.saved_stdin = dup(STDIN_FILENO);
				}
			}
			else if ()
			{
				//data.saved_stdout = dup(STDOUT_FILENO);
			}
			i++;
		}
	}
	close(data.saved_stdin);
	return (0);
}
