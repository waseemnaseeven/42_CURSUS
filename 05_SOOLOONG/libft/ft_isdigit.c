/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:38:41 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/07 18:38:54 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

/*
int main(void)
{
	char var = '@';
	char lotre = '2';
	printf("%d\n", ft_isalnum(var));
	printf("%d\n", isalnum(lotre));

}
*/
