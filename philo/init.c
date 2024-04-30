/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:56:57 by seckhard          #+#    #+#             */
/*   Updated: 2024/04/29 17:47:14 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	init_and_alloc()
{
	
}

void	data_init(t_table *table)
{
	table->end = false;
	table->philos = safe_malloc(table->philo_nbr * sizeof(t_philos));
}
