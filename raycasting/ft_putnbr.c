/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:43:21 by marvin            #+#    #+#             */
/*   Updated: 2023/01/09 19:43:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    long int nbr;

    nbr = nb;
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = nbr * -1;
    }
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putchar (nbr % 10 + 48);
    }
    else
        ft_putchar(nbr + 48);
}