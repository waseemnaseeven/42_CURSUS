/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:21:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/04/21 11:02:47 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct CommonData
{
	int				nb_philo;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				must_eat;
	bool			end;
	long int		time;
	struct s_philo	*philos;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	status;
	pthread_mutex_t	dead;
	pthread_mutex_t	shield;
	pthread_mutex_t	condition;

}	t_data;

typedef struct s_philo
{
	int							to_die;
	int							to_eat;
	int							to_sleep;
	int							must_eat;
	int							n_meals;
	int							i_philo;
	int							left;
	int							right;
	struct timeval				t_meal;
	pthread_t					tid;
	pthread_mutex_t				*lfork;
	pthread_mutex_t				*rfork;
	t_data						*data;

}	t_philo;

typedef struct s_dead
{
	pthread_t			looking;
	t_philo				*philos;
	t_data				*data;

}						t_dead;

/* ********** INIT FUNCTIONS ********** */
int						ft_initialize1(t_data *data, char *av[], int ac);
int						ft_initialize2(t_data *data);
void					init_philo(t_data *data);
int						init_threads1(t_data *data, t_philo *philos);
int						init_threads2(t_data *data, t_philo *philo,
							t_dead *dead);
int						ft_init_mutex(t_data *data);

/* ********** THREADS FUNCTIONS ********** */
void					*ft_routine(void *arg);

/* ********** DEAD FUNCTIONS ********** */
void					*ft_checker(void *arg);
void					ft_mutex_end(t_dead *dead);
int						ft_check_end(t_dead *dead);
int						is_dead(t_philo *philo);

/* ********** STATUS FUNCTIONS ********** */
void					*ft_writing_death(t_philo *philo);
int						ft_writing_status(t_philo *philo, char flag);
void					ft_death(t_philo *philo);

/* ********** TIME FUNCTIONS ********** */
long int				ft_calc_timestamp(struct timeval start);
int						ft_calc_time(struct timeval now);
long int				ft_now(void);
int						msleep(long int duration, t_philo *philo);

/* ********** ERROR FUNCTIONS ********** */
void					msg_error(char *msg);
int						ft_error_arg(t_data *data, char *av[]);
int						ft_error(t_data *data, char *msg, int i, char flag);
int						ft_flag_four(t_data *data, int i, int j);

/* ********** FREE FUNCTIONS ********** */
void					ft_free_philo(t_philo *philo);
void					ft_free_philos(t_data *data);
void					ft_free_data(t_data *data);
void					ft_free_all(t_data *data);

/* ********** UTILS FUNCTIONS ********** */
long					ft_atol(const char *nptr);
void					ft_sign(const char *nptr, int sign, int i);
int						ft_isdigit(const char *nptr);
int						ft_strlen(char *s);

#endif
