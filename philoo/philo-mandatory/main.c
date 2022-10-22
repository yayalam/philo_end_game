/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <ylambark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:28:21 by ylambark          #+#    #+#             */
/*   Updated: 2022/10/21 20:36:42 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*executing(void *id_philo)
{
	t_philo_id	*philo;

	philo = (t_philo_id *)id_philo;
	if (philo->id % 2 == 0)
		usleep(10);
	philo->time = timer();
	while (1)
	{
		pthread_mutex_lock(&philo->fork[philo->id - 1]);
		ft_print(time_now(philo), philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork[philo->id % philo->philoo->n_philo]);
		ft_print(time_now(philo), philo, "has taken a fork");
		ft_print(time_now(philo), philo, "is eating");
		philo->nbr_eat++;
		if (philo->nbr_eat == philo->philoo->must_eat)
			philo->philoo->globale_eat++;
		philo->time = timer();
		usleep(philo->philoo->time_eat * 1000 - 500);
		pthread_mutex_unlock(&philo->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->fork[philo->id % philo->philoo->n_philo]);
		ft_print(time_now(philo), philo, "is sleeping");
		usleep(philo->philoo->time_sleep * 1000 - 500);
		ft_print(time_now(philo), philo, "is thinking");
	}
	return (0);
}

void	check_dead(t_philo *philo, t_philo_id *param, pthread_mutex_t *print)
{
	int	i;

	i = 0;
	while (1)
	{
		if (param[i].philoo->globale_eat == param[i].philoo->n_philo)
		{
			destroy_mutex(param);
			free_parram(philo, param->fork, param, print);
			return ;
		}
		if (timer() - param[i].time
			>= (unsigned long)philo->time_die)
		{
			usleep(100);
			pthread_mutex_lock(print);
			printf("%lums	 %d died\n", time_now(param), param[i].id);
			destroy_mutex(param);
			free_parram(philo, param->fork, param, print);
			return ;
		}
		i = (i + 1) % philo->n_philo;
		usleep(500);
	}
}

int	main_help(t_philo *philo, t_philo_id *philo_id, pthread_mutex_t *print)
{
	pthread_t	*th;
	int			i;

	th = (pthread_t *)malloc(sizeof(pthread_t) * philo->n_philo);
	i = -1;
	while (++i < philo->n_philo)
	{
		pthread_create(&th[i], NULL, executing, philo_id + i);
		usleep(100);
	}
	check_dead(philo, philo_id, print);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_philo_id		*philo_id;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;

	fork = NULL;
	if (not_num(av) != 0 || error(ac) == 1)
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	if (init(philo, av))
		return (free_parram(philo, fork, 0, 0));
	print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!print)
		return (free_parram(philo, fork, 0, print));
	if (pthread_mutex_init(print, NULL))
		return (free_parram(philo, fork, 0, print));
	philo_id = (t_philo_id *)malloc(sizeof(t_philo_id) * philo->n_philo);
	if (!philo_id)
		return (free_parram(philo, fork, philo_id, print));
	philo_id = init_philosophers (philo, philo_id, fork, print);
	if (!philo_id)
		return (free_parram(philo, fork, philo_id, print));
	main_help(philo, philo_id, print);
}
