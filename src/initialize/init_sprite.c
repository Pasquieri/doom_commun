/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:48:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/28 18:02:11 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	init_sprite_extra(t_env *env)
{
	env->sp_t[5].img = mlx_xpm_file_to_image(env->mlx,
		"textures/7-door.XPM", &env->sp_t[5].width,
		&env->sp_t[5].height);
	env->sp_t[6].img = mlx_xpm_file_to_image(env->mlx,
		"textures/seringue.XPM", &env->sp_t[6].width, &env->sp_t[6].height);
	env->sp_t[7].img = mlx_xpm_file_to_image(env->mlx,
		"textures/4-5-6-van_gogh.XPM", &env->sp_t[7].width,
		&env->sp_t[7].height);
	env->sp_t[8].img = mlx_xpm_file_to_image(env->mlx,
		"textures/syringegun.xpm", &env->sp_t[8].width, &env->sp_t[8].height);
}

void		init_sprite(t_env *env)
{
	env->sp_t[0].img = mlx_xpm_file_to_image(env->mlx,
		"textures/8-grid.XPM", &env->sp_t[0].width, &env->sp_t[0].height);
	env->sp_t[1].img = mlx_xpm_file_to_image(env->mlx,
		"textures/9-win4.xpm", &env->sp_t[1].width, &env->sp_t[1].height);
	env->sp_t[2].img = mlx_xpm_file_to_image(env->mlx,
		"textures/12-column.XPM", &env->sp_t[2].width, &env->sp_t[2].height);
	env->sp_t[3].img = mlx_xpm_file_to_image(env->mlx,
		"textures/13-banana.XPM", &env->sp_t[3].width, &env->sp_t[3].height);
	env->sp_t[4].img = mlx_xpm_file_to_image(env->mlx,
		"textures/monkeymiddle.XPM", &env->sp_t[4].width, &env->sp_t[4].height);
	init_sprite_extra(env);
}
