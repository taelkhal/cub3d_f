/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:44:39 by amakhrou          #+#    #+#             */
/*   Updated: 2024/01/01 15:49:35 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/cub3D.h"

void	error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void    destroy_textures(t_game *game)
{
    mlx_destroy_image(game->mlx, game->no_tex);
    mlx_destroy_image(game->mlx, game->so_tex);
    mlx_destroy_image(game->mlx, game->ea_tex);
    mlx_destroy_image(game->mlx, game->we_tex);
}

void    free_exit(t_game *game, int status)
{
    if (status)
        ft_putstr_fd("ERROR\n", 2);
    if (game->mlx)
    {
        if (game->img)
            mlx_destroy_image(game->mlx, game->img);
        mlx_destroy_window(game->mlx, game->win);
        destroy_textures(game);
        free(game->mlx);
    }
    // free_parsing(game->pars);
    free(game);
    exit(status);
}

int free_structs(t_game *game)
{
    free_exit(game, 0);
    return (0);
}
void	get_path(t_game *g)
{
	g->no_tex = mlx_xpm_file_to_image(g->mlx, g->parse->NO_tex, &g->n_w, &g->n_h);
	if (!g->no_tex)
		error_msg(RED"invalid north texture\n");
	g->we_tex = mlx_xpm_file_to_image(g->mlx, g->parse->WE_tex, &g->w_w, &g->w_h);
	if (!g->we_tex)
		error_msg(RED"invalid west texture\n");
	g->so_tex = mlx_xpm_file_to_image(g->mlx, g->parse->SO_tex, &g->s_w, &g->s_h);
	if (!g->so_tex)
		error_msg(RED"invalid south texture\n");
	g->ea_tex = mlx_xpm_file_to_image(g->mlx, g->parse->EA_tex, &g->e_w, &g->e_h);
	if (!g->ea_tex)
		error_msg(RED"invalid east texture\n");
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

// void	mlx_clear_image(t_game *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->map->width * 64)
//     {
//         j = 0;
//         while (j < data->map->height * 64)
//         {
//             my_mlx_pixel_put(data, i, j, 0);
//             j++;
//         }
//         i++;
//     }
// }
int    game_loop(t_game *game)
{
    // mlx_clear_window(game->mlx, game->win);
    mlx_destroy_image(game->mlx, game->img);
    game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel[0], &game->line_length[0], &game->endian[0]);
    // draw_map(game);
    // mlx_clear_image(game);
    // draw_player(game, game->player->x, game->player->y);
    // draw_thick_line(game, game->player->x, game->player->y, game->player->x + game->player->pdx * 5, game->player->y + game->player->pdy * 5, 0x0000FF);
    castoneray(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}
int key_hook(t_game *game)
{
    int check;

    check = 0;
    if (game->turn_left == 1)
        turn_left(game);
    if (game->turn_right == 1)
        turn_right(game);
    if (game->walk_left == 1)// Key A (Move left)
        move_left(game);
    if (game->walk_right == 1)// Key D (Move right)
        move_right(game);
    if (game->walk_up == 1)// Key W (Move forward)
        check = move_up(game, check);
    if (game->walk_down == 1)// Key S (Move backward)
        check = move_down(game, check);
    game_loop(game);
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
    get_path(game);
    get_angle(game);
    mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
    mlx_hook(game->win, 6, 1L << 6, mouse_hook, game);
    mlx_hook(game->win, 17, 0, free_structs, game);
    mlx_loop_hook(game->mlx, key_hook, game);
    mlx_loop(game->mlx);
}