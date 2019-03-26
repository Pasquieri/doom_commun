/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:15:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/19 16:48:09 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	init_texture(t_env *env)
{
	env->text[0].img = mlx_xpm_file_to_image(env->mlx,
		"textures/0-floor_labo.XPM", &env->text[0].width, &env->text[0].height);
	env->text[0].img_str = mlx_get_data_addr(env->text[0].img,
		&env->text[0].bpp, &env->text[0].s_l, &env->text[0].end);
	env->text[1].img = mlx_xpm_file_to_image(env->mlx,
		"textures/1-mur_gray.XPM", &env->text[1].width, &env->text[1].height);
	env->text[1].img_str = mlx_get_data_addr(env->text[1].img,
		&env->text[1].bpp, &env->text[1].s_l, &env->text[1].end);
	env->text[2].img = mlx_xpm_file_to_image(env->mlx,
		"textures/2-wall_white.XPM", &env->text[2].width, &env->text[2].height);
	env->text[2].img_str = mlx_get_data_addr(env->text[2].img,
		&env->text[2].bpp, &env->text[2].s_l, &env->text[2].end);
	env->text[3].img = mlx_xpm_file_to_image(env->mlx,
		"textures/3-wall_bleu.XPM", &env->text[3].width, &env->text[3].height);
	env->text[3].img_str = mlx_get_data_addr(env->text[3].img,
		&env->text[3].bpp, &env->text[3].s_l, &env->text[3].end);

	env->text[4].img = mlx_xpm_file_to_image(env->mlx,
		"textures/1-mur_gray.XPM", &env->text[4].width, &env->text[4].height);
	env->text[4].img_str = mlx_get_data_addr(env->text[4].img,
		&env->text[4].bpp, &env->text[4].s_l, &env->text[4].end);
	env->text[5].img = mlx_xpm_file_to_image(env->mlx,
		"textures/2-wall_white.XPM", &env->text[5].width, &env->text[5].height);
	env->text[5].img_str = mlx_get_data_addr(env->text[5].img,
		&env->text[5].bpp, &env->text[5].s_l, &env->text[5].end);
	env->text[6].img = mlx_xpm_file_to_image(env->mlx,
		"textures/3-wall_bleu.XPM", &env->text[6].width, &env->text[6].height);
	env->text[6].img_str = mlx_get_data_addr(env->text[6].img,
		&env->text[6].bpp, &env->text[6].s_l, &env->text[6].end);

	env->text[7].img = mlx_xpm_file_to_image(env->mlx,
		"textures/7-door.XPM", &env->text[7].width, &env->text[7].height);
	env->text[7].img_str = mlx_get_data_addr(env->text[7].img,
		&env->text[7].bpp, &env->text[7].s_l, &env->text[7].end);

	env->text[8].img = mlx_xpm_file_to_image(env->mlx,
		"textures/8-grid.XPM", &env->text[8].width, &env->text[8].height);
	env->text[8].img_str = mlx_get_data_addr(env->text[8].img,
		&env->text[8].bpp, &env->text[8].s_l, &env->text[8].end);
	env->text[9].img = mlx_xpm_file_to_image(env->mlx,
		"textures/9-window.XPM", &env->text[9].width, &env->text[9].height);
	env->text[9].img_str = mlx_get_data_addr(env->text[9].img,
		&env->text[9].bpp, &env->text[9].s_l, &env->text[9].end);
	env->text[12].img = mlx_xpm_file_to_image(env->mlx,
		"textures/12-column.XPM", &env->text[12].width, &env->text[12].height);
	env->text[12].img_str = mlx_get_data_addr(env->text[12].img,
		&env->text[12].bpp, &env->text[12].s_l, &env->text[12].end);
	env->text[14].img = mlx_xpm_file_to_image(env->mlx,
		"textures/14-monkey.XPM", &env->text[14].width, &env->text[14].height);
	env->text[14].img_str = mlx_get_data_addr(env->text[14].img,
		&env->text[14].bpp, &env->text[14].s_l, &env->text[14].end);

	env->text[21].img = mlx_xpm_file_to_image(env->mlx,
		"textures/21-plafond_white.XPM",
		&env->text[21].width, &env->text[21].height);
	env->text[21].img_str = mlx_get_data_addr(env->text[21].img,
		&env->text[21].bpp, &env->text[21].s_l, &env->text[21].end);
	env->text[22].img = mlx_xpm_file_to_image(env->mlx,
		"textures/22-sky.XPM", &env->text[22].width, &env->text[22].height);
	env->text[22].img_str = mlx_get_data_addr(env->text[22].img,
		&env->text[22].bpp, &env->text[22].s_l, &env->text[22].end);
}
