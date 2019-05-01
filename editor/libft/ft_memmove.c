/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:16:55 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/11/17 16:17:04 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	p_dest = dest;
	p_src = src;
	if (p_src <= p_dest)
	{
		while (n > 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
