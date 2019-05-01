/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:52:46 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:03 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	void	limit_grid(t_img *img)
{
	int i;

	i = 0;
	while (i < GRID_SQUARE)
	{
		put_pixel_to_img(img, GRID_SQUARE, (t_point){i, 0}, 0xFFFFFF);
		put_pixel_to_img(img, GRID_SQUARE, (t_point){0, i}, 0xFFFFFF);
		put_pixel_to_img(img, GRID_SQUARE, (t_point){GRID_SQUARE - 1, i},
		0xFFFFFF);
		put_pixel_to_img(img, GRID_SQUARE, (t_point){i, GRID_SQUARE - 1},
		0xFFFFFF);
		i++;
	}
}

int				init_grid(t_data_mlx data, t_tile **tiles)
{
	int		i;
	int		j;
	t_img	img;

	i = 0;
	j = 0;
	if (!(init_image(&img, GRID_SQUARE, GRID_SQUARE, data)))
		return (FALSE);
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			put_pixel_to_img(&img, GRID_SQUARE, tiles[i][j].coord, 0xFFFFFF);
			j++;
		}
		i++;
	}
	limit_grid(&img);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img.mlx_image, PADDING,
		PADDING);
	mlx_destroy_image(data.mlx_ptr, img.mlx_image);
	return (TRUE);
}

int				grid_collection(t_data_mlx data, t_tile **tiles,
	t_collection *collection)
{
	int i;
	int j;
	int type;
	int index;

	type = 0;
	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			type = tiles[i][j].type;
			index = type;
			if (type == 16)
				index = 15;
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
					collection[index].texture->mlx_image,
					tiles[i][j].coord.x + PADDING,
					tiles[i][j].coord.y + PADDING);
			j++;
		}
		i++;
	}
	return (TRUE);
}
