/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:46:23 by mac               #+#    #+#             */
/*   Updated: 2023/07/04 22:17:25 by timelkon         ###   ########.fr       */
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

# define WALL "./images/AnyConv.com__SUPPORT_6A.xpm"
# define TILE "./images/AnyConv.com__TILE_3C.xpm"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		img_height;
	int		img_widths;
}	t_mlx;

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
int		key_hook(int keycode, t_mlx *mlx);
void	open_error(void);
void	ber_error(void);
void	unplayable_error(void);
void	no_map_error(void);
void	argc_error(void);
int		krest(void);
t_mlx	*game(t_mlx *mlx);

#endif
