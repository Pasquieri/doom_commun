/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:44:47 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/15 18:46:19 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		win_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (-1);
	env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "Doom-Nukem");
	env->m[0].img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	if (env->m[0].img == NULL)
		return (error_message(17, env));
	env->m[0].img_str = mlx_get_data_addr(env->m[0].img, &env->m[0].bpp,
			&env->m[0].s_l, &env->m[0].end);
	env->m[1].img = mlx_new_image(env->mlx, 200, 200);
	if (env->m[1].img == NULL)
		return (error_message(17, env));
	env->m[1].img_str = mlx_get_data_addr(env->m[1].img, &env->m[1].bpp,
			&env->m[1].s_l, &env->m[1].end);
	env->text[20].img = mlx_xpm_file_to_image(env->mlx,
			"textures/labo.XPM",
			&env->text[20].width, &env->text[20].height);
	if (init_texture(env) != 0)
		return (error_message(17, env));
	return (0);
}
