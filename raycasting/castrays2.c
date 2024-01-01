/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:05:10 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/31 15:07:32 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_tex(t_game *game, float y1, float line, float x)
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
		if (game->castrays->ra >= 180.0 && game->castrays->ra <= 360.0)
			dst = game->no_texadr + (int)(i * (game->n_h / line))
				% game->n_h * game->line_length[1]
				+ (int)(x * game->n_w / 64) % game->n_w * (game->bits_per_pixel[1] / 8);
		if (game->castrays->ra >= 0 && game->castrays->ra <= 180.0)
			dst = game->so_texadr + (int)(i * (game->s_h / line))
				% game->s_h * game->line_length[2]
				+ (int)(x * game->s_w / 64) % game->s_w * (game->bits_per_pixel[2] / 8);
		my_mlx_pixel_put(game, game->r, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}


void	draw_tex2(t_game *game, float y1, float lineho, float x)
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
		my_mlx_pixel_put(game, game->r, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

float fix_p_ang(float ang)
{
    if (ang < 0)
        ang += 360.0;
    if (ang > 360.0)
        ang -= 360.0;
    return (ang);
}