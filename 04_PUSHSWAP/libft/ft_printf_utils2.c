/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:59:00 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/12 11:43:35 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert(unsigned int nb, char *base, int len, unsigned int *count)
{
	if (nb >= (unsigned int)len)
	{
		ft_convert(nb / len, base, len, count);
		ft_convert(nb % len, base, len, count);
	}
	else
		ft_putchar(base[nb], count);
}

void	ft_puthex(unsigned int nb, unsigned int *count)
{
	char				*base;
	unsigned int		len;

	base = "0123456789abcdef";
	len = ft_strlen(base);
	ft_convert(nb, base, len, count);
}

void	ft_puthexmaj(unsigned int nb, unsigned int *count)
{
	char				*base;
	unsigned int		len;

	base = "0123456789ABCDEF";
	len = ft_strlen(base);
	ft_convert(nb, base, len, count);
}

void	ft_convertmem(unsigned long long nb, int len, unsigned int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= (unsigned long long)len)
	{
		ft_convertmem(nb / len, len, count);
		ft_convertmem(nb % len, len, count);
	}
	else
		ft_putchar(nb[base], count);
}

void	ft_putmem(void *nb, unsigned int *count)
{
	char					*base;
	unsigned long long		len;
	unsigned long long		nbr;

	if (nb == NULL)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	ft_putstr("0x", count);
	nbr = (unsigned long long) nb;
	base = "0123456789abcdef";
	len = ft_strlen(base);
	ft_convertmem(nbr, len, count);
}
