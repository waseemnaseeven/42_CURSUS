/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:20:24 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 11:45:52 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initialize2(t_data *data)
{
	if (ft_init_mutex(data) != 0)
		return (-1);
	data->philos = malloc(sizeof(t_philo) * (data->nb_philo));
	if (!data->philos)
		return (-1);
	memset(data->philos, 0, sizeof(t_philo) * data->nb_philo);
	data->time = ft_now();
	data->end = 0;
	init_philo(data);
	if (init_threads1(data, data->philos) != 0)
		return (-1);
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	if (data->nb_philo > 0 && data->nb_philo <= 200)
	{
		data->mutex = malloc(sizeof(pthread_mutex_t)
				* data->nb_philo);
		if (!data->mutex)
			return (-1);
		i = -1;
		while (++i < data->nb_philo)
			if (pthread_mutex_init(&data->mutex[i], NULL))
				return (ft_error(data, "init mutex", i, 1));
		if (pthread_mutex_init(&data->shield, NULL))
			return (ft_error(data, "init shield", 42, 1));
		if (pthread_mutex_init(&data->condition, NULL))
			return (ft_error(data, "init condition", 42, 1));
		if (pthread_mutex_init(&data->status, NULL))
			return (ft_error(data, "init status", 42, 1));
		if (pthread_mutex_init(&data->dead, NULL))
			return (-1);
	}
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philos[i].data = data;
		data->philos[i].to_die = data->to_die;
		data->philos[i].to_eat = data->to_eat;
		data->philos[i].to_sleep = data->to_sleep;
		data->philos[i].must_eat = data->must_eat;
		data->philos[i].lfork = &data->mutex[i];
		data->philos[i].i_philo = i;
		if (i == data->nb_philo - 1)
			data->philos[i].rfork = &data->mutex[0];
		else
			data->philos[i].rfork = &data->mutex[i + 1];
	}
}

int	init_threads1(t_data *data, t_philo *philos)
{
	int		i;
	t_dead	dead;

	memset(&dead, 0, sizeof(t_dead));
	dead.data = data;
	dead.philos = philos;
	i = -1;
	while (++i < data->nb_philo)
		if (gettimeofday(&data->philos[i].t_meal, NULL) == -1)
			return (ft_error(data, "init", -1, 3));
	if (pthread_create(&dead.looking, NULL, &ft_checker, &dead))
		return (ft_error(data, "create dead thread", 42, 2));
	i = -1;
	while (++i < data->nb_philo)
		if (pthread_create(&philos[i].tid, NULL, &ft_routine, &philos[i]))
			return (ft_error(data, "create philo thread", 42, 3));
	if (init_threads2(data, philos, &dead) != 0)
		return (-1);
	return (0);
}

int	init_threads2(t_data *data, t_philo *philo, t_dead *dead)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		if (pthread_join(philo[i].tid, NULL))
			return (ft_error(data, "join thread", 0, 4));
	if (pthread_join(dead->looking, NULL))
		return (ft_error(data, "join thread", 0, 4));
	return (0);
}
