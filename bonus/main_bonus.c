/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:45:47 by mac               #+#    #+#             */
/*   Updated: 2023/07/13 18:49:57 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ber_check(char *str, t_list *stack)
{
	int	size;

	size = ft_strlen(str);
	stack->coll = 0;
	stack->exit = 0;
	stack->item = 0;
	stack->player = 0;
	stack->height = 0;
	stack->cur_score = 0;
	stack->enemy = 0;
	while (size--)
	{
		if (ft_strncmp(str, ".ber\0", 5) == 0)
			return (1);
		str++;
	}
	ber_error();
	return (0);
}

void	big_error(void)
{
	write (2, "Error\nThe map is too big\n", 25);
	exit(EXIT_FAILURE);
}

void	error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	stack;
	t_mlx	mlx;
	char	*gn;
	int		fdmap;

	if (argc != 2 || !ber_check(argv[1], &stack))
		argc_error();
	fdmap = open(argv[1], O_RDONLY);
	if (fdmap == -1)
		open_error();
	gn = get_next_line(fdmap);
	if (gn <= 0)
		error();
	gnl(&stack, gn, fdmap);
	game(&mlx, &stack);
	return (0);
}
