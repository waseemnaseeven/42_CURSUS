#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putsum(int nb)
{
    char digit;

    if (nb > 9)
        ft_putsum(nb / 10);
    digit = (nb % 10) + '0';
    ft_putchar(digit);
}

int main(int ac, char **av)
{
    (void) av;
    ft_putsum(ac - 1);
    write(1, "\n", 1);
}