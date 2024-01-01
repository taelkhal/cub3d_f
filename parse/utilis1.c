/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:46:01 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/30 16:32:56 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	error_empty_line(void)
{
	ft_putstr_fd(RED"ERROR: empty map line\n", 2);
	exit(0);
}

void	error_invalid(void)
{
	ft_putstr_fd(RED"ERROR: INVALID (TEXTURE) (F) (C)\n", 2);
	exit(0);
}
