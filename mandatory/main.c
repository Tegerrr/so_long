/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:45:47 by mac               #+#    #+#             */
/*   Updated: 2023/07/03 20:18:41 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *str)
{
	while (str+4)
		str++;
	if (ft_strncmp(str, ".ber", ft_strlen(str)) == 0)
		return (1);
	return (0);
}

void	error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	stack;
	void	*mlx;
	void	*mlx_win;
	
	if (argc != 2 && !ber_check(argv[1]))
		error();
	stack.coll = 0;
	stack.exit = 0;
	stack.item = 0;
	stack.player = 0;
	stack.score = 0;
	stack.height = 1;
	if (gnl(&stack, argv))
		printf("OK\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
