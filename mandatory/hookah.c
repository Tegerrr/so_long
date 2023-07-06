/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookah.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:01:51 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/06 20:01:10 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_change(t_list *stack, int y, int x)
{
	int	img_hei;
	int	img_wid;

	stack->img = mlx_xpm_file_to_image(stack->mlx, TILE, &img_wid, &img_hei);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img, x * 64, y * 64);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img, stack->ppos_x * 64, stack->ppos_y * 64);
	stack->img = mlx_xpm_file_to_image(stack->mlx, MC, &img_wid, &img_hei);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img, x * 64, y * 64);
}

void	move(t_list *stack, int x, int y)
{
	if (stack->mapdata[y][x] == '1' || (stack->mapdata[y][x] == 'E' && stack->coll))
		return ;
	if (stack->mapdata[y][x] != 'E')
		texture_change(stack, y, x);
	ft_putnbr_fd(++stack->cur_score, 1);
	write (1, "\n", 1);
	if (stack->mapdata[y][x] == 'C')
		stack->coll--;
	stack->mapdata[stack->ppos_y][stack->ppos_x] = '0';
	if (stack->mapdata[y][x] == 'E')
		exit(EXIT_SUCCESS);
	stack->mapdata[y][x] = 'P';
	stack->ppos_x = x;
	stack->ppos_y = y;
}

int	key_hook(int keycode, t_list *stack)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 13)
		move(stack, stack->ppos_x, stack->ppos_y - 1);
	else if (keycode == 0)
		move(stack, stack->ppos_x - 1, stack->ppos_y);
	else if (keycode == 1)
		move(stack, stack->ppos_x, stack->ppos_y + 1);
	else if (keycode == 2)
		move(stack, stack->ppos_x + 1, stack->ppos_y);
	return (0);
}

int	krest(void)
{
	exit(EXIT_SUCCESS);
}
