#ifndef CUB3D_H
# define CUB3D_H


# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../cub3D/minilibx-linux/mlx.h"
# include "../cub3D/get_next_line/get_next_line.h"
#define pi 3.1415926535
# define P_SPEED 5

# define WIN_W  1400
# define WIN_H  800
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
    // char **mapholder;

}   t_parse;


typedef struct s_map
{
    int width;
    int height;
    char **map;
}           t_map;

// typedef struct s_map
// {
//     int width;
//     int height;
//     char **map;
// }           t_map;

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
    int r;
    int mx;
    int my;
    int mp;
    int dof;
    float rx;
    float ry;
    float ra;
    float xo;
    float yo;
}t_castrays;

typedef struct s_game
{
    void *mlx;
    void *win;
    void *img;
    void *img_minimap;
    char *addr;
    char *addr_minimap;
    int i2;
    int    *bits_per_pixel;
    int   *line_length;
	int		*endian;
    int player_size;
    int size_px_map;
    int mouse;//bonus
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
char    **reads(t_parse *parse, int fd, int count);
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
// char *ft_strdup(const char *s1);
int ft_strcmp(const char *s1, const char *s2);
// size_t	ft_strlen(const char *str);
// char	*ft_strjoin(char *s1, char *s2);

char **read_map(char *path);
int lenth_width_map(char **map);
int lenth_height_map(char **map);
void draw_map(t_game *game);
void draw_player(t_game *game, int x, int y);
// int get_x_player(t_map *map);
int get_x_player(t_game *game);
// int get_y_player(t_map *map);
int get_y_player(t_game *game);
void draw_thick_line(t_game *game, int x1, int y1, int x2, int y2, int color);
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
//raycasting
void castoneray(t_game *game);
float degtorad(float angle);
void get_angle(t_game *game);
// void convert_3d(t_game *game, int x ,int y, int check);
void convert_3d(t_game *game, int check);

float fixang(float ang);
//bonus
// int mouse_hook(t_game *game, int x, int y);
int mouse_hook(int x, int y, t_game *game);
#endif