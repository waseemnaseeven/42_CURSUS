#include <stdlib.h>
#include <stdio.h>

static int  ft_count(int n)
{
    int len = 0;

    if (n == 0)
        return (1);
    if (n < 0)
    {
        len++;
        n = (unsigned int) n * -1;
    }
    while ((unsigned int) n > 0)
    {
        len++;
        n = (unsigned int) n / 10;
    }
    return (len);
}

char *ft_itoa(int nbr)
{
    char *str;
    int len = ft_count(nbr);

    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    len--;
    if (nbr == 0)
        str[0] = '0';
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = nbr * -1;
    }
    while ((unsigned int ) nbr > 0)
    {
        str[len] = (unsigned int) nbr % 10 + '0';
        nbr = (unsigned int) nbr / 10;
        len--;
    }
    return (str);
}

int main(void)
{
    printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-21474));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(0));
	printf("%p\n", NULL);

}