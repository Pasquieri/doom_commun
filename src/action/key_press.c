/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:59:27 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/28 22:59:30 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void		key_press3(int key, t_env *env)
{
	if (env->key[53])
	{
		system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
		exit(0);
	}
	if (env->key[15] && env->h_jump + 100 < (env->d_ecran * env->h_mur) / 2
		&& env->coef_h_wall == 1)
		env->h_jump += 100;
	if (env->key[3] && env->h_jump - 100 > (env->d_ecran * env->h_mur) / -2
		&& env->coef_h_wall == 1)
		env->h_jump -= 100;
	if (env->key[49] && !env->menu && env->jump == 0 && env->crouch == 0
		&& env->coef_h_wall == 1)
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
	key = 0;
}

void		key_press2(int key, t_env *env)
{
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
	if (env->key[83] && !env->menu && env->jump == 0
		&& env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 1;
	else if (env->key[84] && !env->menu && env->jump == 0
		&& env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 3;
	else if (env->key[85] && !env->menu && env->jump == 0
		&& env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 5;
	else if (env->key[86] && !env->menu && env->jump == 0
		&& env->crouch == 0 && env->h_jump == 0)
		env->coef_h_wall = 7;
	key = 0;
}

int			key_press(int key, t_env *env)
{
	env->key[key] = 1;
	key_press2(key, env);
	key_press3(key, env);
	if (env->key[4] == 1)
		env->h_help = env->h_help == 0 ? 1 : 0;
	if (env->key[8] && !env->menu && (env->crouch == 0 || env->crouch == -2)
		&& env->jump == 0 && env->coef_h_wall == 1 && env->h_jump <= 0)
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
