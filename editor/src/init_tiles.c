/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:21:54 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:11 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	t_point		init_tile_coord(t_point point)
{
	t_point new;

	new.x = point.x * TILE;
	new.y = point.y * TILE;
	return (new);
}

t_tile				**free_tiles(t_tile **tiles, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tiles[i]);
		i++;
	}
	free(tiles);
	tiles = NULL;
	return (NULL);
}

int					init_type_tile(int x, int y)
{
	int type;

	type = 0;
	if (x == 0 || y == 0 || y == GRID_SIZE - 1 || x == GRID_SIZE - 1)
		type = 1;
	else
		type = 0;
	return (type);
}

t_tile				**init_tiles(void)
{
	t_point	point;
	t_tile	**tiles;
	int		type;

	tiles = NULL;
	type = 0;
	point.y = 0;
	if (!(tiles = (t_tile **)malloc(sizeof(t_tile *) * GRID_SIZE + 1)))
		return (NULL);
	while (point.y < GRID_SIZE)
	{
		point.x = 0;
		if (!(tiles[point.y] = (t_tile *)malloc(sizeof(t_tile)
					* GRID_SIZE + 1)))
			return (free_tiles(tiles, point.y + 1));
		while (point.x < GRID_SIZE)
		{
			type = init_type_tile(point.x, point.y);
			tiles[point.y][point.x] = (t_tile){type, init_tile_coord(point)};
			point.x++;
		}
		point.y++;
	}
	return (tiles);
}
