/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pda_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:41:38 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/12/14 17:05:27 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pda_int(int **tab, int max_y, int max_x)
{
	int x;
	int y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			ft_putnbr(tab[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
