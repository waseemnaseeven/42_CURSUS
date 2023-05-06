#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct s_data
{
	int	fd[2];
	pid_t pid[4096];
}	t_data;

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int len = ft_strlen (src);
	char *ret = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		src[i] = ret[i];
	ret[len] = '\0';
	return (ret);
}

int main(int ac, char *av[], char *envp[])
{
	(void) av;
	(void) ac;
	(void) envp;
	t_data data;
}
