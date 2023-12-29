#include "cub3D.h"

void	put_pixel(t_game *mlx, int x, int y, unsigned int color)
{
	int	*dst;

	dst = (int *)(mlx->addr
			+ (y * mlx->size_l + x * (mlx->bpp / 8)));
	*dst = color;
}


void	mlx_rectangle(t_game *mlx, int x, int y, int color)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = x;
	width = TAIL * SCALE;
	height = TAIL * SCALE;
	while (i <= x + width)
	{
		j = y;
		while (j <= y + height)
		{
			if (i >= 0 && i < WIN_W && j >= 0 && j < WIN_H)
				put_pixel(mlx, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *mlx)
{
	int	h;
	int	w;
	int	x;
	int	y;

	h = 0;
	while (h < mlx->map->height)
	{
		w = 0;
		while (w < mlx->map->width)
		{
			x = w * TAIL * SCALE;
			y = h * TAIL * SCALE;
			if (mlx->map->map[h][w] == '1')
				mlx_rectangle(mlx, x, y, 0xFFFFFF);
			if (mlx->map->map[h][w] != '1' && mlx->map->map[h][w] != ' '
				&& mlx->map->map[h][w] != '\n')
				mlx_rectangle(mlx, x, y, 0x000000);
			w++;
		}
		h++;
	}
}



// void  draw_map(t_game *game)
// {
//     int x;
//     int map_x;
//     char **map = game->map->map;
//     int map_y;
//     int y;

//     x = 0; 
//     while (x < game->map->width)
//     {
//         y = 0;
//         while (y < game->map->height)
//         {
//             map_x = y * game->size_px_map;
//             map_y = x * game->size_px_map;
//             if (map[y][x] == '1')
//             {
//                 for (int i = map_y + 1; i < map_y + game->size_px_map - 1; i++) // Subtract 1 pixel from each edge
//                 {
//                     for (int j = map_x + 1; j < map_x + game->size_px_map - 1; j++) // Subtract 1 pixel from each edge
//                         my_mlx_pixel_put(game, i, j, 0xFFFFFF);
//                 }
//             }
//             else if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n')
//             {
//                 for (int i = map_y + 1; i < map_y + game->size_px_map - 1; i++) // Subtract 1 pixel from each edge
//                 {
//                     for (int j = map_x + 1; j < map_x + game->size_px_map - 1; j++) // Subtract 1 pixel from each edge
//                         my_mlx_pixel_put(game, i, j, 0x808080); // White for '1'
//                 }
//             }
//             y++;
//         }
//         x++;
//     }
//     // draw_square(game->mlx, game->win, game->player->x, game->player->y, game->player_size, 0xFFFF00);
// }

// void draw_map(t_game *game)
// {
//     char **map = game->map->map;
//     for (int x = 0; x < game->map->width; x++)
//     {
//         for (int y = 0; y < game->map->height; y++)
//         {
//             int map_x = x * game->size_px_map;
//             int map_y = y * game->size_px_map;
//             int pixel_color = 0x000000; // Default color for empty space
            
//             if (map[y][x] == '1')
//             {
//                 for (int i = map_y + 1; i < map_y + game->size_px_map - 1; i++) // Subtract 1 pixel from each edge
//                 {
//                     for (int j = map_x + 1; j < map_x + game->size_px_map - 1; j++) // Subtract 1 pixel from each edge
//                         my_mlx_pixel_put(game, j, i, 0xFFFFFF);
//                 }
//                 // Wall color
//                 // pixel_color = 0xFFFF00;
//             }
//             else if (map[y][x] != ' ' && map[y][x] != '\n')
//             {
//                 for(int i = map_y + 1; i < map_y + game->size_px_map - 1; i++) // Subtract 1 pixel from each edge
//                 {
//                     for(int j = map_x + 1; j < map_x + game->size_px_map - 1; j++) // Subtract 1 pixel from each edge
//                         my_mlx_pixel_put(game, j, i, 0x808080); // White for '1'
//                 }
//                 // Other tile colorj
//                 // pixel_color = 0x808080;
//             }

//             // Assuming each tile is of size 1x1, adjust coordinates accordingly if needed
//             my_mlx_pixel_put(game, x, y, pixel_color);
//         }
//     }
// }
