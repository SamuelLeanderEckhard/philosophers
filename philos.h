/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:51 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/19 19:54:29 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# define OK 0
# define FAILURE 1

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <errno.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_table
{
	int		philo_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_must_eat;
	size_t  meals;
}	t_table;

typedef struct s_philos
{
	pthread_t	*phil;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	int		pos;
	int		num_eaten;
	int		must_eat;
	int		last_time_ate;
}	t_philos;


void    error_exit(const char *error);

void	parse_input(t_table *table, char **argv);

void	*safe_malloc(size_t size);
void	safe_mutex_handle(t_philos *mutex, );


#endif
