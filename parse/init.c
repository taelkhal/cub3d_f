/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:38 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/18 20:40:38 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

int	open_path(char *path, int permition)
{
	int	fd;

	fd = open(path, permition);
	if (fd <= 0)
	{
		ft_putstr_fd("Error: cant find file\n", 2);
		exit(0);
	}
	return (fd);
}

t_map	*init_map(char *path, t_parse *parse)
{
	t_map	*map;
	int		fd;
	int		c;

	c = 0;
	map = malloc(sizeof(t_map));
	fd = open_path(path, O_RDONLY);
	reads(parse, fd, c);
	map->map = parse->map_holder;
	if (!map->map[0])
	{
		ft_putstr_fd(RED"ERROR: map not found\n", 2);
		exit(0);
	}
	close(fd);
	return (map);
}

void	init_parse(t_parse *parse)
{
	parse->C_value = NULL;
	parse->F_value = NULL;
	parse->NO_tex = NULL;
	parse->SO_tex = NULL;
	parse->EA_tex = NULL;
	parse->WE_tex = NULL;
	parse->line_size = 0;
	parse->F_RGB = 0;
	parse->C_RGB = 0;
	parse->map_holder = NULL;
}
