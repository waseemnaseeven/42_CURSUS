/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:23:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/07 18:24:33 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
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
