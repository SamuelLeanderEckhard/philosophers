/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:51 by seckhard          #+#    #+#             */
/*   Updated: 2024/04/30 19:41:03 by seckhard         ###   ########.fr       */
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
#include <string.h>
#include <stdint.h>
#include <errno.h>


#include <sys/wait.h>
#include <sys/time.h>
#include <limits.h>

// Foreground colors
#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\r[36m"
#define White "\033[37m"

typedef struct s_table	t_table;

typedef struct s_forks
{
	pthread_mutex_t		fork;
	int					number_of_forks;
}			t_forks;

typedef struct	s_philos
{
	int					id;
	double				meals;
	bool				full;
	double				last_meal;
	pthread_t			number_of_philosophers;
	t_forks				*left_fork;
	t_forks				*right_fork;
	t_table				*table;
}			t_philos;

typedef struct s_table
{	
	long				number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				start;
	bool				end;
	long				limit_meals;
	t_forks				*forks;
	t_philos			*philos;
}			t_table;


void    error_exit(const char *error);

void	parse_input(t_table *table, char **argv);


#endif
