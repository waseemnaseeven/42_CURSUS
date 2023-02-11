/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:37:14 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/03 12:03:24 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenprintf(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_putcharprintf(int c, unsigned int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstrprintf(char *c, unsigned int *count)
{
	int	i;

	i = 0;
	if (!c)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		(*count)++;
		i++;
	}
}

void	ft_putnbrprintf(int nb, unsigned int *count)
{
	if (nb == -2147483648)
	{
		ft_putcharprintf('-', count);
		ft_putnbrprintf(2, count);
		ft_putnbrprintf(147483648, count);
	}
	else if (nb < 0)
	{
		ft_putcharprintf('-', count);
		nb = -nb;
		ft_putnbrprintf(nb, count);
	}
	else if (nb > 9)
	{
		ft_putnbrprintf((nb / 10), count);
		ft_putnbrprintf((nb % 10), count);
	}
	else
		ft_putcharprintf((nb + 48), count);
}

void	ft_putunbrprintf(unsigned int nb, unsigned int *count)
{
	if (nb > 9)
	{
		ft_putunbrprintf((nb / 10), count);
		ft_putunbrprintf((nb % 10), count);
	}
	else
		ft_putcharprintf((nb + 48), count);
}
