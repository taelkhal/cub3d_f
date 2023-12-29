/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:23:54 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/19 02:23:54 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

void	extention(char *ext)
{
	int	i;

	i = ft_strlen(ext) - 4;
	if (i <= 0 || ext[i] != '.')
	{
		ft_putstr_fd(RED"INVALID : extention !\n", 2);
		exit(0);
	}
	if (ft_strncmp(ext + i, ".cub", 4))
	{
		ft_putstr_fd(RED"INVALID : extention diff!\n", 2);
		exit(0);
	}
}

void	check_map_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(RED"ERROR: Couldnt find\n", 2);
		exit(0);
	}
	close(fd);
}

t_map	*parser(char *path, t_parse *parse)
{
	t_map	*map;

	check_map_path(path);
	extention(path);
	init_parse(parse);
	map = init_map(path, parse);
	map_check(map->map, parse);
	return (map);
}
