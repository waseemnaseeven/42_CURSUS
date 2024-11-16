/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:08:46 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 12:12:29 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_current(t_dead *dead, long int current, int i)
{
	pthread_mutex_lock(&dead->data->shield);
	current = ft_calc_timestamp(dead->data->philos[i].t_meal);
	pthread_mutex_unlock(&dead->data->shield);
	return (current);
}

int	ft_check_end(t_dead *dead)
{
	pthread_mutex_lock(&dead->data->condition);
	if (dead->data->must_eat == 0)
	{
		pthread_mutex_lock(&dead->data->dead);
		dead->data->end = 1;
		pthread_mutex_unlock(&dead->data->dead);
		pthread_mutex_unlock(&dead->data->condition);
		return (-1);
	}
	pthread_mutex_unlock(&dead->data->condition);
	return (0);
}

void	*ft_philo_one(t_dead *dead)
{
	if (ft_writing_status(dead->philos, 'f') != 0)
		return (NULL);
	pthread_mutex_lock(&dead->data->dead);
	dead->data->end = 1;
	pthread_mutex_unlock(&dead->data->dead);
	dead->data->time = ft_now() - dead->data->to_die;
	return (ft_writing_death(dead->philos));
	if (ft_check_end(dead) != 0)
		return (NULL);
}

void	ft_mutex_end(t_dead *dead)
{
	pthread_mutex_lock(&dead->data->dead);
	dead->data->end = 1;
	pthread_mutex_unlock(&dead->data->dead);
}

void	*ft_checker(void *arg)
{
	t_dead		*dead;
	int			i;
	long int	current;

	dead = (t_dead *)arg;
	current = 0;
	if (dead->data->nb_philo == 1)
		if (ft_philo_one(dead) == NULL)
			return (NULL);
	while (1)
	{
		i = -1;
		while (++i < dead->data->nb_philo)
		{
			current = ft_current(dead, current, i);
			if (current > dead->data->to_die)
			{
				ft_mutex_end(dead);
				return (ft_writing_death(dead->philos));
			}
			if (ft_check_end(dead) != 0)
				return (NULL);
		}
	}
	return (NULL);
}
