/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:32:20 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/20 15:43:18 by cpalmier         ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	int				size;
	unsigned int	nb;

	nb = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	size = ft_size(nb);
	while (size)
	{
		ft_putchar_fd((nb / size) + 48, fd);
		nb = nb % size;
		size = size / 10;
	}
}
