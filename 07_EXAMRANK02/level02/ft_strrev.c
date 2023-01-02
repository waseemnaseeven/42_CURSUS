#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strrev(char *str)
{
    int i = 0;
    int len = ft_strlen(str);
    len--;
    char a;
    char b;

    if (!str)
        return (0); 

    while (i < len / 2)
    {
        a = str[i];
        b = str[len -i];
        str[len - i] = a;
        str[i] = b;
        i++;
    }
    return (str);
}

int main (void)
{
    char str[] = "Hello World!";
    printf("%s", ft_strrev(str));
}