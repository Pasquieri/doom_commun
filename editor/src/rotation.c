/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:52:45 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:36 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	int	dist_to_right(t_tile **tiles, t_point player_position)
{
	int i;

	i = player_position.x + 1;
	while (i < GRID_SIZE)
	{
		if (tiles[player_position.y][i].type != 0)
			return (i - player_position.x);
		i++;
	}
	return (0);
}

static	int	dist_to_left(t_tile **tiles, t_point player_position)
{
	int i;

	i = player_position.x - 1;
	while (i >= 0)
	{
		if (tiles[player_position.y][i].type != 0)
			return (player_position.x - i);
		i--;
	}
	return (0);
}

static	int	dist_to_bottom(t_tile **tiles, t_point player_position)
{
	int i;

	i = player_position.y + 1;
	while (i < GRID_SIZE)
	{
		if (tiles[i][player_position.x].type != 0)
			return (i - player_position.y);
		i++;
	}
	return (0);
}

static	int	dist_to_top(t_tile **tiles, t_point player_position)
{
	int i;

	i = player_position.y - 1;
	while (i >= 0)
	{
		if (tiles[i][player_position.x].type != 0)
			return (player_position.y - i);
		i--;
	}
	return (0);
}

int			calc_rotation(t_tile **tiles, t_point player_position)
{
	int right;
	int top;
	int left;
	int bottom;

	right = dist_to_right(tiles, player_position);
	left = dist_to_left(tiles, player_position);
	top = dist_to_top(tiles, player_position);
	bottom = dist_to_bottom(tiles, player_position);
	if (right >= left && right >= top && right >= bottom)
		return (360);
	else if (left >= right && left >= top && left >= bottom)
		return (180);
	else if (top >= right && top >= left && top >= bottom)
		return (90);
	else if (bottom >= right && bottom >= left && bottom >= top)
		return (270);
	return (1);
}
