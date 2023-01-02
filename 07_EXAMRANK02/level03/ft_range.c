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
    if (start < end)
    {
        while (i < size)
        {
            tab[i] = start + i;
            i++;
        }
    }
    else if (start > end)
    {
        while (i < size)
        {
            tab[i] = start - i;
            i++;
        }
    }
    return (tab);
}

int main(void)
{
    int start = -1;
    int end = 2;
    int *tab = ft_range(start, end);
    int i = 0;
    int size = (end - start) + 1;
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
}