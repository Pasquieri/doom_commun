/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_selection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:20:41 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 17:04:04 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	void	draw_select(t_editor *editor, t_point coord, int color)
{
	int i;

	i = 0;
	while (i < TILE + 4)
	{
		mlx_pixel_put(editor->data.mlx_ptr, editor->data.mlx_win,
			coord.x - 2 + i, coord.y - 2, color);
		mlx_pixel_put(editor->data.mlx_ptr, editor->data.mlx_win,
			coord.x - 2, coord.y - 2 + i, color);
		mlx_pixel_put(editor->data.mlx_ptr, editor->data.mlx_win,
			coord.x - 2 + i, coord.y - 2 + TILE + 3, color);
		mlx_pixel_put(editor->data.mlx_ptr, editor->data.mlx_win,
			coord.x - 2 + TILE + 3, coord.y - 2 + i, color);
		i++;
	}
}

static	void	clean_selected(t_editor *editor, t_collection *collection)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (collection[i].selected)
			draw_select(editor, collection[i].coord, 0x000000);
		collection[i].selected = FALSE;
		i++;
	}
}

int				select_type_collection(t_point coord, t_collection *collection)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (coord.x >= collection[i].coord.x
			&& coord.x <= collection[i].coord.x
			+ TILE && coord.y >= collection[i].coord.y
			&& coord.y <= collection[i].coord.y + TILE)
			return (i);
		i++;
	}
	return (-1);
}

int				get_type_selected(t_collection *collection)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (collection[i].selected)
			return (collection[i].type);
		i++;
	}
	return (-1);
}

void			handle_selection(t_editor *editor, t_point coord)
{
	int index;

	index = -1;
	if ((index = select_type_collection(coord, editor->collection)) == -1)
		return ;
	if (editor->collection[index].selected)
		return ;
	else
	{
		clean_selected(editor, editor->collection);
		editor->collection[index].selected = TRUE;
		draw_select(editor, editor->collection[index].coord, 0xffffff);
	}
}
