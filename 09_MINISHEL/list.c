/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:10:03 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:07:31 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_list_tok	*ft_token_list_new(t_token *token)
{
	t_list_tok	*m;

	m = malloc(sizeof(t_list_tok));
	if (!m)
		return (NULL);
	m->token = token;
	m->next = NULL;
	m->previous = NULL;
	return (m);
}

void	ft_token_list_add_back(t_list_tok **lst, t_list_tok *new)
{
	t_list_tok	*last;

	last = *lst;
	if (*lst != NULL)
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->previous = last;
	}
	else
	{
		new->previous = NULL;
		*lst = new;
	}
}	

void	del(t_token *token)
{
	if (!token)
		return ;
	free(token->value);
	token->value = NULL;
	free(token);
	token = NULL;
}

void	ft_lst_token_delone(t_list_tok *lst, void (*del)(t_token *token))
{
	if (!lst)
		return ;
	else
	{
		del(lst->token);
		free(lst);
	}
}

void	ft_lst_token_clear(t_list_tok **lst, void (*del)(t_token *token))
{
	t_list_tok	*tmp;

	tmp = *lst;
	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lst_token_delone(*lst, del);
		*lst = tmp;
	}
}
