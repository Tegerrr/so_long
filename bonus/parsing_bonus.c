/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:03:40 by mac               #+#    #+#             */
/*   Updated: 2023/07/08 18:14:07 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	val_1(t_list *stack, int i, int j)
{
	if (stack->mapdata[i][j] == 'P')
	{
		stack->player++;
		stack->ppos_y = i;
		stack->ppos_x = j;
	}
	if (stack->mapdata[i][j] == 'Q')
		stack->enemy++;
	if (stack->mapdata[i][j] == 'C')
		stack->coll++;
	if (stack->mapdata[i][j] == 'E')
		stack->exit++;
	if (stack->mapdata[i][j] != 'E' && stack->mapdata[i][j] != 'P'
		&& stack->mapdata[i][j] != 'C' && stack->mapdata[i][j] != '0'
			&& stack->mapdata[i][j] != '1' && stack->mapdata[i][j] != 'Q')
		no_map_error();
}

void	val(t_list *stack, int i, int j)
{
	while (stack->mapdata[++i])
	{
		j = -1;
		while (stack->mapdata[i][++j])
		{
			if (i != 0 && ft_strlen(stack->mapdata[i])
				!= ft_strlen(stack->mapdata[i - 1]))
				no_map_error();
			if ((j == 0 || stack->mapdata[i][j + 1] == '\0')
				&& stack->mapdata[i][j] != '1')
				no_map_error();
			if (i == 0 || stack->mapdata[i + 1] == NULL)
				check_w(stack->mapdata[i]);
			val_1(stack, i, j);
		}
		stack->height++;
	}
	stack->widths = ft_strlen(stack->mapdata[0]);
	if (stack->player != 1 || stack->coll < 1
		|| stack->exit != 1)
		no_map_error();
	flood_fill(stack, stack->mapdata, stack->ppos_x, stack->ppos_y);
}

void	gnl_1(t_list *stack, char *temp, char *joined, int fdmap)
{
	int	i;

	i = -1;
	temp = ft_strtrim(joined, "\n");
	free(joined);
	while (temp[++i])
	{
		if (temp[i] == '\n' && temp[i + 1] == '\n'
			&& temp[i + 2] == '\n')
			no_map_error();
	}
	stack->mapdata = ft_split(temp, '\n');
	free(temp);
	val(stack, -1, -1);
	close(fdmap);
}

void	gnl(t_list *stack, char **argv)
{
	char	*joined;
	char	*temp;
	char	*gn;
	int		fdmap;

	fdmap = open(argv[1], O_RDONLY);
	if (fdmap == -1)
		open_error();
	gn = get_next_line(fdmap);
	joined = ft_strdup(gn);
	if (!joined)
		error();
	free(gn);
	gn = get_next_line(fdmap);
	while (gn)
	{
		temp = ft_strjoin(joined, "\n");
		free(joined);
		joined = ft_strjoin(temp, gn);
		free(temp);
		free(gn);
		gn = get_next_line(fdmap);
	}
	free(gn);
	gnl_1(stack, temp, joined, fdmap);
}
