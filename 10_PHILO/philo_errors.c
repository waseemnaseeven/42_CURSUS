/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:19:56 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 12:15:02 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg_error(char *msg)
{
	printf("%s\n", msg);
}

int	ft_error_arg(t_data *data, char *av[])
{
	(void) av;
	if (data->nb_philo <= 0)
	{
		msg_error("Need at least one philosopher");
		return (-1);
	}
	if (data->nb_philo > 200)
	{
		msg_error("Too much philosophers");
		return (-1);
	}
	else
	{
		msg_error("Error Arguments");
		return (-1);
	}
	return (0);
}

int	ft_flag_four(t_data *data, int i, int j)
{
	while (++j < i)
		pthread_detach(data->philos[i].tid);
	free(data->philos);
	return (-1);
}

int	ft_error(t_data *data, char *msg, int i, char flag)
{
	int	j;

	j = -1;
	printf("Failed to %s\n", msg);
	if (flag == 4)
		return (ft_flag_four(data, i, j));
	if (i == 42)
		i = data->nb_philo;
	while (++j < i)
		pthread_mutex_destroy(&data->mutex[i]);
	if (flag > 0)
		pthread_mutex_destroy(&data->status);
	else if (flag > 1)
		pthread_mutex_destroy(&data->shield);
	else if (flag > 4)
		pthread_mutex_destroy(&data->condition);
	else if (flag > 5)
		pthread_mutex_destroy(&data->dead);
	else if (flag > 6)
		free(data->philos);
	return (0);
}
