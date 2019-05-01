/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:51:38 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:54:32 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

int		end(t_editor *editor)
{
	if (editor->file.file)
		free_double_tab(editor->file.file);
	if (editor->tiles)
		free_tiles(editor->tiles, GRID_SIZE);
	if (editor->collection)
		free_collection(16, editor->collection, editor->data);
	editor->tiles = NULL;
	editor->collection = NULL;
	editor->file.file = NULL;
	exit(0);
}
