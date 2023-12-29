/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:54:00 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/11 15:54:00 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ray(t_game *g, float y1, float line, float x)
{
	char	*dst;
	int		i;

	i = 0;
	if (line > WIN_H)
		i = (line - WIN_H) / 2;
	while (i < line)
	{
		if (y1 >= WIN_H)
			break ;
		if (g->castrays->ra >= 180.0 && g->castrays->ra <= 360.0)
			dst = g->no_texadr + (int)(i * (g->n_h / line))
				% g->n_h * g->line_length[1]
				+ (int)(x * g->n_w / 64) % g->n_w * (g->bits_per_pixel[1] / 8);
		if (g->castrays->ra >= 0 && g->castrays->ra <= 180.0)
			dst = g->so_texadr + (int)(i * (g->s_h / line))
				% g->s_h * g->line_length[2]
				+ (int)(x * g->s_w / 64) % g->s_w * (g->bits_per_pixel[2] / 8);
		my_mlx_pixel_put(g, g->i2, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}


void	draw_ray2(t_game *game, float y1, float lineho, float x)
{
	char	*dst;
	int		i;

	i = 0;
	if (lineho > WIN_H)
		i = (lineho - WIN_H) / 2;
	while (i < lineho)
	{
		if (y1 >= WIN_H)
			break ;
		if ((game->castrays->ra >= 0 && game->castrays->ra <= 90.0)
			|| (game->castrays->ra >= 270.0 && game->castrays->ra <= 360.0))
			dst = game->we_texadr + (int)(i * (game->w_h / lineho))
				% game->w_h * game->line_length[3]
				+ (int)(x * game->w_w / 64) % game->w_w * (game->bits_per_pixel[3] / 8);
		if (game->castrays->ra >= 90.0 && game->castrays->ra <= 270.0)
			dst = game->ea_texadr + (int)(i * (game->e_h / lineho))
				% game->e_h * game->line_length[4]
				+ (int)(x * game->e_w / 64) % game->e_w * (game->bits_per_pixel[4] / 8);
		my_mlx_pixel_put(game, game->i2, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

float fixang(float ang)
{
    if (ang < 0)
        ang += 360.0;
    if (ang > 360.0)
        ang -= 360.0;
    return (ang);
}

void	ft_drawfloor(t_game *game, float lineh, float lineo)
{
	int		j;

	j = (int)(lineh + lineo);
	while (j < WIN_H)
	{
		my_mlx_pixel_put(game, game->i2, j, game->parse->F_RGB);
		j++;
	}
}
void	ft_drawceilling(t_game *game, float lineo)
{
	int	i;

	i = 0;
	while (i < lineo)
	{
		my_mlx_pixel_put(game, game->i2, i, game->parse->C_RGB);
		i++;
	}
}
float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

void convert_3d(t_game *game, int check)
{
    float lineo;
    float lenn;
    float wall_h = fixang(game->player->angle - game->castrays->ra); /* (WIN_W / 2) / (game->castrays->ra);*/
    // int wall_strip_h = (int)(wall_h);
    // int wall_top_px = (WIN_H / 2) - (wall_strip_h / 2);
    // int wall_bottom_px = (WIN_H / 2) + (wall_strip_h / 2);
    // int wall_strip_h = (int)(64 / wall_h * 277);
    // int wall_top_px = (WIN_H / 2) - (wall_strip_h / 2);
    // int wall_bottom_px = (WIN_H / 2) + (wall_strip_h / 2);
    float len = dist(game->player->x, game->player->y, game->castrays->rx, game->castrays->ry);
    len = len * cos(degtorad(wall_h));
    lenn = (64 * WIN_H) / len;
    int tmp = lenn;
    int i = 0;
    if (lenn > WIN_H)
        lenn = WIN_H;
    lineo = (WIN_H / 2.0) - (lenn / 2.0);

    // castoneray(game);
    // while (i < WIN_H)
    // {
    //     if (i > lineo && i < (lineo + lenn))
    //     {
            if (check == 1)
                draw_ray(game, lineo, tmp, game->castrays->rx);
            else
                draw_ray2(game, lineo, tmp, game->castrays->ry);
                // my_mlx_pixel_put(game, game->i2, i, 0x808080);
        // }
        // i++;
    // }
    ft_drawfloor(game, lenn, lineo);
    ft_drawceilling(game, lineo);
}

void casting(t_game *game, float x, float y)
{
    while (1)
    {
        if (game->map->map[(int)(game->castrays->ry + y) / 64][(int)(game->castrays->rx / 64)] != '0')
        {
            if (game->map->map[(int)(game->castrays->ry + y) / 64][(int)(game->castrays->rx / 64)] == '1')
            {
                convert_3d(game, 1);
                return;
            }
        }
        if (game->map->map[(int)(game->castrays->ry / 64)][(int)(game->castrays->rx + x) / 64] != '0')
        {
            if (game->map->map[(int)(game->castrays->ry / 64)][(int)(game->castrays->rx + x) / 64] == '1')
            {
                convert_3d(game, 0);
                return ;
            }
        }
        game->castrays->ry += y / 4;
        game->castrays->rx += x / 4;
    }
}
void castoneray(t_game *game)
{
    float x;
    float y;

    game->castrays->ra = fixang(game->player->angle - 30.0);
    game->i2 = 0;
    while (game->i2 < WIN_W)
    {
        game->castrays->rx = game->player->x;
        game->castrays->ry = game->player->y;
        x = cos(degtorad(game->castrays->ra));
        y = sin(degtorad(game->castrays->ra));
        casting(game, x, y);
        game->i2++;
        game->castrays->ra += 60.0 / (WIN_W);
        game->castrays->ra = fixang(game->castrays->ra);
    }
}