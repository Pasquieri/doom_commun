/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_event_on_grid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:30:08 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:46 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	int	validate_begin(t_tile **tiles)
{
	int i;
	int j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			if (tiles[i][j].type == BEGIN)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int			validate_compatibility(int type_collection, int type_tile,
	t_tile **tiles)
{
	if (type_collection == type_tile)
		return (-3);
	if (type_collection == BEGIN)
	{
		if (!validate_begin(tiles))
			return (-1);
	}
	if (type_collection == COLUMN
		|| type_collection == BANANA
		|| type_collection == MONKEY
		|| type_collection == BEGIN
		|| type_collection == END
		|| type_collection == 16)
	{
		if (type_tile != FLOOR)
			return (-2);
	}
	return (TRUE);
}
