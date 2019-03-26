/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:41:32 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/20 15:48:11 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_size(unsigned int nb)
{
	int	size;

	size = 1;
	while (nb / 10 > 0)
	{
		nb /= 10;
		size *= 10;
	}
	return (size);
}

static char	*ft_malloc(int n, char *str)
{
	int				size;
	unsigned int	nb;

	nb = (unsigned int)n;
	size = 1;
	if (n < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb / 10 > 0)
	{
		nb /= 10;
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				size;
	int				i;
	unsigned int	nb;

	i = 0;
	nb = (unsigned int)n;
	str = NULL;
	str = ft_malloc(n, str);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		nb = -nb;
		str[i++] = '-';
	}
	size = ft_size(nb);
	while (size)
	{
		str[i++] = ((nb / size) + 48);
		nb = nb % size;
		size = size / 10;
	}
	str[i] = '\0';
	return (str);
}
