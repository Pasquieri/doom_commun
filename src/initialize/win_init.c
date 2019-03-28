/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:44:47 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/27 17:46:20 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		win_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (-1);
	env->win = mlx_new_window(env->mlx, 1200, 870, "Wolf3D");
	env->m[0].img = mlx_new_image(env->mlx, 1200, 870);
	env->m[0].img_str = mlx_get_data_addr(env->m[0].img, &env->m[0].bpp,
			&env->m[0].s_l, &env->m[0].end);
	env->m[1].img = mlx_new_image(env->mlx, 200, 200);
	env->m[1].img_str = mlx_get_data_addr(env->m[1].img, &env->m[1].bpp,
			&env->m[1].s_l, &env->m[1].end);
	env->text[20].img = mlx_xpm_file_to_image(env->mlx,"textures/20-labyrinthe.XPM",
			&env->text[20].width, &env->text[20].height);
	env->text[20].img_str = mlx_get_data_addr(env->text[20].img,
		&env->text[20].bpp, &env->text[20].s_l, &env->text[20].end);
	init_texture(env);
	return (0);
}
