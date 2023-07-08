/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:23:32 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/08 19:32:02 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	e_texture_change(t_list *stack, int y, int x)
{
	int	img_hei;
	int	img_wid;

	stack->img = mlx_xpm_file_to_image(stack->mlx, TILE, &img_wid, &img_hei);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img, x * 64, y * 64);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img,
		stack->epos_x * 64, stack->epos_y * 64);
	stack->img = mlx_xpm_file_to_image(stack->mlx, ENEMY, &img_wid, &img_hei);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img, x * 64, y * 64);
}

void	e_move(t_list *stack, int y, int x)
{
	if (stack->mapdata[y][x] == '1' || stack->mapdata[y][x] == 'E'
		|| stack->mapdata[y][x] == 'C' || stack->mapdata[y][x] == 'Q')
		return ;
	if (stack->mapdata[y][x] == 'P')
		exit(EXIT_FAILURE);
	printf("%d\n %d\n", stack->epos_y, stack->epos_x);
	stack->mapdata[y][x] = 'Q';
	stack->mapdata[stack->epos_y][stack->epos_x] = '0';
	e_texture_change(stack, y, x);
	
}

void	find_enemy(t_list *stack, int y, int x)
{
	while (stack->mapdata[y])
	{
		x = stack->epos_x;
		while (stack->mapdata[y][++x])
		{
			if (stack->mapdata[y][x] == 'Q')
			{
				stack->epos_y = y;
				stack->epos_x = x;
				return ;
			}
		}
		y++;
	}
}

void	enemy_move(t_list *stack)
{
	int	e_count;
	int i = 0;
	while (stack->mapdata[i])
		printf("%s\n", stack->mapdata[i++]);
	e_count = stack->enemy;
	while (e_count--)
	{
		stack->epos_x += 1;
		find_enemy(stack, stack->epos_y, stack->epos_x);
		if (stack->cur_score % 3 == 0)
			e_move(stack, stack->epos_y, stack->epos_x - 1);
		else if (stack->cur_score % 5 == 0)
			e_move(stack, stack->epos_y, stack->epos_x + 1);
		// else if (stack->cur_score % 7 == 0)
		// 	e_move(stack, stack->epos_y - 1, stack->epos_x);
		else if (stack->cur_score % 4 == 0)
			e_move(stack, stack->epos_y + 1, stack->epos_x);
	}
}
