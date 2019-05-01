/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord_collection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 20:22:51 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/28 20:23:01 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	t_point			init_coord_collection_first_part(int tex)
{
	if (tex == 0)
	{
		return ((t_point){(GRID_SQUARE + (PADDING * 2) + 125),
			FLOOR_POSITION});
	}
	else if (tex >= 1 && tex <= 3)
	{
		return ((t_point){((GRID_SQUARE + (PADDING * 2) + 125)
				+ ((tex - 1) * TILE) + ((tex - 1) * PADDING)), WALL_POSITION});
	}
	else if (tex >= 4 && tex <= 6)
	{
		return ((t_point){((GRID_SQUARE + (PADDING * 2) + 125)
		+ ((tex - 4) * TILE) + ((tex - 4) * PADDING)), WALL_PICTURE_POSITION});
	}
	else if (tex == 7)
		return ((t_point){(GRID_SQUARE + (PADDING * 2) + 125), DOOR_POSITION});
	else if (tex == 8 || tex == 9)
	{
		return ((t_point){((GRID_SQUARE + (PADDING * 2) + 125)
			+ ((tex - 8) * TILE) + ((tex - 8) * PADDING)), BEGIN_END_POSITION});
	}
	return ((t_point){0, 0});
}

static	t_point			init_coord_collection_last_part(int tex)
{
	if (tex == 10 || tex == 11)
	{
		return ((t_point){((GRID_SQUARE + (PADDING * 2) + 125)
		+ ((tex - 10) * TILE) + ((tex - 10) * PADDING)), TRANSPARENT_POSITION});
	}
	else if (tex == 12)
	{
		return ((t_point){(GRID_SQUARE + (PADDING * 2) + 125),
			COLUMN_POSITION});
	}
	else if (tex == 13)
	{
		return ((t_point){(GRID_SQUARE + (PADDING * 2) + 125),
			BANANA_POSITION});
	}
	else if (tex == 14)
	{
		return ((t_point){(GRID_SQUARE + (PADDING * 2) + 125),
			MONKEY_POSITION});
	}
	return ((t_point){0, 0});
}

t_point					init_coord_collection(int tex)
{
	if (tex >= 0 && tex <= 9)
		return (init_coord_collection_first_part(tex));
	else if (tex >= 10 && tex <= 14)
		return (init_coord_collection_last_part(tex));
	else if (tex == 15)
	{
		return ((t_point){(GRID_SQUARE + (PADDING * 2) + 125),
			SYRINGE_POSITION});
	}
	return ((t_point){0, 0});
}
