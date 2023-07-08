/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:46:23 by mac               #+#    #+#             */
/*   Updated: 2023/07/08 18:05:55 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"
# include "/Users/timelkon/Desktop/so_long_git/mlx/mlx.h"

# define WALL "./images/AnyConv.com__BRICK_2B.xpm"
# define TILE "./images/AnyConv.com__TILE_3C.xpm"
# define MC "./images/AnyConv.com__pixil-frame-0.xpm"
# define EXIT "./images/AnyConv.com__BIG_portal_jan.xpm"
# define COIN "./images/AnyConv.com__scroll_jan.xpm"
# define ENEMY "./images/AnyConv.com__Enemy_tile.xpm"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_hei;
	int		img_wid;
}	t_mlx;

typedef struct s_list
{
	int		img_wid;
	int		img_hei;
	void	*mlx;
	void	*win;
	void	*img;
	int		height;
	int		widths;
	int		ppos_x;
	int		ppos_y;
	int		cur_score;
	char	**mapdata;
	int		wall;
	int		player;
	int		exit;
	int		item;
	int		coll;
	int		enemy;
	int		epos_x;
	int		epos_y;
}	t_list;

void	gnl(t_list *stack, char **argv);
void	error(void);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s1, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	flood_fill(t_list *stack, char **tab, int x, int y);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	go_game(void *mlx);
int		key_hook(int keycode, t_list *stack);
void	open_error(void);
void	ber_error(void);
void	unplayable_error(void);
void	no_map_error(void);
void	argc_error(void);
int		krest(void);
t_mlx	*game(t_mlx *mlx, t_list *stack);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char const *s, char const *set);
void	map_fix(t_list *stack, int i, int j, int y);
void	enemy_move(t_list *stack);

#endif
