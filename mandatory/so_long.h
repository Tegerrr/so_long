/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:46:23 by mac               #+#    #+#             */
/*   Updated: 2023/06/29 21:30:33 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"
# include "minilibx_opengl_20191021/mlx.h"

typedef struct s_list
{
	int		height;
	int		widths;
	int		ppos_x;
	int		ppos_y;
	int		score;
	int		cur_score;
	char	**mapdata;
	int		wall;
	int		player;
	int		exit;
	int		item;
	int		coll;
	int		enemypos;
	int		gameover;
}	t_list;

int		gnl(t_list *stack);
void	error(void);

#endif
