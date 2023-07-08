/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:45:47 by mac               #+#    #+#             */
/*   Updated: 2023/07/08 13:16:53 by timelkon         ###   ########.fr       */
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

void	error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	stack;
	t_mlx	mlx;

	if (argc != 2 || !ber_check(argv[1], &stack))
		argc_error();
	gnl(&stack, argv);
	game(&mlx, &stack);
	return (0);
}
