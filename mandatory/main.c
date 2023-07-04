/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:45:47 by mac               #+#    #+#             */
/*   Updated: 2023/07/04 21:46:15 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *str, t_list *stack)
{
	int	size;

	size = ft_strlen(str);
	stack->coll = 0;
	stack->exit = 0;
	stack->item = 0;
	stack->player = 0;
	stack->score = 0;
	stack->height = 1;
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
	if (gnl(&stack, argv))
		printf("OK\n");
	game(&mlx);
	return (0);
}
