/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_end_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:45:14 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:42 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	int		count_by_type(t_tile **tiles, int type)
{
	int y;
	int x;
	int count;

	count = 0;
	y = 0;
	while (y < GRID_SIZE)
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			if (tiles[y][x].type == type)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static	void	check_begin_end(t_tile **tiles, int *error)
{
	if (count_by_type(tiles, BEGIN) != 1)
		*error = -4;
	if (count_by_type(tiles, END) < 1)
		*error = (*error == -4) ? -6 : -5;
}

int				valid_map(t_editor *editor)
{
	t_point	point;
	int		error;

	error = 0;
	point.y = 0;
	while (point.y < GRID_SIZE)
	{
		point.x = 0;
		while (point.x < GRID_SIZE)
		{
			if (!check_border(editor->tiles[point.y][point.x].type,
			point.y, point.x))
				return (0);
			point.x++;
		}
		point.y++;
	}
	check_begin_end(editor->tiles, &error);
	if (error != 0)
		return (error);
	return (1);
}
