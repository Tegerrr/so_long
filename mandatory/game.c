/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:43:48 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/06 19:02:36 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_fix(t_mlx *mlx, t_list *stack, int i, int j)
{
	int	x;
	int	y;

	y = 0;
	i = -1;
	while (stack->mapdata[++i])
	{
		x = 0;
		j = -1;
		while (stack->mapdata[i][++j])
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, TILE, &mlx->img_wid, &mlx->img_hei);
			if (stack->mapdata[i][j] == '1')
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, WALL, &mlx->img_wid, &mlx->img_hei);
			else if (stack->mapdata[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x, y);
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, MC, &mlx->img_wid, &mlx->img_hei);
			}
			else if (stack->mapdata[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x, y);
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, COIN, &mlx->img_wid, &mlx->img_hei);
			}
			else if (stack->mapdata[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x, y);
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, EXIT, &mlx->img_wid, &mlx->img_hei);
			}
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x, y);
			x += 64;
		}
		y += 64;
	}
}

t_mlx	*game(t_mlx *mlx, t_list *stack)
{
	stack->height *= 64;
	stack->widths *= 64;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx,  stack->widths, stack->height, "Chren 2");
	stack->mlx = mlx->mlx;
	stack->win = mlx->win;
	map_fix(mlx, stack, -1, -1);
	mlx_hook(mlx->win, 17, 0L, krest, &mlx);
	mlx_key_hook(mlx->win, key_hook, stack);
	mlx_loop(mlx->mlx);
	return (mlx);
}
