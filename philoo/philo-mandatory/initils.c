/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <ylambark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:10:44 by ylambark          #+#    #+#             */
/*   Updated: 2022/10/21 20:33:16 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init(t_philo *philo, char **av)
{
	philo->tm = timer();
	philo->n_philo = ft_atoi(av[1]);
	philo->time_die = ft_atoi(av[2]);
	philo->time_eat = ft_atoi(av[3]);
	philo->time_sleep = ft_atoi(av[4]);
	philo->globale_eat = 0;
	if (av[5])
		philo->must_eat = ft_atoi(av[5]);
	else
		philo->must_eat = -1;
	if (philo->n_philo == 0 || philo->time_die == 0 || philo->time_eat == 0 \
		|| philo->time_sleep == 0 || philo->must_eat == 0)
		return (1);
	if (philo->n_philo < 0 || philo->time_die < 0 || philo->time_eat < 0 \
		|| philo->time_sleep < 0 || (philo->must_eat < 0 && av[5]))
		return (printf("Error\n"));
	return (0);
}

pthread_mutex_t	*init_mutex(t_philo *nb, pthread_mutex_t *fork)
{
	int	i;

	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb->n_philo);
	if (!fork)
		return (0);
	i = 0;
	while (i < nb->n_philo)
	{
		if (pthread_mutex_init(&fork[i], 0))
			return (0);
		i++;
	}
	return (fork);
}

t_philo_id	*init_philosophers(t_philo *nb, t_philo_id *param_philo,
						pthread_mutex_t *fork, pthread_mutex_t *print)
{
	int	i;

	fork = init_mutex(nb, fork);
	if (!fork)
		return (0);
	i = -1;
	while (++i < nb->n_philo)
	{
		param_philo[i].id = i + 1;
		param_philo[i].nbr_eat = 0;
		param_philo[i].philoo = nb;
		param_philo[i].print = print;
		param_philo[i].fork = fork;
	}
	return (param_philo);
}

int	free_parram(t_philo *philo, pthread_mutex_t *fork, \
		t_philo_id *id_philo, pthread_mutex_t *print)
{
	if (philo)
		free(philo);
	if (fork)
		free(fork);
	if (print)
		free(print);
	if (id_philo)
		free(id_philo);
	return (1);
}
