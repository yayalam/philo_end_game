/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <ylambark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:01:39 by ylambark          #+#    #+#             */
/*   Updated: 2022/10/21 20:32:34 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *str)
{
	int		i;
	long	r;
	int		k;

	i = 0;
	r = 0;
	k = 1;
	if (!*str)
		return (-1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	return (r * k);
}

unsigned long	timer(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_print(unsigned long time, t_philo_id *philo, char *action)
{
	pthread_mutex_lock(philo->print);
	printf("%lums   %d  %s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->print);
}

void	destroy_mutex(t_philo_id *philo)
{
	int	i;

	i = 0;
	while (i < philo->philoo->n_philo)
		pthread_mutex_destroy(&philo->fork[i++]);
}

unsigned long	time_now(t_philo_id *philo)
{
	return (timer() - philo->philoo->tm);
}
