/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:02:26 by taelkhal          #+#    #+#             */
/*   Updated: 2023/11/26 15:34:20 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_total_words(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (j);
}

int	ft_len_word(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_add_words(const char *str, char c)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_len_word(str, c);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (str[i] && str[i] != c && len > 0)
	{
		s[i] = str[i];
		i++;
		len--;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_total_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			str[j] = ft_add_words(&s[i], c);
			i = i + ft_len_word(&s[i], c);
			j++;
		}
	}
	str[j] = 0;
	return (str);
}
