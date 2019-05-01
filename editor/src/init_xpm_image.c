/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:43:21 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/28 19:43:22 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	void	*init_xpm_first_part(int tex, t_data_mlx data,
t_point *xpm_size)
{
	if (tex == FLOOR)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr, "textures/floor.xpm",
		&xpm_size->x, &xpm_size->y));
	}
	else if (tex == W_GRAY)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr, "textures/grey_wall.xpm",
		&xpm_size->x, &xpm_size->y));
	}
	else if (tex == W_WHITE)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr, "textures/white_wall.xpm",
		&xpm_size->x, &xpm_size->y));
	}
	else if (tex == W_BLUE)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr, "textures/blue_wall.xpm",
		&xpm_size->x, &xpm_size->y));
	}
	return (NULL);
}

static	void	*init_xpm_second_part(int tex, t_data_mlx data,
t_point *xpm_size)
{
	if (tex == W_G_TAB)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/grey_wall_tab.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == W_W_TAB)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/white_wall_tab.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == W_B_TAB)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/blue_wall_tab.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == DOOR)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/door.xpm", &xpm_size->x, &xpm_size->y));
	}
	return (NULL);
}

static	void	*init_xpm_third_part(int tex, t_data_mlx data,
t_point *xpm_size)
{
	if (tex == BEGIN)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/perso.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == END)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/end.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == GRID)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/grid.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == WIN)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/window.xpm", &xpm_size->x, &xpm_size->y));
	}
	return (NULL);
}

static	void	*init_xpm_last_part(int tex, t_data_mlx data,
t_point *xpm_size)
{
	if (tex == COLUMN)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/column.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == BANANA)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/banane.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == MONKEY)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/monkey.xpm", &xpm_size->x, &xpm_size->y));
	}
	else if (tex == SYRINGE)
	{
		return (mlx_xpm_file_to_image(data.mlx_ptr,
		"textures/syringe.xpm", &xpm_size->x, &xpm_size->y));
	}
	return (NULL);
}

void			*init_xpm(int tex, t_data_mlx data, t_point *xpm_size)
{
	if (tex >= 0 && tex <= 3)
		return (init_xpm_first_part(tex, data, xpm_size));
	else if (tex >= 4 && tex <= 7)
		return (init_xpm_second_part(tex, data, xpm_size));
	else if (tex >= 8 && tex <= 11)
		return (init_xpm_third_part(tex, data, xpm_size));
	else if (tex >= 12 && tex <= 15)
		return (init_xpm_last_part(tex, data, xpm_size));
	return (NULL);
}
