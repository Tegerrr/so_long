/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:40:54 by timelkon          #+#    #+#             */
/*   Updated: 2023/07/06 20:41:08 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
