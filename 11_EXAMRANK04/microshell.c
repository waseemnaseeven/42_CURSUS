#include "microshell.h"

int	ft_putstr_fd(char *str, char *arg)
{
	int i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	if (arg)
	{
		i = 0;
		while (arg[i])
		{
			write(2, &arg[i], 1);
			i++;
		}
	}
	write(2, "\n", 1);
	return (1);
}

int ft_exec(char *av[], int fd, int i, char *env[])
{
	av[i] = NULL;
	dup2(fd, STDIN_FILENO);
	close(fd);
	execve(av[0], av, env);
	return (ft_putstr_fd("error: cannot execute ", av[0]));
}

int main (int ac, char *av[], char *env[])
{
	int fd[2];
	int previous_pipe = dup(STDIN_FILENO);
	int i = 0;
	(void) ac;

	if (av[i] == NULL && av[i + 1] == NULL)
		return (0);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			int j = 0;
			while (av[j])
				j++;
			if (j != 2)
				ft_putstr_fd("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_putstr_fd("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (ft_exec(av, previous_pipe, i, env))
					return (1);
			}
			else
			{
				close(previous_pipe);
				while (waitpid(-1, NULL, 0) != -1)
					;
				previous_pipe = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				close(fd[0]);
				if (ft_exec(av, previous_pipe, i, env))
					return (1);
			}
			else
			{
				close(previous_pipe);
				close(fd[1]);
				previous_pipe = fd[0];
			}
		}
	}
	close(previous_pipe);
	return (0);
}
