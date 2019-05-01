/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 00:12:08 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/12/14 20:41:29 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pda(char **tab, char separator)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar(separator);
		i++;
	}
}
