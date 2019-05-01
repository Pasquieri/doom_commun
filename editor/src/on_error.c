/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:22:34 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:56:53 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

int		err_free(char *to_free, int error)
{
	ft_strdel(&to_free);
	return (error);
}

int		err_free_dbl(char **tab, int size, int error)
{
	int i;

	i = -1;
	while (i++ < size)
		ft_strdel(&tab[i]);
	if (tab)
		free(tab);
	tab = NULL;
	return (error);
}
