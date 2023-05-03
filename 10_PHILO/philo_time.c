/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:37:12 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/18 01:14:21 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_now(void)
{
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	return ((t_now.tv_sec * 1000) + (t_now.tv_usec / 1000));
}

int	ft_calc_time(struct timeval start)
{
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

long int	ft_calc_timestamp(struct timeval start)
{
	long int		result;
	struct timeval	now;

	gettimeofday(&now, NULL);
	result = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	result -= (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (result);
}

int	msleep(long int duration, t_philo *philo)
{
	long int	start;
	long int	now;
	long int	end;

	start = ft_now();
	end = start + duration;
	while (1)
	{
		now = ft_now();
		if (now >= end)
			break ;
		usleep(100);
		if (is_dead(philo))
			return (1);
	}
	return (0);
}
