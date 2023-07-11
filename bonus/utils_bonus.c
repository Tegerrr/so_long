/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:54:09 by mac               #+#    #+#             */
/*   Updated: 2023/07/11 20:19:53 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*nbr(int n, char *s, int n1)
{
	int	i;

	i = n1;
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	s[i] = '\0';
	i--;
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	while (i >= 0 && n > 0)
	{
		s[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n1)
{
	unsigned int	n;
	char			*s;

	if (n1 == 0)
		return(0);
	if (n1 == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n1 == 2147483647)
		return (ft_strdup("2147483647"));
	n = ft_numlen((unsigned int)n1);
	s = malloc(n * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	s = nbr(n1, s, n);
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*spc;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	spc = malloc (ft_strlen(str1) + ft_strlen(str2) * sizeof(char) + 1);
	if (spc == NULL)
		return (NULL);
	while (*str1)
		spc[i++] = *str1++;
	while (*str2)
	{
		spc[i] = *str2;
		i++;
		str2++;
	}
	spc[i] = '\0';
	return (spc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;
	char	*spc;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	st = (char *)s;
	spc = malloc(len + 1);
	if (!spc)
		return (0);
	i = 0;
	while (i != len)
	{
		spc[i] = st[start];
		i++;
		start++;
	}
	spc[i] = '\0';
	return (spc);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	a = 0;
	if (n == 0)
		return (0);
	while (str1[a] == str2[a] && a < n && str1[a] != '\0' && str2[a] != '\0')
		a++;
	if (a < n)
	{
		return (str1[a] - str2[a]);
	}
	else
		return (0);
}
