/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:42:02 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:14 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

void		on_music_key(int *music, t_data_mlx data)
{
	*music = *music + 1;
	if (*music == 8)
		*music = 1;
	print_music(data, *music);
}

static	int	middleware_end(t_editor *editor)
{
	int error;

	error = 0;
	if ((error = valid_map(editor)) != TRUE)
	{
		print_notif(editor->data, error);
		return (0);
	}
	if ((error = print_tiles(editor)) != TRUE)
	{
		print_notif(editor->data, error);
		return (0);
	}
	return (1);
}

int			on_key_event(int keycode, t_editor *editor)
{
	if (keycode == 36)
	{
		if (!middleware_end(editor))
			return (1);
		end(editor);
	}
	else if (keycode == 48)
		on_music_key(&editor->music, editor->data);
	else if (keycode == 51)
	{
		reset_tiles(editor->tiles);
		grid_collection(editor->data, editor->tiles, editor->collection);
	}
	else if (keycode == 53)
		end(editor);
	return (0);
}
