/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:18:42 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 12:02:04 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forks(t_philo *philo)
{
	if (philo->i_philo % 2 != 0)
	{
		pthread_mutex_lock(philo->lfork);
		philo->left = 1;
		if (ft_writing_status(philo, 'f') != 0)
			return (-1);
		if (philo->lfork == philo->rfork)
			return (-1);
		pthread_mutex_lock(philo->rfork);
		philo->right = 1;
		if (ft_writing_status(philo, 'f') != 0)
			return (-1);
	}
	else
	{
		pthread_mutex_lock(philo->rfork);
		philo->right = 1;
		if (ft_writing_status(philo, 'f') != 0)
			return (-1);
		pthread_mutex_lock(philo->lfork);
		philo->left = 1;
		if (ft_writing_status(philo, 'f') != 0)
			return (-1);
	}
	return (0);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->shield);
	gettimeofday(&philo->t_meal, NULL);
	pthread_mutex_unlock(&philo->data->shield);
	if (ft_writing_status(philo, 'e') != 0)
		return (1);
	else
	{
		philo->n_meals++;
		pthread_mutex_lock(&philo->data->condition);
		philo->data->must_eat--;
		pthread_mutex_unlock(&philo->data->condition);
		msleep(philo->to_eat, philo);
	}
	philo->left = 0;
	pthread_mutex_unlock(philo->lfork);
	philo->right = 0;
	pthread_mutex_unlock(philo->rfork);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_writing_status(philo, 's') != 0)
		return (-1);
	if (msleep(philo->to_sleep, philo) != 0)
		return (-1);
	if (ft_writing_status(philo, 't') != 0)
		return (-1);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->i_philo % 2)
		msleep(philo->to_eat / 10, philo);
	while (1)
	{
		if (philo->n_meals && philo->data->nb_philo % 2)
			msleep(philo->to_die * 0.50, philo);
		if (ft_forks(philo) != 0)
			break ;
		if (ft_eat(philo) != 0)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
	}
	if (philo->left == 1)
		pthread_mutex_unlock(philo->lfork);
	if (philo->right == 1)
		pthread_mutex_unlock(philo->rfork);
	return (NULL);
}
