  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:47:47 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/19 15:29:24 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "get_next_line/get_next_line.h" 

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
    int F_R;
    int F_G;
    int F_B;
    int C_R;
    int C_G;
    int C_B;
    // char **mapholder;

}   t_parse;

typedef struct s_map
{
    char **map;
}           t_map;

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
// void	parser(char *av,t_parse *parse, t_map *map);
			// if(ft_strlen(line) > parse->line_size)
			// 	parse->line_size = ft_strlen(line);

#endif