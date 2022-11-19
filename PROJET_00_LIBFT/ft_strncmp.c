/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:27:07 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/12 16:54:29 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	char			*x;
	char			*y;

	i = 0;
	x = (char *)s1;
	y = (char *)s2;
	while ((i < n) && (x[i] || y[i]))
	{
		if (x[i] - y[i] != 0)
			return ((unsigned char)x[i] - (unsigned char)y[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char *s1 = "1234";
// 	char *s2 = "12345";

// 	printf("%d\n", ft_strncmp(s1, s2, 3));
// }
