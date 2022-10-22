/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <ylambark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:28:27 by ylambark          #+#    #+#             */
/*   Updated: 2022/10/21 20:29:22 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include<unistd.h>
# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				globale_eat;
	unsigned long	tm;
}t_philo;

typedef struct s_philo_id
{
	int				id;
	int				nbr_eat;
	unsigned long	time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
	t_philo			*philoo;
}t_philo_id;

int				main(int ac, char **av);
int				ft_atoi(char *str);
int				init(t_philo *philo, char **av);
int				error(int ac);
unsigned long	timer(void);
t_philo_id		*init_philosophers(t_philo *nb, t_philo_id *param_philo, \
		pthread_mutex_t *fork, pthread_mutex_t *print);
unsigned long	time_now(t_philo_id *philo);
void			*executing(void *id_philo);
void			ft_print(unsigned long time, t_philo_id *philo, char *action);
int				not_num(char **av);
void			check_dead(t_philo *philo, t_philo_id *param, \
		pthread_mutex_t *print);
void			destroy_mutex(t_philo_id *philo);
int				free_parram(t_philo *philo, pthread_mutex_t *fork, \
		t_philo_id *id_philo, pthread_mutex_t *print);

#endif