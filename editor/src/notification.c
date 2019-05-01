/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:55:17 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/29 11:55:19 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	void	print_notif_error(t_data_mlx data, int error, t_point notif_pos)
{
	if (error == -1)
		mlx_string_put(data.mlx_ptr, data.mlx_win,
			notif_pos.x, notif_pos.y, 0xff0000,
			"Already defined");
	else if (error == -2)
		mlx_string_put(data.mlx_ptr, data.mlx_win,
			notif_pos.x, notif_pos.y, 0xff0000,
			"Only possible on floor");
	else if (error == -4)
		mlx_string_put(data.mlx_ptr, data.mlx_win,
			notif_pos.x, notif_pos.y, 0xff0000, "Begin undefined");
	else if (error == -5)
		mlx_string_put(data.mlx_ptr, data.mlx_win,
			notif_pos.x, notif_pos.y, 0xff0000, "End undefined");
	else if (error == -6)
		mlx_string_put(data.mlx_ptr, data.mlx_win,
			notif_pos.x, notif_pos.y, 0xff0000,
			"Begin & End undefined");
	else if (error == -7)
		mlx_string_put(data.mlx_ptr, data.mlx_win,
			notif_pos.x, notif_pos.y, 0xff0000, "Leave. Map can't be save");
}

void			clean_notification(t_data_mlx data)
{
	int x;
	int y;

	x = (GRID_SQUARE + (PADDING * 3));
	y = 390;
	while (y < 420)
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

void			print_notif(t_data_mlx data, int error_type)
{
	t_point notif_pos;

	clean_notification(data);
	if (error_type == -3)
		return ;
	notif_pos.x = GRID_SQUARE + (PADDING * 3);
	notif_pos.y = 390;
	if ((error_type <= -1 && error_type >= -2)
		|| (error_type <= -4 && error_type >= -7))
		print_notif_error(data, error_type, notif_pos);
}
