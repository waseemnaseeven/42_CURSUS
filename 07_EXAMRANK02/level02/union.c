#include <unistd.h>

int	checkdouble2(char *str, char c)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == c)
			return (0);
	}
	return (1);
}

int checkdouble1(char *str, int c, int pos)
{
	for (int i = 0; i < pos; i++)
	{
		if (str[i] == c)
			return (0);
	}
	return (1);
}

void	ft_union(char *str, char *base)
{
	for (int i = 0; str[i]; i++)
	{
		if (checkdouble1(str, str[i], i) == 1)
			write(1, &str[i], 1);
	}
	for (int j = 0; base[j]; j++)
	{
		if (checkdouble2(str, base[j]) == 1)
		{
			if (checkdouble1(base, base[j], j) == 1)
				write(1, &base[j], 1);
		}
	}
}

int main(int ac, char *av[])
{
	if (ac > 2)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
}
