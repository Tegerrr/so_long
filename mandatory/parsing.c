/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:03:40 by mac               #+#    #+#             */
/*   Updated: 2023/06/28 19:55:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	val(char **str, int i)
{
	int	j;

	j = 0;
	if (i == 0 || str[i+1] == NULL)
	{
		while (str[i][j])
		{
			if (str[i][j] != '1')
				return (0);
			j++;
		}
	}
	return (1);
}

int	parsing(t_list **stack)
{
	int	i;
	int	j;

	i = -1;
	while ((*stack)->mapdata[++i])
	{
		j = -1;
		while ((*stack)->mapdata[i][++j])
		{
			if ((*stack)->mapdata[i][j] != '1' && (j == 0 
				|| (*stack)->mapdata[i][j+1] == '\0') 
					&& val((*stack)->mapdata, i))
				error();
			if ((*stack)->mapdata[i][j] == 'P')
				(*stack)->player++;
			if ((*stack)->mapdata[i][j] == 'E')
				(*stack)->exit++;
			if ((*stack)->mapdata[i][j] == 'C')
				(*stack)->coll++;
		}
	}
}

int	gnl(t_list **stack)
{
	char	*line;
	int		fdmap;
	int		i;

	i = 0;
	fdmap = open("map.ber", O_RDONLY);
	if (fdmap == -1)
		error();
	(*stack)->mapdata[i] = get_next_line(fdmap);
	while (stack->mapdata[i])
		i++;
	parsing(stack);
}
