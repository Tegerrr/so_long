/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookah_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:01:51 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/11 22:00:58 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	texture_change(t_list *stack, int y, int x)
{
	int		img_hei;
	int		img_wid;
	char	*str;
	int		w;

	w = -1;
	str = ft_itoa(++stack->cur_score);
	stack->img = mlx_xpm_file_to_image(stack->mlx, WALL, &img_wid, &img_hei);
	while (w++ != 4)
		mlx_put_image_to_window(stack->mlx, stack->win, stack->img, w * 64, 0);
	mlx_string_put(stack->mlx, stack->win, 14, 32, 0x0000FF00, "Moves made: ");
	mlx_string_put(stack->mlx, stack->win, 100, 32, 0x0000FF00, str);
	free(str);
	stack->img = mlx_xpm_file_to_image(stack->mlx, TILE, &img_wid, &img_hei);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img, x * 64, y * 64);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img,
		stack->ppos_x * 64, stack->ppos_y * 64);
	stack->img = mlx_xpm_file_to_image(stack->mlx, MC, &img_wid, &img_hei);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img, x * 64, y * 64);
}

void	move(t_list *stack, int x, int y)
{
	if (stack->mapdata[y][x] == '1'
		|| (stack->mapdata[y][x] == 'E' && stack->coll))
		return ;
	if (stack->mapdata[y][x] != 'E')
		texture_change(stack, y, x);
	if (stack->mapdata[y][x] == 'C')
		stack->coll--;
	stack->mapdata[stack->ppos_y][stack->ppos_x] = '0';
	if (stack->mapdata[y][x] == 'E')
		exit(EXIT_SUCCESS);
	if (stack->mapdata[y][x] == 'Q')
		exit(EXIT_FAILURE);
	stack->mapdata[y][x] = 'P';
	if (stack->cur_score % 50 == 0)
	{
		mlx_clear_window(stack->mlx, stack->win);
		map_fix(stack, -1, -1, 0);
	}
	stack->ppos_x = x;
	stack->ppos_y = y;
	if (stack->enemy)
		enemy_move(stack);
	if (x == stack->epos_x && y == stack->epos_y)
		exit(EXIT_FAILURE);
}

int	key_hook(int keycode, t_list *stack)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 13 || keycode == 126)
		move(stack, stack->ppos_x, stack->ppos_y - 1);
	else if (keycode == 0 || keycode == 123)
		move(stack, stack->ppos_x - 1, stack->ppos_y);
	else if (keycode == 1 || keycode == 125)
		move(stack, stack->ppos_x, stack->ppos_y + 1);
	else if (keycode == 2 || keycode == 124)
		move(stack, stack->ppos_x + 1, stack->ppos_y);
	return (0);
}
