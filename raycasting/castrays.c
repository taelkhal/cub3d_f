/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:54:00 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/01 17:38:00 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void convert_3d(t_game *game, int check)
{
	float	lineo;
	float	lenn;
	float	wall_h;
	float	distance;
	
	wall_h = fix_p_ang(game->player->angle - game->castrays->ra);
	// int wall_bottom_px = (WIN_H / 2) + (wall_strip_h / 2);
	// int wall_top_px = (WIN_H / 2) - (wall_strip_h / 2);
	distance = calcul_dist(game->player->x, game->player->y, game->castrays->rx, game->castrays->ry);
	distance = distance * cos(degtorad(wall_h));
	lenn = (64 * WIN_H) / distance;
	int tmp = lenn;
	if (lenn > WIN_H)
	    lenn = WIN_H;
	lineo = (WIN_H / 2.0) - (lenn / 2.0);
	// int wall_top_px = (WIN_H / 2) - (wall_strip_h / 2);
	if (check == 1)
	    draw_tex(game, lineo, tmp, game->castrays->rx);
	else
	    draw_tex2(game, lineo, tmp, game->castrays->ry);
	draw_floor(game, lenn, lineo);
	draw_ceilling(game, lineo);
}

void	casting(t_game *game, float x, float y)
{
	while (1)
	{
		if (game->map->map[(int)(game->castrays->ry + y) / 64]
			[(int)(game->castrays->rx / 64)] == '1')
		{
			convert_3d(game, 1);
			return ;
		}
		if (game->map->map[(int)(game->castrays->ry / 64)]
			[(int)(game->castrays->rx + x) / 64] == '1')
		{
			convert_3d(game, 0);
			return ;
		}
		game->castrays->ry += y / 4;
		game->castrays->rx += x / 4;
	}
}

void	castoneray(t_game *game)
{
	float	x;
	float	y;

	game->castrays->ra = fix_p_ang(game->player->angle - 30.0);
	game->r = 0;
	while (game->r < WIN_W)
	{
		game->castrays->rx = game->player->x;
		game->castrays->ry = game->player->y;
		x = cos(degtorad(game->castrays->ra));
		y = sin(degtorad(game->castrays->ra));
		casting(game, x, y);
		game->r++;
		game->castrays->ra += 60.0 / (WIN_W);
		game->castrays->ra = fix_p_ang(game->castrays->ra);
	}
}
