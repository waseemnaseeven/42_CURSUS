#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i])
    {
        res *= 10;
        res += str[i] - '0';
        i++;
    }
    return (res);
}

void ft_putnbr(int nb)
{
    char *base = "0123456789abcdef";
    int len = ft_strlen(base);

    if (nb >= len)
    {
        ft_putnbr(nb / len);
        ft_putnbr(nb % len);
    }
    else
        ft_putchar(base[nb]);
}

int main(int ac, char **av)
{
    if (ac == 2)
        ft_putnbr(ft_atoi(av[1]));
    write(1, "\n", 1);
}