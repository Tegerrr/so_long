/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:43:48 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/12 13:26:29 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	string_put_please(t_list *stack)
{
	char	*str;

	str = ft_itoa(stack->cur_score);
	mlx_string_put(stack->mlx, stack->win, 14, 32, 0x0000FF00, "Moves made: ");
	if (str == NULL)
		mlx_string_put(stack->mlx, stack->win, 100, 32, 0x0000FF00, "0");
	else
		mlx_string_put(stack->mlx, stack->win, 100, 32, 0x0000FF00, str);
	free(str);
}

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

void	map_fix(t_list *stack, int i, int j, int y)
{
	int	x;

	while (stack->mapdata[++i])
	{
		x = 0;
		j = -1;
		while (stack->mapdata[i][++j])
		{
			stack->img = mlx_xpm_file_to_image(stack->mlx, TILE,
					&stack->img_wid, &stack->img_hei);
			if (stack->mapdata[i][j] == 'Q')
			{
				mlx_put_image_to_window(stack->mlx, stack->win,
					stack->img, x, y);
				stack->img = mlx_xpm_file_to_image(stack->mlx, ENEMY,
						&stack->img_wid, &stack->img_hei);
			}
			map_fix_1(stack->mapdata[i][j], stack, x, y);
			mlx_put_image_to_window(stack->mlx, stack->win,
				stack->img, x, y);
			x += 64;
		}
		y += 64;
	}
	string_put_please(stack);
}

t_mlx	*game(t_mlx *mlx, t_list *stack)
{
	stack->height *= 64;
	stack->widths *= 64;
	stack->epos_y = 0;
	stack->epos_x = -1;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, stack->widths, stack->height, "Chren");
	stack->mlx = mlx->mlx;
	stack->win = mlx->win;
	map_fix(stack, -1, -1, 0);
	mlx_hook(mlx->win, 17, 0L, krest, &mlx);
	mlx_key_hook(mlx->win, key_hook, stack);
	mlx_loop(mlx->mlx);
	return (mlx);
}
