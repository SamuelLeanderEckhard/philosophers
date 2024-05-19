/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:26:27 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/19 19:03:36 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void *application(void *data)
{
 t_phil *phil;

 phil = (t_phil *)data;
 if (phil->var->num_phil == 1)
 {
  ft_lone_ranger(phil);
  return (NULL);
 }
 if (phil->pos % 2 == 0)
  usleep(150);
 ft_odd_phil(phil);
 return (NULL);
}

int start_simulation(t_var *var)
{
 int i;

 i = 0;
 var->start_time = get_time_in_ms();
 while (i < var->num_phil)
 {
  var->phil[i].last_time_ate = get_time_in_ms();
  if (pthread_create(&var->phil[i].thread, NULL, \
     &application, &var->phil[i]))
   return (printf("Error creating threads\n"), 1);
  i++;
 }
 i = 0;
 while (i < var->num_phil)
 {
  pthread_join(var->phil[i].thread, NULL);
  i++;
 }
 if (var->stop_sign == 1)
  printf("%ld %d %s\n", var->time_of_death, \
    var->index_of_the_phil_who_died, "died");
 ft_free(var);
 return (0);
}

void ft_odd_phil(t_philos *phil)
{
 while (phil->must_eat)
 {
  pthread_mutex_lock(&phil->var->forks[phil->fr_fork]);
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
    phil->pos, "has taken a fork");
  pthread_mutex_lock(&phil->var->forks[phil->sc_fork]);
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
    phil->pos, "has taken a fork");
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
    phil->pos, "is eating");
  if (ft_sleep(phil, phil->var->time_to_eat))
   break ;
  phil->last_time_ate = get_time_in_ms();
  pthread_mutex_unlock(&phil->var->forks[phil->sc_fork]);
  pthread_mutex_unlock(&phil->var->forks[phil->fr_fork]);
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
    phil->pos, "is sleeping");
  if (ft_sleep(phil, phil->var->time_to_sleep))
   break ;
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
    phil->pos, "is thinking");
  phil->must_eat--;
 }
}

void ft_odd_phil(t_philos *phil)
{
	 while (phil->must_eat)
 {
  pthread_mutex_lock(&phil->var->forks[phil->fr_fork]);
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
	phil->pos, "has taken a fork");
  pthread_mutex_lock(&phil->var->forks[phil->sc_fork]);
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
	phil->pos, "has taken a fork");
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
	phil->pos, "is eating");
  if (ft_sleep(phil, phil->var->time_to_eat))
   break ;
  phil->last_time_ate = get_time_in_ms();
  pthread_mutex_unlock(&phil->var->forks[phil->sc_fork]);
  pthread_mutex_unlock(&phil->var->forks[phil->fr_fork]);
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
	phil->pos, "is sleeping");
  if (ft_sleep(phil, phil->var->time_to_sleep))
   break ;
  printf("%ld %d %s\n", get_time_in_ms() - phil->var->start_time, \
	phil->pos, "is thinking");
  phil->must_eat--;
 }
}