/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:07:53 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/07 01:07:53 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// t_map *init_map(char *path)
// {
//     t_map *map;

//     map = malloc(sizeof(t_map));
//     map->map = read_map(path);
//     map->width = lenth_width_map(map->map) - 1; // x hia l3ard
//     map->height = lenth_height_map(map->map); // y hia toll
//     return (map);
// }

t_player *init_player(t_game *game)
{
    t_player *player;

    player = malloc(sizeof(t_player));
    player->x = get_x_player(game);
    player->y = get_y_player(game);
    player->angle = 0;
    player->pdx = cos(player->angle) * 5;
    player->pdy = sin(player->angle) * 5;
    return (player);
}

t_castrays *init_castrays(t_castrays *castrays)
{
    castrays->r = 0;
    castrays->mx = 0;
    castrays->my = 0;
    castrays->mp = 0;
    castrays->dof = 0;
    castrays->rx = 0;
    castrays->ry = 0;
    castrays->ra = 0;
    castrays->xo = 0;
    castrays->yo = 0;
    return (castrays);
}

void init_game(t_game *game, char *av)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
    game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->line_length = calloc(sizeof(int), 5);
	game->bits_per_pixel = calloc(sizeof(int), 5);
	game->endian = calloc(sizeof(int), 5);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel[0], &game->line_length[0], &game->endian[0]);
    game->player_size = 15;
    game->size_px_map = 64;
    game->mouse = WIN_W / 2;
    game->parse = malloc(sizeof(t_parse));
    game->map = parser(av, game->parse);
    game->player = init_player(game);
    game->castrays = malloc(sizeof(t_castrays));
    game->castrays = init_castrays(game->castrays);
}
