/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:28:55 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/01 15:25:56 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int key_release(int key, t_game *game)
{
	if (key == 13)
		game->walk_up = 0;
	else if (key == 1)
		game->walk_down = 0;
	else if (key == 0)
		game->walk_left = 0;
	else if (key == 2)
		game->walk_right = 0;
	else if (key == 123)
		game->turn_left = 0;
	else if (key == 124)
		game->turn_right = 0;
	return (0);
}

int key_press(int key, t_game *game)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		game->walk_up = 1;
	else if (key == 1)
		game->walk_down = 1;
	else if (key == 0)
		game->walk_left = 1;
	else if (key == 2)
		game->walk_right = 1;
	else if (key == 123)
		game->turn_left = 1;
	else if (key == 124)
		game->turn_right = 1;
	return (0);
}