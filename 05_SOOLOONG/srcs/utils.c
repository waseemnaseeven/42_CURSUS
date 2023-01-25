/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:23:43 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/17 15:36:12 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puterror1(void)
{
	ft_printf("Error\n");
	ft_printf("Please, provide a map.\n");
	exit(1);
}

void	ft_puterror2(void)
{
	ft_printf("Error\n");
	ft_printf("Please, provide only one map.\n");
	exit(1);
}

void	ft_puterror3(void)
{
	ft_printf("Error\n");
	ft_printf("Please, provide a .ber file.\n");
	exit (1);
}

int	ft_checkfile_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.' && file[i] != '\0')
		i++;
	if (file[i] == '\0')
		return (-1);
	if (file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r'
		&& file[i + 4] == '\0')
		return (0);
	return (-1);
}
