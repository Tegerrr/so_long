/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:43:48 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/04 22:07:38 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*game(t_mlx *mlx)
{
	int	img_widths;
	int	img_height;
	
	img_height = 64;
	img_widths = 64;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "Hello world!");
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, WALL, &img_widths, &img_height);
	mlx_hook(mlx->win, 17, 1L<<2, krest, &mlx);
	mlx_key_hook(mlx->win, key_hook, NULL);
	mlx_loop(mlx->mlx);
	return (mlx);
}
