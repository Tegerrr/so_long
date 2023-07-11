/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:40:54 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/11 18:22:33 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	if (n <= 9)
		i++;
	return (i);
}

int	krest(void)
{
	exit(EXIT_SUCCESS);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	if (!*s)
		return (ft_strdup(""));
	j = ft_strlen(s);
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	while (j > i && ft_strchr(set, s[j]))
		j--;
	return (ft_substr(s, i, (j - i + 1)));
}
