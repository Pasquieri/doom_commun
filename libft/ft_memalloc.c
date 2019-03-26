/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:49:49 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/20 12:37:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = NULL;
	mem = (void *)malloc(sizeof(void) * size);
	if (mem == NULL)
		return (NULL);
	mem = ft_memset(mem, 0, size);
	return (mem);
}
