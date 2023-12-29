/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:44:39 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/18 20:44:39 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

static void    destroy_textures(t_game *data)
{
    mlx_destroy_image(data->mlx, data->no_tex);
    mlx_destroy_image(data->mlx, data->so_tex);
    mlx_destroy_image(data->mlx, data->ea_tex);
    mlx_destroy_image(data->mlx, data->we_tex);
}

void    free_exit(t_game *data, int status)
{
    if (status)
        ft_putstr_fd("ERROR\n", 2);
    if (data->mlx)
    {
        if (data->img)
            mlx_destroy_image(data->mlx, data->img);
        mlx_destroy_window(data->mlx, data->win);
        destroy_textures(data);
        free(data->mlx);
    }
    // free_parsing(data->pars);
    free(data);
    exit(status);
}

int free_structs(t_game *game)
{
    free_exit(game, 0);
    return (0);
}
void	get_path(t_game *g)
{
    printf ("NO_tex = %s\n", g->parse->NO_tex);
    printf ("SO_tex = %s\n", g->parse->SO_tex);
    printf ("WE_tex = %s\n", g->parse->WE_tex);
    printf ("EA_tex = %s\n", g->parse->EA_tex);
	g->no_tex = mlx_xpm_file_to_image(g->mlx, g->parse->NO_tex, &g->n_w, &g->n_h);
	if (!g->no_tex)
        printf("wrong texture path!!\n(north texture)\n");
	g->we_tex = mlx_xpm_file_to_image(g->mlx, g->parse->WE_tex, &g->w_w, &g->w_h);
	if (!g->we_tex)
        printf("wrong texture path!!\n(west texture)\n");
	g->so_tex = mlx_xpm_file_to_image(g->mlx, g->parse->SO_tex, &g->s_w, &g->s_h);
	if (!g->so_tex)
		printf("wrong texture path!!\n(south texture)\n");
	g->ea_tex = mlx_xpm_file_to_image(g->mlx, g->parse->EA_tex, &g->e_w, &g->e_h);
	if (!g->ea_tex)
		printf("wrong texture path!!\n(east texture)\n");
	g->no_texadr = mlx_get_data_addr(g->no_tex, &g->bits_per_pixel[1],
			&g->line_length[1], &g->endian[1]);
	g->so_texadr = mlx_get_data_addr(g->so_tex, &g->bits_per_pixel[2],
			&g->line_length[2], &g->endian[2]);
	g->we_texadr = mlx_get_data_addr(g->we_tex, &g->bits_per_pixel[3],
			&g->line_length[3], &g->endian[3]);
	g->ea_texadr = mlx_get_data_addr(g->ea_tex, &g->bits_per_pixel[4],
			&g->line_length[4], &g->endian[4]);
}

float degtorad(float angle)
{
    return (angle * (pi / 180));
}

void	mlx_clear_image(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->width * 64)
    {
        j = 0;
        while (j < data->map->height * 64)
        {
            my_mlx_pixel_put(data, i, j, 0);
            j++;
        }
        i++;
    }
}

int key_hook(int key, t_game *game)
{
    float new_angle;
    int check;

    check = 0;
    if (key == 65307)
        exit(0);
    if (key == 65361)
    {
        game->player->angle -= 3;
        if (game->player->angle < 0)
            game->player->angle += 360.0;
        game->player->pdx = cos(degtorad(game->player->angle)) * 5;
        game->player->pdy = sin(degtorad(game->player->angle)) * 5;
    }
    if (key == 65363)
    {
        game->player->angle += 3;
        if (game->player->angle > 360.0)
            game->player->angle -= 360.0;
        game->player->pdx = cos(degtorad(game->player->angle)) * 5;
        game->player->pdy = sin(degtorad(game->player->angle)) * 5;
    }
    if (key == 97)// Key A (Move left)
    {
        new_angle = game->player->angle - 90.0;
        if (new_angle < 0)
            new_angle += 360.0;
        if (game->map->map[(int)(game->player->y + sin(degtorad(new_angle)) * 5) / game->size_px_map]
        [(int)(game->player->x + cos(degtorad(new_angle)) * 5) / game->size_px_map] != '1')
        {
            game->player->x = game->player->x + cos(degtorad(new_angle)) * 5;
            game->player->y = game->player->y + sin(degtorad(new_angle)) * 5;
        }
    }
    if (key == 100)// Key D (Move right)
    {
        new_angle = game->player->angle + 90.0;
        if (new_angle > 360.0)
            new_angle -= 360.0;
        if (game->map->map[(int)(game->player->y + sin(degtorad(new_angle)) * 5) / game->size_px_map][(int)(game->player->x + cos(degtorad(new_angle)) * 5) / game->size_px_map] != '1')
        {
            game->player->x = game->player->x + cos(degtorad(new_angle)) * 5;
            game->player->y = game->player->y + sin(degtorad(new_angle)) * 5;
        }
    }
    if (key == 119)// Key W (Move forward)
    {
        if (check == 0)
        {
            game->player->pdx = cos(degtorad(game->player->angle)) * 5;
            game->player->pdy = sin(degtorad(game->player->angle)) * 5;
            check = 1;
        }
        if (game->map->map[(int)(game->player->y + game->player->pdy) / game->size_px_map][(int)(game->player->x + game->player->pdx) / game->size_px_map] != '1')
        {
            game->player->x = game->player->x + game->player->pdx;
            game->player->y = game->player->y + game->player->pdy;
        }
    }
    if (key == 115)// Key S (Move backward)
    {
        if (check == 0)
        {
            game->player->pdx = cos(degtorad(game->player->angle)) * 5;
            game->player->pdy = sin(degtorad(game->player->angle)) * 5;
            check = 1;
        }
        if (game->map->map[(int)(game->player->y - game->player->pdy) / game->size_px_map][(int)(game->player->x - game->player->pdx) / game->size_px_map] != '1')
        {
            game->player->x = game->player->x - game->player->pdx;
            game->player->y = game->player->y - game->player->pdy;
        }

    }
    return (0);
}
int    game_loop(t_game *game)
{
    // mlx_clear_window(game->mlx, game->win);
    mlx_destroy_image(game->mlx, game->img);
    game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel[0], &game->line_length[0], &game->endian[0]);
    // draw_map(game);
    // mlx_clear_image(game);
    // draw_player(game, game->player->x, game->player->y);
    // cast_horizontal_rays(game, game->castrays);
    // cast_vertical_rays(game, game->castrays);
    // draw_thick_line(game, game->player->x, game->player->y, game->player->x + game->player->pdx * 5, game->player->y + game->player->pdy * 5, 0x0000FF);
    castoneray(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}

int main(int ac, char **av)
{
    (void)ac;
    t_game *game;

    game = (t_game *)malloc(sizeof(t_game));
    init_game(game, av[1]);
    if (ac != 2)
        return (0);
	// printf ("%s\n", map->map[1]);
    get_path(game);
    get_angle(game);
    mlx_hook(game->win, 2, 1L << 0, key_hook, game);
    mlx_hook(game->win, 6, 1L << 6, mouse_hook, game);
    mlx_hook(game->win, 17, 0, NULL, 0);
    mlx_loop_hook(game->mlx, game_loop, game);
    mlx_loop(game->mlx);

}