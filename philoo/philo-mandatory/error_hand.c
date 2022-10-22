/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <ylambark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:14:09 by ylambark          #+#    #+#             */
/*   Updated: 2022/10/21 14:24:41 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	error(int ac)
{
	if (ac < 5)
	{
		printf("Error :  I-Need-More-Arg\n");
		return (1);
	}
	if (ac > 6)
	{
		printf("Error :  To-Much-Arg-For-Me\n");
		return (1);
	}
	return (0);
}

int	not_num(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9'))
			{
				printf("Error Arg\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
