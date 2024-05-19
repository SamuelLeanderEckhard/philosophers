/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:01 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/08 18:05:06 by seckhard         ###   ########.fr       */
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

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == EINVAL)
		error_exit("The value specified by thread does not refer to an \
		initialized thread object.");
	else if (status == EAGAIN)
		error_exit("The system lacked the necessary resources to create \
		another thread, or the system-imposed limit on the total number \
		of threads in a process PTHREAD_THREADS_MAX would be exceeded.");
	else if (status == EPERM)
		error_exit("The caller does not have appropriate permission to \
		set the required scheduling parameters or scheduling policy.");
	else if (status == ESRCH)
		error_exit("No thread could be found corresponding to that \
		specified by the given thread ID.");
	else if (status == EDEADLK)
		error_exit("A deadlock was detected or the value of thread \
		specifies the calling thread.");
	else if (status == EINVAL && opcode == JOIN)
		error_exit("The implementation has detected that the value \
		specified by thread does not refer to a joinable thread.");
}

static void	handle_mutex_error(int error_code)
{
	if (error_code == EINVAL)
		error_exit("The value specified by mutex does not \
			refer to an initialized mutex object.");
	else if (error_code == EAGAIN)
		error_exit("The mutex could not be acquired because \
			the maximum number of recursive locks for \
			mutex has been exceeded.");
	else if (error_code == EDEADLK)
		error_exit("A deadlock condition was detected or \
			the current thread already owns the mutex.");
	else if (error_code == EPERM)
		error_exit("The current thread does not own the mutex.");
}

void	safe_mutex_handle(t_philos *mutex, t_opcode opcode)
{
	if (opcode == INIT)
	{
		if (pthread_mutex_init(mutex, NULL))
			error_exit("Mutex init failed");
	}
	else if (opcode == DESTROY)
	{
		if (pthread_mutex_destroy(mutex))
			error_exit("Mutex destroy failed");
	}
	else if (opcode == LOCK)
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
