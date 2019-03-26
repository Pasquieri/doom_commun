/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:12:42 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/20 15:43:10 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int nb)
{
	int	size;

	size = 1;
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		size = size * 10;
	}
	return (size);
}

void		ft_putnbr(int n)
{
	int				size;
	unsigned int	nb;

	nb = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	size = ft_size(nb);
	while (size)
	{
		ft_putchar((nb / size) + 48);
		nb = nb % size;
		size = size / 10;
	}
}
