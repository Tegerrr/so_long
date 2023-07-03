/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:46:23 by mac               #+#    #+#             */
/*   Updated: 2023/07/03 20:08:32 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"
# include "mlx/mlx.h"

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

int		gnl (t_list *stack, char **argv);
void	error(void);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s1, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	flood_fill(t_list *stack, char **tab, int x, int y);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	go_game(void *mlx);

#endif
