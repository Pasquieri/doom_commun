/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:52:31 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:56:19 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

void			error_file(int error_code)
{
	if (error_code <= -110 && error_code >= -120)
	{
		ft_putendl("First line of the file map should contain \
\"player(x, y, rotation)\"");
		ft_putendl("x: integer(1-39)\ty: integer(1-39)\t \
rotation: integer(0-360)");
	}
	else if (error_code <= -121 && error_code >= -123)
	{
		ft_putendl("Second line of the file map should contain \"music\"");
		ft_putendl("music: integer(1-7)");
	}
	else if (error_code <= -124 && error_code >= -134)
	{
		ft_putendl("From third line to the last of the file should contain\
	\"map\"");
		ft_putendl("Map:");
		ft_putendl("- 40 line of 40 values");
		ft_putendl("value: integer(0 - 14 & 16) seperate by space");
		ft_putendl("- delimited by wall");
		ft_putendl("wall: integer(1)");
		ft_putendl("- 1 begin (should correspond to player position)");
		ft_putendl("begin: integer(8)");
	}
}

static	void	free_error(int error, t_editor *editor)
{
	if (error <= -1 && editor->file.file)
		free_double_tab(editor->file.file);
	if (error <= -3 && editor->collection)
		free_collection(16, editor->collection, editor->data);
	if (error <= -4 && editor->tiles)
		free_tiles(editor->tiles, GRID_SIZE);
}

int				error(int error_code, t_editor *editor)
{
	ft_putstr("Error[");
	ft_putnbr(error_code);
	ft_putstr("]\n");
	if (error_code <= -110 && error_code >= -134)
		error_file(error_code);
	if (error_code <= -1 && error_code >= -5)
		free_error(error_code, editor);
	if (error_code == -1)
		ft_putendl("Error on initialization of the window");
	if (error_code == -2)
		ft_putendl("Error on initialization of collection");
	if (error_code == -3)
		ft_putendl("Error on initialization of map");
	if (error_code == -4)
		ft_putendl("Error on initialization of grid");
	if (error_code == -5)
		ft_putendl("Error when using collection into grid");
	exit(0);
	return (0);
}
