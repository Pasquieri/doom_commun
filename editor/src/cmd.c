/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:52:27 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:51:58 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

void	print_cmd_user(t_data_mlx data)
{
	mlx_string_put(data.mlx_ptr, data.mlx_win, (GRID_SQUARE + (PADDING * 2))
		+ (280 - 12) / 4.5, 12, 0x3273DC, "COMMAND");
	mlx_string_put(data.mlx_ptr, data.mlx_win,
		(GRID_SQUARE + (PADDING * 3)), 12 * 4, 0xFFFFFF, "Esc: quit");
	mlx_string_put(data.mlx_ptr, data.mlx_win,
		(GRID_SQUARE + (PADDING * 3)), 12 * 6, 0xFFFFFF, "L-click: add");
	mlx_string_put(data.mlx_ptr, data.mlx_win,
		(GRID_SQUARE + (PADDING * 3)), 12 * 8, 0xFFFFFF, "R-click: remove");
	mlx_string_put(data.mlx_ptr, data.mlx_win,
		(GRID_SQUARE + (PADDING * 3)), 12 * 10, 0xFFFFFF, "Delete: Reset");
	mlx_string_put(data.mlx_ptr, data.mlx_win,
		(GRID_SQUARE + (PADDING * 3)), 12 * 12, 0xFFFFFF,
		"Return: Save and quit");
	mlx_string_put(data.mlx_ptr, data.mlx_win, (GRID_SQUARE + (PADDING * 3)),
		12 * 14, 0xFFFFFF, "Tab: Change music");
}

void	print_info_collecton(t_data_mlx data)
{
	mlx_string_put(data.mlx_ptr, data.mlx_win, (GRID_SQUARE + (PADDING * 2))
		+ (280 - 12) / 4.5, 475, 0x3273DC, "SELECTION");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2 + 60,
		FLOOR_POSITION, 0xFFFFFF, "Floor:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2 + 70,
		WALL_POSITION, 0xFFFFFF, "Wall:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2,
		WALL_PICTURE_POSITION, 0xFFFFFF, "WallPicture:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2 + 70,
		DOOR_POSITION, 0xFFFFFF, "Door:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2,
		BEGIN_END_POSITION, 0xFFFFFF, "Begin / End:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2,
		TRANSPARENT_POSITION, 0xFFFFFF, "Transparent:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2 + 50,
		COLUMN_POSITION, 0xFFFFFF, "Column:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2 + 50,
		BANANA_POSITION, 0xFFFFFF, "Banana:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2 + 50,
		MONKEY_POSITION, 0xFFFFFF, "Monkey:");
	mlx_string_put(data.mlx_ptr, data.mlx_win, GRID_SQUARE + PADDING * 2 + 40,
		SYRINGE_POSITION, 0xFFFFFF, "Syringe:");
}

void	print_cmd(t_data_mlx data)
{
	print_cmd_user(data);
	print_info_collecton(data);
	mlx_string_put(data.mlx_ptr, data.mlx_win, (GRID_SQUARE
			+ (PADDING * 2)) + (280 - 12) / 4.5, 220, 0x3273DC, "MUSIC");
	mlx_string_put(data.mlx_ptr, data.mlx_win, (GRID_SQUARE + (PADDING * 2))
		+ (280 - 12) / 4.5, 320, 0x3273DC, "NOTIFICATION");
}

void	clean_music(t_data_mlx data)
{
	int x;
	int y;

	x = (GRID_SQUARE + (PADDING * 3));
	y = 270;
	while (y < 300)
	{
		x = (GRID_SQUARE + (PADDING * 3));
		while (x < WIDTH)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	print_music(t_data_mlx data, int music)
{
	char tmp;

	tmp = music + '0';
	clean_music(data);
	mlx_string_put(data.mlx_ptr, data.mlx_win, (GRID_SQUARE + (PADDING * 3)),
		270, 0xffffff, "Music: ");
	if (music >= 1 && music <= 7)
	{
		mlx_string_put(data.mlx_ptr, data.mlx_win,
			(GRID_SQUARE + (PADDING) + 100),
			270, 0xffffff, &tmp);
	}
}
