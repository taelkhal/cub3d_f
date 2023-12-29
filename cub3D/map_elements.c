/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:47:36 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:36 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

void	check_x(char **map)
{
	int	x_count;
	int	i;
	int	j;

	x_count = 1;
	i = 0;
	while (i < tol(map))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'W'
				&& map[i][j] != 'E')
				x_count = 0;
			j++;
		}
		i++;
	}
	if (x_count == 0)
	{
		ft_putstr_fd(RED"ERROR: Map elements\n", 2);
		exit(0);
	}
}

void	check_p(char **map)
{
	int	p_count;
	int	i;
	int	j;

	p_count = 0;
	i = 0;
	while (i < tol(map))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W'
				|| map[i][j] == 'E')
				p_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1)
	{
		ft_putstr_fd(RED"ERROR: Player\n", 2);
		exit(0);
	}
}
