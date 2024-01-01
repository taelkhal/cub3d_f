/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:47:47 by amakhrou          #+#    #+#             */
/*   Updated: 2024/01/01 18:21:20 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../parse/get_next_line/get_next_line.h"
# define pi 3.1415926535
# define P_SPEED 12

# define WIN_W  1080
# define WIN_H  720
# define RED    "\033[1m\033[31m"
# define GREEN    "\033[1m\033[32m"
# define YELLOW    "\033[1m\033[33m"

# define RED    "\033[1m\033[31m"
# define GREEN    "\033[1m\033[32m"
# define YELLOW    "\033[1m\033[33m"

typedef struct parse
{
    char *F_value;
    char *C_value;
    char *NO_tex;
    char *WE_tex;
    char *EA_tex;
    char *SO_tex;
	size_t  line_size;
    int F_RGB;
    int C_RGB;
    char **map_holder;
}   t_parse;


typedef struct s_map
{
    char **map;
}           t_map;

typedef struct s_player
{
    float x;
    float y;
    float pdx;
    float pdy;
    float angle;
}t_player;

typedef struct s_castrays
{
    float rx;
    float ry;
    float ra;
}t_castrays;

typedef struct s_game
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int r;
    int    *bits_per_pixel;
    int   *line_length;
	int		*endian;
    int player_size;
    int size_px_map;
    void	*no_tex;
	char	*no_texadr;
	int		n_w;
	int		n_h;
	void	*so_tex;
	char	*so_texadr;
	int		s_w;
	int		s_h;
	void	*we_tex;
	char	*we_texadr;
	int		w_w;
	int		w_h;
	void	*ea_tex;
	char	*ea_texadr;
	int		e_w;
	int		e_h;
    int mouse;
    int walk_left;
    int walk_right;
    int walk_up;
    int walk_down;
    int turn_left;
    int turn_right;
    t_parse *parse;
    t_map *map;
    t_player *player;
    t_castrays *castrays;

}t_game;

//parsing
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	line_is_empty_in(char *str);
int	c_w(char const *s1, char c1);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	tol(char **map);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
int	line_is_empty(char *str);
char	*check_texture_existence(char *path);
void    check_p(char **map);
void	check_x(char **map);
char	*check_texture_existence(char *path);
void    reads(t_parse *parse, int fd, int count);
t_map *init_map(char *path,t_parse *parse);
void init_parse(t_parse *parse);
int map_check(char **map, t_parse *parse);
void	rgb(t_parse *parse,char *str, char c);
t_map	*parser(char *path, t_parse *parse);
void	error_empty_line(void);
void	error_invalid(void);

//------------raycasting----------------
//init_structs
// t_map *init_map(char *path);
// t_player *init_player(t_map *map);
t_player *init_player(t_game *game);
// void init_game(t_game *game,t_map *map);
// void init_game(t_game *game,t_map *map, t_castrays *castrays);
void init_game(t_game *game, char *av);

//libft

void    ft_putstr(char *str, int fd);
char    **ft_split(char const *s, char c);
int ft_strcmp(const char *s1, const char *s2);

char **read_map(char *path);
// int lenth_width_map(char **map);
// int lenth_height_map(char **map);
void draw_map(t_game *game);
void draw_player(t_game *game, int x, int y);
int get_x_player(t_game *game);
int get_y_player(t_game *game);
void draw_thick_line(t_game *game, int x1, int y1, int x2, int y2, int color);
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);

// keys

int key_release(int key, t_game *game);
int key_press(int key, t_game *game);
//raycasting
void castoneray(t_game *game);
float degtorad(float angle);
void get_angle(t_game *game);
void convert_3d(t_game *game, int check);

//moves
void	turn_left(t_game *game);
void	turn_right(t_game *game);
int	move_up(t_game *game, int check);
int	move_down(t_game *game, int check);
void	move_right(t_game *game);
void	move_left(t_game *game);

float	calcul_dist(float ax, float ay, float bx, float by);
float fix_p_ang(float ang);
void	draw_tex(t_game *game, float y1, float line, float x);
void	draw_tex2(t_game *game, float y1, float lineho, float x);
void	draw_ceilling(t_game *game, float top_px);
void	draw_floor(t_game *game, float lineh, float bottom_px);
//bonus
// int mouse_hook(t_game *game, int x, int y);
int mouse_hook(int x, int y, t_game *game);
#endif