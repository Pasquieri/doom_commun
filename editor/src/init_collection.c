/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:14:08 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/28 19:34:44 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

t_collection			*free_collection(int size,
t_collection *collection, t_data_mlx data)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (collection[i].texture)
		{
			mlx_destroy_image(data.mlx_ptr, collection[i].texture->mlx_image);
			free(collection[i].texture);
		}
		i++;
	}
	free(collection);
	return (NULL);
}

static	t_img			*init_image_collection(int tex, t_data_mlx data)
{
	t_img	*img;
	t_point	xpm_size;

	img = NULL;
	xpm_size.x = 0;
	xpm_size.y = 0;
	if (!(img = (t_img*)malloc(sizeof(t_img) * 1)))
		return (NULL);
	if (!(img->mlx_image = init_xpm(tex, data, &xpm_size)))
		return (NULL);
	if (xpm_size.x == TILE && xpm_size.y == TILE)
		return (img);
	return (NULL);
}

t_collection			*init_collection(t_data_mlx data)
{
	int				i;
	t_collection	*collection;

	collection = NULL;
	i = 0;
	if (!(collection = (t_collection*)malloc(sizeof(t_collection) * 16 + 1)))
		return (NULL);
	while (i < 16)
	{
		collection[i] = (t_collection){FALSE, i, init_coord_collection(i),
		init_image_collection(i, data)};
		if (i == 15)
			collection[i].type = 16;
		if (!collection[i].texture)
			return (free_collection(i, collection, data));
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
		collection[i].texture->mlx_image,
		collection[i].coord.x, collection[i].coord.y);
		i++;
	}
	return (collection);
}
