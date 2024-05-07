/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:41 by seckhard          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2024/04/29 17:03:58 by seckhard         ###   ########.fr       */
=======
/*   Updated: 2024/05/07 20:09:11 by seckhard         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char **argv)
{
	t_table table;
	
	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);

		data_init(&table);

		dinner_start(&table);

		clean_up(&table);
	}
	else
	{
		error_exit("Wrong input:\n"
			Green"Usage: ./philo 5 800 200 200 [5]\n"reset);
	}
}
