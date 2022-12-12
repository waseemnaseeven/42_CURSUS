#include <stdlib.h>
#include <stdio.h>



int check(char c)
{
    if ((c == 0) || (c >= 9 && c <= 13))
        return (1);
    if ((c == 32) || (c == '\t'))
        return (1);
    if (c == '\n')
        return (1);
    return (0);
}

int ft_strlen(char *str)
{
    int i = 0;
    while ((str[i] && (check(str[i]) == 0)))
        i++;
    return (i);
}

int ft_count(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        while (str[i] && check(str[i]) == 1)
            i++;
        if (str[i])
            count++;
        while (str[i] && check(str[i]) == 0)
            i++;
    }
    return (count);
}

char *ft_strdup(char *str)
{
    int i = 0;
    char *word;
    int len = ft_strlen(str);
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (0);
    word[len] = '\0';
    while (i < len)
    {
        word[i] = str[i];
        i++;
    }
    return (word);
}

char **ft_split(char *str)
{
    char **new;
    int i = 0;
    new = (char **)malloc(sizeof(char *) * (ft_count(str) + 1));
    while (*str)
    {
        while (*str && (check(*str) == 1))
            str++;
        if (*str)
        {
            new[i] = ft_strdup(str);
            i++;
        }
        while (*str && (check(*str) == 0))
            str++;
    }
    new[i] = '\0';
    return (new);
}

int main(void)
{
    char **tab;
    int i = 0;
    char *str = "ifoag   gsgjosigs  g sgesg eggs gs gs g     gsgs   g g gr";
    tab = ft_split(str);
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
}