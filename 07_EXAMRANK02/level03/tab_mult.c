#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

void    ft_putnbr(int n)
{
	//if (n == -2147483648)
	//{
	//	ft_putchar('-');
	//	ft_putnbr(2);
	//	ft_putnbr(147483648);
	//}
	//if (n == 0)
	//{
	//	ft_putchar('-');
	//	n = n * -1;
	//}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int i = 1;
		int nbr = ft_atoi(av[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
