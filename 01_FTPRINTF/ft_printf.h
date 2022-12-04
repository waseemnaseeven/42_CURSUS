/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:33:46 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/01 16:57:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

void	ft_putchar(int c, unsigned int *count);
void	ft_putstr(char *c, unsigned int *count);
void	ft_putnbr(int nb, unsigned int *count);
void	ft_putunbr(unsigned int nb, unsigned int *count);
void	ft_puthex(unsigned int nb, unsigned int *count);
void	ft_puthexmaj(unsigned int nb, unsigned int *count);
void	ft_putmem(void *nb, unsigned int *count);
int		ft_strlen(char *c);
void	ft_flags(const char format, va_list args, unsigned int *count);
int		ft_printf(const char *format, ...);

#endif
