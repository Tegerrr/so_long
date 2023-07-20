/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:43:48 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/20 12:15:48 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_fix_1(char sign, t_list *stack, int x, int y)
{
	if (sign == '1')
			stack->img = mlx_xpm_file_to_image(stack->mlx, WALL,
				&stack->img_wid, &stack->img_hei);
	else if (sign == 'P')
	{
		mlx_put_image_to_window(stack->mlx, stack->win,
			stack->img, x, y);
		stack->img = mlx_xpm_file_to_image(stack->mlx, MC,
				&stack->img_wid, &stack->img_hei);
	}
	else if (sign == 'C')
	{
		mlx_put_image_to_window(stack->mlx, stack->win,
			stack->img, x, y);
		stack->img = mlx_xpm_file_to_image(stack->mlx, COIN,
				&stack->img_wid, &stack->img_hei);
	}
	else if (sign == 'E')
	{
		mlx_put_image_to_window(stack->mlx, stack->win,
			stack->img, x, y);
		stack->img = mlx_xpm_file_to_image(stack->mlx, EXIT,
				&stack->img_wid, &stack->img_hei);
	}
}

void	map_fix(t_list *stack, int i, int j)
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
			stack->img = mlx_xpm_file_to_image(stack->mlx, TILE,
					&stack->img_wid, &stack->img_hei);
			map_fix_1(stack->mapdata[i][j], stack, x, y);
			mlx_put_image_to_window(stack->mlx, stack->win,
				stack->img, x, y);
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
	mlx->win = mlx_new_window(mlx->mlx, stack->widths, stack->height, "Chren");
	stack->mlx = mlx->mlx;
	stack->win = mlx->win;
	stack->mlx = mlx;
	map_fix(stack, -1, -1);
	mlx_hook(mlx->win, 17, 0L, krest, &mlx);
	mlx_key_hook(mlx->win, key_hook, stack);
	mlx_loop(mlx->mlx);
	return (mlx);
}
