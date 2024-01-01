/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:24:10 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/05 13:24:10 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

char	*check_texture_existence(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(RED"ERROR: WRONG FILE TEXTURE\n", 2);
		exit (0);
	}
	close(fd);
	return (path);
}

void	set_value_in(char *value, char c, t_parse *parse)
{
	if ((c == 'N' && parse->NO_tex) || (c == 'W' && parse->WE_tex)
		|| (c == 'S' && parse->SO_tex) || (c == 'E' && parse->EA_tex)
		|| (c == 'F' && parse->F_value) || (c == 'C' && parse->C_value))
	{
		ft_putstr_fd(RED"ERROR: DUplicate\n", 2);
		exit(0);
	}
	if (c == 'N')
		parse->NO_tex = check_texture_existence(value);
	else if (c == 'W')
		parse->WE_tex = check_texture_existence(value);
	else if (c == 'S')
		parse->SO_tex = check_texture_existence(value);
	else if (c == 'E')
		parse->EA_tex = check_texture_existence(value);
	else if (c == 'F')
		parse->F_value = value;
	else if (c == 'C')
		parse->C_value = value;
}

void	get_value(char *line, char c, t_parse *parse)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\t')
	{
		ft_putstr_fd(RED"ERROR: TAB in file\n", 2);
		exit(0);
	}
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	while (j > 0 && line[j - 1] == ' ')
		j--;
	if (line[j - 1] == '\t')
	{
		ft_putstr_fd(RED"ERROR: TAB in file\n", 2);
		exit(0);
	}
	value = ft_substr(line, i, j - i);
	set_value_in(value, c, parse);
}

int	check_lines(char *line, t_parse *parse)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		j = i + 1;
		while (line[j] && line[j] != ' ')
			j++;
		if (j - i == 2 && (!ft_strncmp(line + i, "NO", 2)
				|| !ft_strncmp(line + i, "SO", 2)))
			get_value(line + j, line[i], parse);
		else if (j - i == 2 && (!ft_strncmp(line + i, "WE", 2)
				|| !ft_strncmp(line + i, "EA", 2)))
			get_value(line + j, line[i], parse);
		else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
			get_value(line + j, line[i], parse);
		else
			error_invalid();
		return (1);
	}
	return (1);
}

void	reads(t_parse *parse, int fd, int count)
{
	char	*line;
	char	*map;

	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line)
		{
			printf ("line = %s\n", line);
			free(line);
		}
		if (line_is_empty(line) && count == 6)
			continue ;
		if (count >= 6)
		{
			if (line_is_empty_in(line))
				error_empty_line();
			map = ft_strjoin(map, line);
			count++;
		}
		else if (!line_is_empty(line))
			count += check_lines(line, parse);
		free(line);
	}
	parse->map_holder = ft_split(map, '\n');
	free(map);
}
