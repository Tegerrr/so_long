/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:46:23 by mac               #+#    #+#             */
/*   Updated: 2023/07/01 22:11:05 by timelkon         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s1, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
