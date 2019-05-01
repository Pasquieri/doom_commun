/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:49:29 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/29 12:49:32 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

void		print_player(t_tile **tiles, t_point player_position, int fd)
{
	ft_putstr_fd("player(", fd);
	ft_putnbr_fd(player_position.x, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(player_position.y, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(calc_rotation(tiles, player_position), fd);
	ft_putendl_fd(")", fd);
}

t_point		search_player(t_tile **tiles)
{
	int		i;
	int		j;
	t_point	player;

	player = (t_point){0, 0};
	i = 0;
	j = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			if (tiles[i][j].type == BEGIN)
			{
				player.y = i;
				player.x = j;
			}
			j++;
		}
		i++;
	}
	return (player);
}

static	int	get_write(t_editor *editor)
{
	if (!editor->file.file)
		editor->file.fd_write = 1;
	else
		editor->file.fd_write = open(editor->file.filename, O_TRUNC | O_WRONLY);
	if (editor->file.fd_write <= 0)
		return (0);
	return (1);
}

int			print_tiles(t_editor *editor)
{
	int i;
	int j;

	i = 0;
	if (!get_write(editor))
		return (-7);
	print_player(editor->tiles, search_player(editor->tiles),
		editor->file.fd_write);
	ft_putnbr_fd(editor->music, editor->file.fd_write);
	ft_putchar_fd('\n', editor->file.fd_write);
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			ft_putnbr_fd(editor->tiles[i][j].type, editor->file.fd_write);
			if (j < GRID_SIZE - 1)
				ft_putchar_fd(' ', editor->file.fd_write);
			j++;
		}
		ft_putchar_fd('\n', editor->file.fd_write);
		i++;
	}
	return (1);
}
