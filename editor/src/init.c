/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:52:50 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:52:47 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

int		init(int argc, char **argv, t_editor *editor)
{
	int ret;

	if (argc == 2)
		if ((ret = init_file(argv[1], editor)) != TRUE)
			return (error(ret, editor));
	if (!(init_window(&editor->data)))
		return (error(-1, editor));
	if (!(editor->collection = init_collection(editor->data)))
		return (error(-2, editor));
	if (!(editor->tiles = init_tiles()))
		return (error(-3, editor));
	if (!(init_grid(editor->data, editor->tiles)))
		return (error(-4, editor));
	if (!(grid_collection(editor->data, editor->tiles, editor->collection)))
		return (error(-5, editor));
	if (editor->file.file)
	{
		if (!(file_to_tiles(editor->file.file, editor->tiles)))
			return (FALSE);
		if (!(grid_collection(editor->data, editor->tiles,
				editor->collection)))
			return (error(-5, editor));
	}
	return (TRUE);
}

int		init_image(t_img *img, int width, int height, t_data_mlx data)
{
	if (!(img->mlx_image = mlx_new_image(data.mlx_ptr, width, height)))
		return (FALSE);
	img->data = (int*)mlx_get_data_addr(img->mlx_image,\
			&img->bpp, &img->sizeline, &img->endlian);
	return (TRUE);
}

int		init_window(t_data_mlx *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (FALSE);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
					"Level Editor")) == NULL)
		return (FALSE);
	return (TRUE);
}
