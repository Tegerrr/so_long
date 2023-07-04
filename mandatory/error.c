/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:02:39 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/04 19:28:54 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_error(void)
{
	write (2, "Error\nA given 'map' file doesn't exist\n", 39);
	exit(EXIT_FAILURE);
}

void	ber_error(void)
{
	write (2, "Error\nThe 'map' file is not of '.ber' type\n", 43);
	exit(EXIT_FAILURE);
}

void	unplayable_error(void)
{
	write (2, "Error\nThe given map is unplayable\n", 34);
	exit(EXIT_FAILURE);
}

void	no_map_error(void)
{
	write (2, "Error\nThe given map is illegal\n", 31);
	exit(EXIT_FAILURE);
}

void	argc_error(void)
{
	write (2, "Error\nWrong number of arguments\n", 32);
	exit(EXIT_FAILURE);
}
