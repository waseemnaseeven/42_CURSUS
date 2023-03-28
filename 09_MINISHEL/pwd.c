/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:06:26 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/16 13:49:20 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_pwd(char *arg)
{
	char	str[4096];

	if (!arg)
	{
		if (getcwd(str, sizeof(str)) == NULL)
			return (1);
		printf("%s\n", getcwd(str, sizeof(str)));
		return (0);
	}
	else
	{
		if (getcwd(str, sizeof(str)) == NULL)
			return (1);
		printf("%s\n", getcwd(str, sizeof(str)));
		return (0);
	}
}
