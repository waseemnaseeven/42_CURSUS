#include <unistd.h>

void	snake_to_camel(char *str)
{
	if (!str)
		return ;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '_')
		{
			i++;
			str[i] -= 32;
		}
		write(1, &str[i], 1);
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write(1, "\n", 1);
}
