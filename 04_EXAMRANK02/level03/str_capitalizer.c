#include <unistd.h>

char    *lower(char *c)
{
    int i = 0;
    while (c[i])
    {
        if (c[i] >= 'a' && c[i] <= 'z')
            c[i] -= 32;
        i++;
    }
    return (c);
}

char *upper(char *c)
{
    
}

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    
    if (ac == 2)
    {
        while (av[1][i])
        {
            write(1, "A", 1);
            if (av[1][i] == ' ')
                j = 0;
            else if (j == 0)
            {
                if (av[1][i + 1] >= 'a' && av[1][i + 1] <= 'z')
                    av[1][i + 1] -= 32;
                j = 1;
            }
            else
            {
                if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                    av[1][i] += 32;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}