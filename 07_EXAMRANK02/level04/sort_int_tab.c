void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    unsigned int j;
    int swap;

    if (tab == 0)
        return (0);

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                swap = tab[i];
                tab[i] = tab[j];
                tab[j] = swap;
            }
            j++;
        }
        i++;
    }
}