#include <unistd.h>

int	checkdouble1(char *str, char c, int pos)
{
	for (int i = 0; i < pos; i++)
	{
		if (str[i] == c)
			return (0);
	}
	return (1);
}

void	ft_inter(char *str, char *base)
{
	for (int i = 0; str[i]; i++)
	{
		for (int j = 0; base[j]; j++)
		{
			if (str[i] == base[j])
			{
				if (checkdouble1(str, str[i], i) == 1)
				{
					write(1, &str[i], 1);
					break ;
				}
			}
		}
	}
}

int main(int ac, char *av[])
{
	if (ac > 2)
		ft_inter(av[1], av[2]);
	write(1, "\n", 1);
}
