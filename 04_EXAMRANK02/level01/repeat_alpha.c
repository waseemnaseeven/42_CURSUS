#include <unistd.h>

int ft_count(char c)
{
    int count= 0;

	if (c >= 'A' && c <= 'Z')
		count = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		count = c - 'a' + 1;
	else
		count = 1;
	return (count);
}

int main(int ac, char **av)
{
	int repeat = 0;
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			repeat = ft_count(av[1][i]);
			while (repeat--)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}