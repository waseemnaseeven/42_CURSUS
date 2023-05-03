/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:24:12 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/18 01:55:09 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo(t_philo *philo)
{
	free(philo);
}

void	ft_free_philos(t_data *data)
{
	free(data->philos);
}

void	ft_free_data(t_data *data)
{
	free(data->mutex);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&data->mutex[i]);
	pthread_mutex_destroy(&data->shield);
	pthread_mutex_destroy(&data->condition);
	pthread_mutex_destroy(&data->dead);
	free(data->mutex);
	free(data->philos);
}
