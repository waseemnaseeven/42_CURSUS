/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:36:39 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/03 10:53:46 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nb;
	void	*m;
	char	*v;

	if (!size || !nmemb)
	{
		v = malloc(sizeof(char));
		if (v == NULL)
			return (NULL);
		v[0] = '\0';
		return (v);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	nb = nmemb * size;
	m = malloc(nb);
	if (!m)
		return (NULL);
	ft_bzero(m, nb);
	return (m);
}
