/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:43:46 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/28 22:43:48 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

int		click_release(int button, int x, int y, t_editor *editor)
{
	(void)x;
	(void)y;
	editor->loop = FALSE;
	editor->button = button;
	return (1);
}

int		click_press(int button, int x, int y, t_editor *editor)
{
	editor->loop = TRUE;
	editor->button = button;
	if ((x >= 1149 && x <= (1223 + TILE))
			&& (y >= 524 && y <= (857 + TILE)) && editor->button == 1)
		handle_selection(editor, (t_point){x, y});
	on_mouse_event(x, y, editor);
	return (TRUE);
}

void	coord_of_index_tiles(int x, int y, t_point *point, t_tile **tiles)
{
	point->x = tiles[(y - PADDING) / TILE][(x - PADDING) / TILE].coord.x
	+ PADDING;
	point->y = tiles[(y - PADDING) / TILE][(x - PADDING) / TILE].coord.y
	+ PADDING;
}

int		on_mouse_event(int x, int y, t_editor *editor)
{
	t_point point;

	if (editor->loop == 1)
	{
		if ((x > PADDING && x < (GRID_SQUARE + PADDING))
		&& y > (PADDING) && y < (GRID_SQUARE + PADDING))
		{
			coord_of_index_tiles(x, y, &point, editor->tiles);
			if (editor->button == 1)
			{
				add_selected_on_grid(point, editor,
				(t_point){((x - PADDING) / TILE), ((y - PADDING) / TILE)});
			}
			if (editor->button == 2)
				remove_on_grid(point, editor,
				(t_point){((x - PADDING) / TILE), ((y - PADDING) / TILE)});
		}
	}
	return (0);
}
