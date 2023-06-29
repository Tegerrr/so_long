/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:45:47 by mac               #+#    #+#             */
/*   Updated: 2023/06/28 18:53:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main()
{
	t_list	**stack;

	(*stack)->wall = 0;
	(*stack)->exit = 0;
	(*stack)->player = 0;
	(*stack)->item = 0;
	(*stack)->coll = 0;
    gnl(stack);
}