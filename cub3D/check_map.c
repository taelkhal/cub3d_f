/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:32:48 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/22 14:48:14 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

int	c_f(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_first_and_last(char **map)
{
	int	y;

	y = 0;
	while (map[0][y])
	{
		if (c_f(map[0][y]))
			return (1);
		y++;
	}
	y = 0;
	while (map[tol(map) - 1][y])
	{
		if (c_f(map[tol(map) - 1][y]))
			return (1);
		y++;
	}
	return (0);
}

int	check_middle(char **map, t_parse *parse)
{
	int		x;
	size_t	y;

	x = 0;
	while (x < (tol(map) - 1))
	{
		y = 0;
		while (map[x][y])
		{
			if (c_f(map[x][0]) || c_f(map[x][ft_strlen(map[x]) - 1]))
				return (1);
			if ((c_f(map[x][y])) && ((ft_strlen(map[x - 1]) - 1) < y
				|| (ft_strlen(map[x + 1]) - 1) < y || map[x - 1][y] == ' '
				|| map[x + 1][y] == ' ' || map[x][y + 1] == ' '
				|| map[x][y - 1] == ' ' || !map[x][y + 1]))
				return (1);
			y++;
		}
		if (ft_strlen(map[x]) > parse->line_size)
			parse->line_size = ft_strlen(map[x]);
		x++;
	}
	return (0);
}

int	map_check(char **map, t_parse *parse)
{
	if (!parse->F_value || !parse->C_value || !parse->EA_tex
		|| !parse->NO_tex || !parse->WE_tex)
	{
		ft_putstr_fd(RED"ERROR: EMPTY VALUES\n", 2);
		exit(0);
	}
	if (check_first_and_last(map) || check_middle(map, parse))
	{
		ft_putstr_fd(RED"ERROR: In map\n", 2);
		exit(0);
	}
	check_p(map);
	check_x(map);
	rgb(parse, parse->C_value, 'C');
	rgb(parse, parse->F_value, 'F');
	return (0);
}
