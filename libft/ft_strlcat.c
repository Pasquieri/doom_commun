/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:14:36 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/22 16:13:43 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	ret = i;
	while (i < size - 1 && src[j] != '\0' && size > 0)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
	ret += ft_strlen(src);
	return (ret);
}
