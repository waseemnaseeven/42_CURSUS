/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:31:43 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 12:02:33 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_writing_status(t_philo *philo, char flag)
{
	pthread_mutex_lock(&philo->data->status);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->data->status);
		return (-1);
	}
	if (flag == 'f')
		printf("%ld %d has taken a fork\n", ft_now() - philo->data->time,
			philo->i_philo + 1);
	if (flag == 'e')
		printf("%ld %d is eating\n", ft_now() - philo->data->time,
			philo->i_philo + 1);
	if (flag == 's')
		printf("%ld %d is sleeping\n", ft_now() - philo->data->time,
			philo->i_philo + 1);
	if (flag == 't')
		printf("%ld %d is thinking\n", ft_now() - philo->data->time,
			philo->i_philo + 1);
	pthread_mutex_unlock(&philo->data->status);
	return (0);
}

void	*ft_writing_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->status);
	printf("%ld %d died\n", ft_now() - philo->data->time,
		philo->i_philo + 1);
	pthread_mutex_unlock(&philo->data->status);
	return (NULL);
}

int	is_dead(t_philo *philo)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&philo->data->dead);
	end = philo->data->end;
	pthread_mutex_unlock(&philo->data->dead);
	if (end > 0)
		return (-1);
	return (0);
}
