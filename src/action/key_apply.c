/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:41:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/28 18:00:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void		key_release2(int key, t_env *env)
{
	if ((key == 18 || key == 19) && !env->menu)
	{
		if (env->skybox != 22 && key == 18)
			env->skybox = 22;
		else if (key == 18)
			env->skybox = 0;
	}
	if (key == 37 && env->gun == 1 && !env->menu && env->h_ammo > 0)
	{
		print_gun(env, 2);
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

int			key_release(int key, t_env *env)
{
	env->key[key] = 0;
	if (key == 257 && !env->menu)
		env->vitesse = SPEED;
	if (key == 14 && !env->menu)
		deal_door(env);
	if (key == 12 && !env->menu)
		deal_tab(env);
	if (key == 36 || key == 76)
	{
		if ((key == 36 || key == 76) && !env->menu)
		{
			open_menu(env);
			env->menu = 1;
			return (0);
		}
		else if ((key == 36 || key == 76) && env->menu && env->map_entree == -1)
			key_invalid_menu(env);
		else if ((key == 36 || key == 76) && env->menu && env->map_entree != -1)
			key_valid_menu(env);
	}
	key_release2(key, env);
	return (0);
}

static void	ft_arrow_menu(t_env *env)
{
	arrow_menu(env);
	env->key[125] = 0;
	env->key[126] = 0;
}

int			key_apply(t_env *env)
{
	if (env->jump != 0)
		ft_jump(env);
	else if (env->crouch == -1 || env->crouch == 1)
		ft_crouch(env);
	ft_monkey(env);
	env->time += 1;
	if (env->time > 10000)
		env->time = 1;
	if ((env->key[125] || env->key[126]) && env->menu == 1)
		ft_arrow_menu(env);
	if (!env->menu)
		trig_press(env);
	return (0);
}
