/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_crouch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:34:26 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/30 21:39:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	jump_hup(t_env *env, int jump_height)
{
	if (env->jump >= 1)
	{
		env->jump = 0;
		if (env->h_jump + jump_height < 15 * jump_height)
		{
			if (env->jump_move != -1)
			{
				if (env->jump_move == 1 || env->jump_move == 13)
					depla_vertical(env, env->jump_move);
				else if (env->jump_move == 0 || env->jump_move == 2)
					depla_horizontal(env, env->jump_move);
			}
			env->h_jump += jump_height;
		}
		else
			env->jump = -2;
	}
	env->jump = env->jump + 1;
}

void	jump_down(t_env *env, int jump_height)
{
	env->jump = 0;
	if (env->h_jump - jump_height > 0)
	{
		if (env->jump_move != -1)
		{
			if (env->jump_move == 1 || env->jump_move == 13)
				depla_vertical(env, env->jump_move);
			else if (env->jump_move == 0 || env->jump_move == 2)
				depla_horizontal(env, env->jump_move);
		}
		env->h_jump -= jump_height;
	}
	else
	{
		env->jump = 1;
		env->h_jump = 0;
		env->vitesse *= 2;
		env->jump_move = -1;
	}
	env->jump = env->jump - 1;
}

void	ft_jump(t_env *env)
{
	int jump_height;

	env->vitesse = 0.5;
	jump_height = 100;
	if (env->jump > 0)
		jump_hup(env, jump_height);
	if (env->jump < 0)
		jump_down(env, jump_height);
}

void	ft_crouch(t_env *env)
{
	int h_crouch_height;

	h_crouch_height = 50;
	env->vitesse = 0.5;
	if (env->crouch == -1)
	{
		if (env->h_jump - h_crouch_height > (env->d_ecran * env->h_mur) / -3)
			env->h_jump -= h_crouch_height;
		else
			env->crouch = -2;
	}
	else if (env->crouch == 1)
	{
		if (env->h_jump + h_crouch_height < 0)
			env->h_jump += h_crouch_height;
		else
		{
			env->crouch = 0;
			env->h_jump = 0;
			env->vitesse *= 2;
		}
	}
}
