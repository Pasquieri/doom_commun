/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:41:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/29 13:12:42 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int			key_press(int key, t_env *env) // il faut reduire la vitesse de deplacement pendant le saut
{
	env->key[key] = 1;
	if (env->key[4] == 1)
		env->h_help = env->h_help == 0 ? 1 : 0;
	if (env->key[53])
	{
		system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
		exit(0);
	}
	if (env->key[16] && !env->menu)
	{
		if (env->h_story != 0)
			ft_play_music(env->musique, ' ');
		env->h_story = 0;
	}
	if (env->key[29] && !env->menu && env->h_end == 0)
		env->lum_int = 370;
	if (env->key[25] && !env->menu && env->h_end == 0)
		env->lum_int = 25;
	if (env->key[257] && !env->menu)
		env->vitesse = SPEED * 2;
	if (env->key[83] && !env->menu && env->jump == 0 && env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 1;
	else if (env->key[84] && !env->menu && env->jump == 0 && env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 3;
	else if (env->key[85] && !env->menu && env->jump == 0 && env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 5;
	else if (env->key[86] && !env->menu && env->jump == 0 && env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 7;
	if (env->key[15] && env->h_jump + 100 < (env->d_ecran * env->h_mur) / 2 && env->coef_h_wall == 1)
		env->h_jump += 100;
	if (env->key[3] && env->h_jump - 100 > (env->d_ecran * env->h_mur) / -2 && env->coef_h_wall == 1)
		env->h_jump -= 100;
	if (env->key[49] && !env->menu && env->jump == 0 && env->crouch == 0 && env->coef_h_wall == 1)
	{
		if (env->key[13])
			env->jump_move = 13;
		else if (env->key[1])
			env->jump_move = 1;
		else if (env->key[0])
			env->jump_move = 0;
		else if (env->key[2])
		env->jump_move = 2;
		env->jump = 1;
	}
	if (env->key[8] && !env->menu && (env->crouch == 0 || env->crouch == -2) && env->jump == 0 && env->coef_h_wall == 1 && env->h_jump <= 0)
	{
		if (env->key[13])
			env->jump_move = 13;
		else if (env->key[1])
			env->jump_move = 1;
		else if (env->key[0])
			env->jump_move = 0;
		else if (env->key[2])
			env->jump_move = 2;
		if (env->crouch == 0)
			env->crouch = -1;
		else if (env->crouch == -2)
			env->crouch = 1;
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
	if ((key == 18 || key == 19) && !env->menu)
	{
		if (env->skybox != 22 && key == 18)
			env->skybox = 22;
		else if (key == 18)
			env->skybox = 0;
	}
	if (key == 37 && env->gun == 1 && !env->menu && env->h_ammo > 0) // coup de feu : key l
	{
		print_gun(env, 5);
		mlx_put_image_to_window(env->mlx,env->win,env->m[0].img, 0,0);
		mlx_put_image_to_window(env->mlx,env->win,env->m[1].img, 960,20);
		print_hub(env);
		system("/usr/bin/afplay -q 1 src/song/fire.mp3&");
		env->h_ammo--;
	}
	if (key == 40 && !env->menu && env->h_end == 0) // pour afficher le gun : key k
	{
		if (env->gun == 0)
			env->gun = 1;
		else
			env->gun = 0;
	}
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

