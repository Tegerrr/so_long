/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookah.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:01:51 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/04 20:28:02 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	mlx = NULL;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	krest(void)
{
	exit(EXIT_FAILURE);
}
