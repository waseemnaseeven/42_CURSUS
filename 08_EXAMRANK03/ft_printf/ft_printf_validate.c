#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int	ft_strlen(char *base)
{
	int	i = 0;
	while (base[i])
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

void	ft_convert(unsigned int nb, char *base, unsigned int len, unsigned int *count)
{
	if (nb >= len)
	{
		ft_convert((nb / len), base, len, count);
		ft_convert((nb % len), base, len, count);
	}
	else
		ft_putchar(base[nb], count);
}

void	ft_puthex(unsigned int nb, unsigned int *count)
{
	char	*base;
	unsigned int	len;

	base = "0123456789abcdef";
	len = ft_strlen(base);
	ft_convert(nb, base, len, count);
}

void	ft_flags(const char format, va_list args, unsigned int *count)
{
	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'x')
		ft_puthex(va_arg(args, unsigned int), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	unsigned	i;
	unsigned	res;

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
