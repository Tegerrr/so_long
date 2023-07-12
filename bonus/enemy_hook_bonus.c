/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:23:32 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/12 13:03:04 by timelkon         ###   ########.fr       */
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
	stack->mapdata[y][x] = 'Q';
	stack->mapdata[stack->epos_y][stack->epos_x] = '0';
	e_texture_change(stack, y, x);
}

char	**find_enemy(char **str, t_list *stack, int y, int x)
{
	while (str[y])
	{
		x = 0;
		while (str[y][++x])
		{
			if (str[y][x] == 'Q')
			{
				str[stack->epos_y][stack->epos_x] = '0';
				stack->epos_y = y;
				stack->epos_x = x;
				str[y][x] = '0';
				return (str);
			}
		}
		y++;
	}
	return (str);
}

void	enemy_move(t_list *stack)
{
	char	**str;
	int		e_count;
	int		i;

	stack->epos_y = 0;
	stack->epos_x = -1;
	i = 0;
	str = double_cp(stack->mapdata, stack);
	e_count = stack->enemy;
	while (e_count--)
	{
		str = find_enemy(str, stack, stack->epos_y, stack->epos_x);
		if (stack->cur_score % 7 == 0)
			e_move(stack, stack->epos_y - 1, stack->epos_x);
		else if (stack->cur_score % 5 == 0)
			e_move(stack, stack->epos_y + 1, stack->epos_x);
		else if (stack->cur_score % 2 == 0)
			e_move(stack, stack->epos_y, stack->epos_x + 1);
		else
			e_move(stack, stack->epos_y, stack->epos_x - 1);
	}
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
