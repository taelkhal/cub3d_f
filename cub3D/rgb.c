/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:38:01 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/23 16:32:50 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					o;
	unsigned long long	p;

	o = 0;
	p = 0;
	while (str[o] >= '0' && str[o] <= '9')
	{
		p = p * 10 + (str[o] - '0');
		o++;
	}
	if (p > 255)
	{
		ft_putstr_fd("ERROR: Number should be betwin 0 and 255", 2);
		exit(0);
	}
	return (p);
}

void	set_rgb_value(t_parse *parse, char *str, char c)
{
	char	**splited;
	int R;
	int G;
	int B;

	if (c_w(str, ',') != 3)
	{
		ft_putstr_fd(RED"ERROR: F & C should be only 3\n", 2);
		exit(0);
	}
	splited = ft_split(str, ',');
	R = ft_atoi(splited[0]);
	G = ft_atoi(splited[1]);
	B = ft_atoi(splited[2]);
	if (c == 'F')
		parse->F_RGB = (R << 16) | (G << 8) | B;
	else if (c == 'C')
		parse->C_RGB = (R << 16) | (G << 8) | B;
}

void	rgb(t_parse *parse, char *str, char c)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (str[i])
	{
		if (str[i] == ',')
			f++;
		if (!ft_isdigit(str[i]) && str[i] != ',')
		{
			ft_putstr_fd(RED"ERROR: this should be number separated by , and contain numbers\n", 2);
			exit(0);
		}
		i++;
	}
	if (f != 2)
	{
		ft_putstr_fd(RED"ERROR: 2 , ONLY\n", 2);
		exit(0);
	}
	if (c == 'F')
		set_rgb_value(parse, str, 'F');
	else if (c == 'C')
		set_rgb_value(parse, str, 'C');
}
