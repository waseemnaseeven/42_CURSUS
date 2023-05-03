/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:21:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 12:04:15 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initialize1(t_data *data, char *av[], int ac)
{
	data->nb_philo = ft_atol(av[1]);
	if (data->nb_philo <= 0 || data->nb_philo > 200)
		return (-1);
	data->to_die = ft_atol(av[2]);
	if (data->to_die <= 0 || data->to_die > 2147483647)
		return (-1);
	data->to_eat = ft_atol(av[3]);
	if (data->to_eat <= 0 || data->to_eat > 2147483647)
		return (-1);
	data->to_sleep = ft_atol(av[4]);
	if (data->to_sleep <= 0 || data->to_sleep > 2147483647)
		return (-1);
	if (ac == 6)
	{
		data->must_eat = ft_atol(av[5]) * data->nb_philo;
		if (data->must_eat < 0)
			return (-1);
	}
	else
		data->must_eat = -1;
	if (ft_initialize2(data) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac > 6 || ac < 5)
	{
		msg_error("Arguments required");
		return (1);
	}
	memset(&data, 0, sizeof(t_data));
	if (ft_initialize1(&data, av, ac) != 0)
	{
		if (ft_error_arg(&data, av) != 0)
			return (-1);
		return (2);
	}
	ft_free_all(&data);
	return (0);
}
