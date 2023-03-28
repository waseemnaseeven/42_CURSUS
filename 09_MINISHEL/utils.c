/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:24:08 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/16 13:56:51 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	print_tab(char *arg)
{
	int	i;

	i = -1;
	if (!arg)
		return ;
	while (arg[++i])
		printf("line[%d] : %s\n", i, arg);
}

void	display(char **args)
{
	int	i;

	i = -1;
	if (!args || !args[0])
		return ;
	while (args[++i])
		ft_printf("arg [%d] : %s\n", i, args[i]);
}

void	display_files(char **args)
{
	int	i;

	i = -1;
	if (!args || !args[0])
		return ;
	while (args[++i])
		ft_printf("file [%d] : %s\n", i, args[i]);
}

void	print_lexer(t_list_tok *lexer)
{
	while (lexer)
	{
		printf("%s : [%d]", lexer->token->value, lexer->token->type);
		lexer = lexer->next;
		printf("\n");
	}
}

void	print_int_array(int *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != 0)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
}
