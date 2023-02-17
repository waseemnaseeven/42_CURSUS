#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
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


int main(int ac, char **av)
{
    (void) av;
    ft_putnbr(ac - 1);
    write(1, "\n", 1);
}
