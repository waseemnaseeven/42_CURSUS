/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:33:58 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/03 12:05:38 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flags(const char format, va_list args, unsigned int *count)
{
	if (format == 's')
		ft_putstrprintf(va_arg(args, char *), count);
	else if (format == 'c')
		ft_putcharprintf(va_arg(args, int), count);
	else if ((format == 'd' || format == 'i'))
		ft_putnbrprintf(va_arg(args, int), count);
	else if (format == 'u')
		ft_putunbrprintf(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_puthex(va_arg(args, unsigned int), count);
	else if (format == 'X')
		ft_puthexmaj(va_arg(args, unsigned int), count);
	else if (format == 'p')
		ft_putmem(va_arg(args, void *), count);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	res;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				res += write(1, &format[i], 1);
			else
				ft_flags(format[i + 1], args, &res);
			i++;
		}
		else
			res += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (res);
}
