/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:49:34 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/04 19:23:43 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_flood(char **str, t_list *maf, t_list *stack)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if ((str[i][j] == 'P' || str[i][j] == 'C'
				|| maf->coll != stack->coll) && maf->exit)
				unplayable_error();
		}
	}
}

void	fill(t_list *stack, t_list *maf, int x, int y)
{
	if ((x < 0 || x >= stack->height || y < 0 || y >= stack->widths)
			|| (maf->mapdata[x][y] != 'C' && maf->mapdata[x][y] != 'P'
				&& maf->mapdata[x][y] != '0'))
		return ;
	if (maf->mapdata[x][y] == 'C')
		maf->coll++;
	if (maf->mapdata[x][y] == 'E')
		maf->exit = 1;
	maf->mapdata[x][y] = 'f';
	fill(stack, maf, x - 1, y);
	fill(stack, maf, x, y - 1);
	fill(stack, maf, x + 1, y);
	fill(stack, maf, x, y + 1);
}

void	flood_fill(t_list *stack, char **tab, int x, int y)
{
	t_list	maf;
	maf.coll = 0;
	maf.mapdata = tab;
	fill(stack, &maf, x, y);
	check_flood(maf.mapdata, &maf, stack);
}
