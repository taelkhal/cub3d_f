/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:57:13 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/01 17:58:32 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	turn_left(t_game *game)
{
	game->player->angle -= 3;
    if (game->player->angle < 0)
        game->player->angle += 360.0;
    game->player->pdx = cos(degtorad(game->player->angle)) * 5;
    game->player->pdy = sin(degtorad(game->player->angle)) * 5;
}

void	turn_right(t_game *game)
{
	game->player->angle += 3;
	if (game->player->angle > 360.0)
		game->player->angle -= 360.0;
	game->player->pdx = cos(degtorad(game->player->angle)) * 5;
	game->player->pdy = sin(degtorad(game->player->angle)) * 5;
}

int	move_up(t_game *game, int check)
{
	if (check == 0)
    {
        game->player->pdx = cos(degtorad(game->player->angle)) * 5;
        game->player->pdy = sin(degtorad(game->player->angle)) * 5;
        check = 1;
    }
    if (game->map->map[(int)(game->player->y + game->player->pdy * P_SPEED) / game->size_px_map][(int)(game->player->x) / game->size_px_map] == '0')
        game->player->y = game->player->y + game->player->pdy;
    if (game->map->map[(int)(game->player->y) / game->size_px_map][(int)(game->player->x + game->player->pdx * P_SPEED) / game->size_px_map] == '0')
        game->player->x = game->player->x + game->player->pdx;
	return (check);
}

int	move_down(t_game *game, int check)
{
	if (check == 0)
    {
        game->player->pdx = cos(degtorad(game->player->angle)) * 5;
        game->player->pdy = sin(degtorad(game->player->angle)) * 5;
        check = 1;
    }
    if (game->map->map[(int)(game->player->y - game->player->pdy * P_SPEED) / game->size_px_map][(int)(game->player->x) / game->size_px_map] == '0')
        game->player->y = game->player->y - game->player->pdy;
	if (game->map->map[(int)(game->player->y) / game->size_px_map][(int)(game->player->x - game->player->pdx * P_SPEED) / game->size_px_map] == '0')
        game->player->x = game->player->x - game->player->pdx;
	return (check);
}

void	move_right(t_game *game)
{
	float new_angle;

	new_angle = game->player->angle + 90.0;
    if (new_angle > 360.0)
        new_angle -= 360.0;
    if (game->map->map[(int)(game->player->y + sin(degtorad(new_angle)) * P_SPEED) / game->size_px_map][(int)(game->player->x) / game->size_px_map] == '0')
        game->player->y = game->player->y + sin(degtorad(new_angle)) * 5;
	if (game->map->map[(int)(game->player->y) / game->size_px_map][(int)(game->player->x + cos(degtorad(new_angle)) * P_SPEED) / game->size_px_map] == '0')
        game->player->x = game->player->x + cos(degtorad(new_angle)) * 5;
}

void	move_left(t_game *game)
{
	float	new_angle;

	new_angle = game->player->angle - 90.0;
    if (new_angle < 0)
        new_angle += 360.0;
    if (game->map->map[(int)(game->player->y + sin(degtorad(new_angle)) * P_SPEED) / game->size_px_map]
    		[(int)(game->player->x) / game->size_px_map] == '0')
        game->player->y = game->player->y + sin(degtorad(new_angle)) * 5;
	if (game->map->map[(int)(game->player->y) / game->size_px_map]
    	[(int)(game->player->x + cos(degtorad(new_angle)) * P_SPEED) / game->size_px_map] == '0')
        	game->player->x = game->player->x + cos(degtorad(new_angle)) * 5;
}
