/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:43:47 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/23 01:43:47 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void rotateleft(t_game *game)
{
    game->player->angle -= 3;
    if (game->player->angle < 0)
        game->player->angle += 360.0;
    game->player->pdx = cos(degtorad(game->player->angle)) * 5;
    game->player->pdy = sin(degtorad(game->player->angle)) * 5;
}

void rotateright(t_game *game)
{
    game->player->angle += 3;
    if (game->player->angle > 360.0)
        game->player->angle -= 360.0;
    game->player->pdx = cos(degtorad(game->player->angle)) * 5;
    game->player->pdy = sin(degtorad(game->player->angle)) * 5;
}

int mouse_hook(int x, int y, t_game *game)
{
    // mlx_mouse_get_pos(game->mlx,game->win, &x, &y);
    if ((x > 0 && x < WIN_W) && (y > 0 && y < WIN_H))
	{
        if (game->mouse < x)
            rotateright(game);
        else if (game->mouse > x)
            rotateleft(game);
        game->mouse = x;
    }
    // mlx_mouse_hook(game->win, mouse_hook, game);
    return (0);
}
