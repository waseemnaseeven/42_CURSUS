#include <unistd.h>

void	ft_putchar(char c)
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

int main(void)
{
    int i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        i++;
        write(1, "\n", 1);
    }

}
