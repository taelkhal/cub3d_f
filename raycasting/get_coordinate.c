/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:08:33 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/31 16:13:56 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_angle(t_player *player, char c)
{
    if (c == 'N')
        player->angle = 270;
    else if (c == 'S')
        player->angle = 90;
    else if (c == 'W')
        player->angle = 180;
    else if (c == 'E')
        player->angle = 0;
}

int get_x_player(t_game *game)
{
    int i = 0;
    int j = 0;
    while (game->map->map[i])
    {
        j = 0;
        while (game->map->map[i][j])
        {
            if (game->map->map[i][j] == 'N' || game->map->map[i][j] == 'S' || game->map->map[i][j] == 'W' || game->map->map[i][j] == 'E')
                return (j * 64);
            j++;
        }
        i++;
    }
    return (0);
}

int get_y_player(t_game *game)
{
    int i = 0;
    int j = 0;
    while (game->map->map[i])
    {
        j = 0;
        while (game->map->map[i][j])
        {
            if (game->map->map[i][j] == 'N' || game->map->map[i][j] == 'S' || game->map->map[i][j] == 'W' || game->map->map[i][j] == 'E')
                return (i * 64);
            j++;
        }
        i++;
    }
    return (0);
}

void get_angle(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map->map[i])
    {
        j = 0;
        while (game->map->map[i][j])
        {
            if (game->map->map[i][j] == 'N' || game->map->map[i][j] == 'S' || game->map->map[i][j] == 'W' || game->map->map[i][j] == 'E')
            {
                check_angle(game->player, game->map->map[i][j]);
                game->map->map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
}
