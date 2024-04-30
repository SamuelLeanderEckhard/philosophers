/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:00:10 by seckhard          #+#    #+#             */
/*   Updated: 2024/04/29 16:53:51 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	error_exit(const char *error)
{
	printf(Red" %s \n"reset, error);
	exit(FAILURE);
}
