/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:01 by seckhard          #+#    #+#             */
/*   Updated: 2024/04/29 17:46:01 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_exit("Malloc failed");
	return (ptr);
}

static void handle_mutex_error(int error_code)
{
	if (error_code == EINVAL)
		error_exit("The value specified by mutex does not refer to an initialized mutex object.");
	else if (error_code == EAGAIN)
		error_exit("The mutex could not be acquired because the maximum number of recursive locks for mutex has been exceeded.");
	else if (error_code == EDEADLK)
		error_exit("A deadlock condition was detected or the current thread already owns the mutex.");
	else if (error_code == EPERM)
		error_exit("The current thread does not own the mutex.");
}

void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
	{
		if (pthread_mutex_lock(mutex))
			error_exit("Mutex lock failed");
	}
	else if (opcode == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex))
			error_exit("Mutex unlock failed");
	}
}