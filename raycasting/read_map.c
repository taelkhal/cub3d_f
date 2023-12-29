#include "cub3D.h"

char **read_map(char *path)
{
    char	*line;
	char	*map;
	int		fd;

	line = "";
	map = ft_strdup("");
	fd = open(path, O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		map = ft_strjoin(map, line);
		free(line);
	}
	free(line);
	close(fd);
	if (map[0] == '\0')
		return (NULL);
	return (ft_split(map, '\n'));
}

// void    draw_horizontal_line(t_game *game)
// {
//     int i = 0;
//     while (i < game->map->width * game->size_px_map)
//     {
//         mlx_pixel_put(game->mlx, game->win, i, game->player->y * game->size_px_map, 0x0000FF);
//         i++;
//     }
// }


// void    draw_vertical_lines(t_game *game)
// {
//     int j;
//     int i;

//     i = 0;
//     while (i < game->map->width)
//     {
//         j = 0;
//         while (j < game->map->height * game->size_px_map)
//         {
//             mlx_pixel_put(game->mlx, game->win, i * game->size_px_map, j, 0x000000);
//             j++;
//         }
//         i++;
//     }
// }
