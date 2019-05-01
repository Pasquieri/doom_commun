/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:09:13 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/11/17 16:41:30 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	new = NULL;
	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
