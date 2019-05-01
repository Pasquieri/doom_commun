/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:19:17 by mpasquie          #+#    #+#             */
/*   Updated: 2019/05/01 21:16:59 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	key_gun(int key, t_env *env)
{
	if (key == 258 && env->gun == 1 && !env->menu && env->h_ammo > 0)
	{
		print_gun(env, 5, 9);
		mlx_put_image_to_window(env->mlx, env->win, env->m[0].img, 0, 0);
		mlx_put_image_to_window(env->mlx, env->win, env->m[1].img, 960, 20);
		print_hub(env);
		system("/usr/bin/afplay -q 1 src/song/fire.mp3&");
		env->h_ammo--;
	}
	if (key == 40 && !env->menu && env->h_end == 0)
	{
		if (env->gun == 0)
			env->gun = 1;
		else
			env->gun = 0;
	}
}

static int	key_release_menu(int key, t_env *env)
{
	if (key == 36 || key == 76)
	{
		if ((key == 36 || key == 76) && !env->menu)
		{
			open_menu(env);
			env->menu = 1;
			return (1);
		}
		else if ((key == 36 || key == 76) && env->menu && env->map_entree == -1)
			key_invalid_menu(env);
		else if ((key == 36 || key == 76) && env->menu && env->map_entree != -1)
			key_valid_menu(env);
	}
	return (0);
}

int			key_release(int key, t_env *env)
{
	env->key[key] = 0;
	if (key == 257 && !env->menu)
		env->vitesse = SPEED;
	if (key == 14 && !env->menu)
		deal_door(env);
	if (key == 12 && !env->menu)
		deal_tab(env);
	if (key_release_menu(key, env) == 1)
		return (0);
	if ((key == 18 || key == 19) && !env->menu)
	{
		if (env->skybox != 22 && key == 18)
			env->skybox = 22;
		else if (key == 18)
			env->skybox = 0;
	}
	key_gun(key, env);
	return (0);
}
