
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	whitespaces_sign_check(char *str, int *ptr_i)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

int	check_nbr_base(char *base, char c, int *ptr_k)
{
	int	k;

	k = 0;
	while (base[k])
	{
		if (base[k] == c)
		{
			*ptr_k = k;
			return (1);
		}
		k++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	lenbase;
	int	k;

	i = 0;
	result = 0;
	sign = whitespaces_sign_check(str, &i);
	lenbase = ft_strlen(base);
	k = 0;
    while (check_nbr_base(base, str[i], &k) == 1)
		{
			result *= lenbase;
			result += k;
			i++;
		}
	return (result * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	main(int argc, char **argv)
{
	char *str;
	char *base;

	if (argc > 2)
	{
		str = argv[1];
		base = argv[2];
		printf("%d", ft_atoi_base(str, base));
	}
	return (0);
}