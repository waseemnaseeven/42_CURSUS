/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:39:54 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 12:01:45 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

void	ft_sign(const char *nptr, int sign, int i)
{
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
}

long	ft_atol(const char *nptr)
{
	long			i;
	long			res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!nptr)
		return (-1);
	if (ft_isdigit(nptr) == -1)
		return (-1);
	ft_sign(nptr, sign, i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (res > 2147483647)
		return (-1);
	return (res * sign);
}
