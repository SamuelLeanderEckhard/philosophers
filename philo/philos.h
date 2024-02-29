/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:51 by seckhard          #+#    #+#             */
/*   Updated: 2024/02/29 21:24:53 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# define OK 1
# define FAILURE 2

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#include <sys/time.h>
#include <limits.h>

typedef struct s_commands	t_commands;


typedef struct s_forks
{
	pthread_mutex_t	fork;
	int	number_of_forks;
}			t_forks;

typedef struct	s_philos
{
	int			id;
	double		meals;
	bool		full;
	double		last_meal;
	pthread_t	number_of_philosophers;
	t_forks		*left_fork;
	t_forks		*right_fork;
	t_commands	*table;
}		t_philos;

typedef struct s_commands
{	
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		start;
	bool		end;
	long		limit_meals;
	t_forks		*forks;
	t_philos	*philos;
}			t_commands;





#endif
