/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:22:56 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/13 13:37:05 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	ptr = (char *)b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	b = (void *)ptr;
	return (b);
}
