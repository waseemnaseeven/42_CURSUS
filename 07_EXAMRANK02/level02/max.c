#include <stdio.h>

int max(int *tab, unsigned int len)
{
    unsigned int i = 0;
    int res = 0;

    if (!tab)
        return (0);
    while (i < len)
    {
        if (res < tab[i])
            res = tab[i];
        i++;
    }
    return (res);
}

// int main(void)
// {
//     int tab[9] = {5,16,3,4, 44,20,22,22,23};
//     printf("%d\n", max(tab, 9));
// }