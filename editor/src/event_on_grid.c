/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_on_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:18:11 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 17:03:15 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	int		check_limit(int y, int x)
{
	if (x == 0 || y == 0 || x == GRID_SIZE - 1 || y == GRID_SIZE - 1)
		return (1);
	return (0);
}

void			add_selected_on_grid(t_point coord, t_editor *editor,
	t_point index_tile)
{
	int index;
	int type;

	if (check_limit(index_tile.y, index_tile.x))
		return ;
	if ((type = get_type_selected(editor->collection)) == -1)
		return ;
	if ((index = validate_compatibility(type,
					editor->tiles[index_tile.y][index_tile.x].type,
					editor->tiles)) < 0)
	{
		print_notif(editor->data, index);
		return ;
	}
	clean_notification(editor->data);
	editor->tiles[index_tile.y][index_tile.x].type = type;
	index = type;
	if (type == 16)
		index = 15;
	mlx_put_image_to_window(editor->data.mlx_ptr, editor->data.mlx_win,
	editor->collection[index].texture->mlx_image, coord.x, coord.y);
}

void			remove_on_grid(t_point coord, t_editor *editor,
	t_point index_tile)
{
	if (check_limit(index_tile.y, index_tile.x))
		return ;
	editor->tiles[index_tile.y][index_tile.x].type = 0;
	clean_notification(editor->data);
	mlx_put_image_to_window(editor->data.mlx_ptr, editor->data.mlx_win,
	editor->collection[FLOOR].texture->mlx_image, coord.x, coord.y);
}
