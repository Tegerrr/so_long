/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:03:40 by mac               #+#    #+#             */
/*   Updated: 2023/07/01 22:49:11 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_w(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i])
	{
		if (str[i] != '1')
			error();
	}
}

void	val(t_list *stack, int i, int j)
{
	while (stack->mapdata[++i])
	{
		j = -1;
		while (stack->mapdata[i][++j])
		{
			if (i != 0 && ft_strlen(stack->mapdata[i]) != ft_strlen(stack->mapdata[i-1]))
				error();
			if ((j == 0 || stack->mapdata[i][j+1] == '\0')
				&& stack->mapdata[i][j] != '1')
				error();
			if (i == 0 || stack->mapdata[i+1] == NULL)
				check_w(stack->mapdata[i]);
			if (stack->mapdata[i][j] == 'P')
				stack->player++;
			if (stack->mapdata[i][j] == 'C')
				stack->coll++;
			if (stack->mapdata[i][j] == 'E')
				stack->exit++;
		}
	}
	stack->widths = ft_strlen(stack->mapdata[0]);
	if (stack->player != 1 || stack->coll < 1 || stack->exit != 1 || stack->height >= stack->widths)
		error();
}

int	gnl (t_list *stack)
{
	char	*joined;
	char	*temp;
	char	*gn;
	int		fdmap;

	fdmap = open("mandatory/map.ber", O_RDONLY);
	if (fdmap == -1)
		error();
	joined = ft_strdup(get_next_line(fdmap));
	if (!joined)
		error();
	gn = get_next_line(fdmap);
	while (gn)
	{
		if (gn[0] == '\n')
			error();
		temp = ft_strjoin(joined, "\n");
		free(joined);
		joined = ft_strjoin(temp, gn);
		free(temp);
		stack->height++;
		gn = get_next_line(fdmap);
	}
	stack->mapdata = ft_split(joined, '\n');
	free(joined);
	val(stack, -1, -1);
	return (1);
}
