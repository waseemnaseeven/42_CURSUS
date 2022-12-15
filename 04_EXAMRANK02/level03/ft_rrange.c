#include <stdlib.h>
#include <stdio.h>

int negative(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

int *ft_range(int start, int end)
{
    int *tab;
    int size = negative(end - start) + 1;
    int i = 0;

    tab = malloc(sizeof(int) * (size + 1));
    if (!tab)
        return (NULL);
    if (end < start)
    {
        while (i < size)
        {
            tab[i] = end + i;
            i++;
        }
    }
    else if (end > start)
    {
        while (i < size)
        {
            tab[i] = end - i;
            i++;
        }
    }
    return (tab);
}

int main(void)
{
    int start = -2147483648;
    int end = -2147483638;
    int *tab = ft_range(start, end);
    int i = 0;
    int size = negative(end - start) + 1;
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
}