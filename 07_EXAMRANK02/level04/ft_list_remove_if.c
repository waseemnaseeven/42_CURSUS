#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || data_ref == NULL || *begin_list)
        return ;
    
    t_list *var = *begin_list;

    if (cmp(var->data, data_ref) == 0)
    {
        *begin_list = var->next; // begin_list = element suivant
        free(var);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    var = *begin_list;
    ft_list_remove_if(&var->next, data_ref, cmp);
}

