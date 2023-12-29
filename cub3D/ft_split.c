/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:11:27 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/22 14:48:23 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

int	c_w(char const *s1, char c1)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (s1[i])
	{
		if (s1[i] != c1 && s1[i + 1] == c1)
			c++;
		else if (s1[i] != c1 && s1[i + 1] == '\0')
			c++;
		i++;
	}
	return (c);
}

int	c_l(char const *s1, char c1)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i] == c1 && s1[i])
		i++;
	while (s1[i] != c1 && s1[i])
	{
		k++;
		i++;
	}
	return (k);
}

char	*f_w(const char *s1, char c1)
{
	char	*st;
	int		i;
	int		cl;

	i = 0;
	cl = c_l(s1, c1);
	st = malloc(sizeof(char) * (cl + 1));
	if (!st)
		return (NULL);
	while (s1[i] && s1[i] != c1 && cl > 0)
	{
		st[i] = s1[i];
		i++;
		cl--;
	}
	st[i] = '\0';
	return (st);
}

char	**ft_split(char const *s, char c)
{
	char	**st;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	st = malloc(sizeof(char *) * (c_w(s, c) + 1));
	if (!st)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			st[k] = f_w(&s[i], c);
			i = i + c_l(&s[i], c);
			k++;
		}
	}
	st[k] = 0;
	return (st);
}
