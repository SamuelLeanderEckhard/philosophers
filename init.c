/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:56:57 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/07 20:26:04 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	assign_forks(t_philo *philo, t_fork *forks, \
				int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	if (philo->id % 2)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = forks[(philo_position + 1) % philo_nbr];
	}
}

static void	 philo_table(t_table *table)
{
	int	i;
	t_philos	
}

void	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end = false;
	table->philos = safe_malloc(table->philo_nbr * sizeof(t_philos));
	table->forks = safe_malloc(table->philo_nbr * sizeof(t_forks));
	while (++i < table->philo_nbr)
	{
		safe_mutex_handle(pthread_mutex_init(&table->forks[i].fork, NULL));
		table->forks[i]->id = i;
	}
	philo_init(table);
}
