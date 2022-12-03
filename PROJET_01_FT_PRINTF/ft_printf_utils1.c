/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:37:14 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/30 13:50:52 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_putchar(int c, unsigned int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *c, unsigned int *count)
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

void	ft_putnbr(int nb, unsigned int *count)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', count);
		ft_putnbr(2, count);
		ft_putnbr(147483648, count);
	}
	else if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
		ft_putnbr(nb, count);
	}
	else if (nb > 9)
	{
		ft_putnbr((nb / 10), count);
		ft_putnbr((nb % 10), count);
	}
	else
		ft_putchar((nb + 48), count);
}

void	ft_putunbr(unsigned int nb, unsigned int *count)
{
	if (nb > 9)
	{
		ft_putnbr((nb / 10), count);
		ft_putnbr((nb % 10), count);
	}
	else
		ft_putchar((nb + 48), count);
}
