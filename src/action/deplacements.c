/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:41:36 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/26 20:33:14 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int	check(int value, t_env *env)
{
	if (value == FLOOR || value == BEGIN || value == END || value == BANANA
			|| value == MONKEY || value == DOOR_CLOSE || value == SYRINGE)
	{
		if (value == BANANA || value == SYRINGE)
			env->value = value;
		return (1);
	}
	else
		return (0);
}

int			check_wall(double xa, double ya, t_env *env)
{
	double	x;
	double	y;

	x = env->perso_x + xa;
	y = env->perso_y + ya;
	if (check(env->tab[(int)y / env->coef][(int)x / env->coef], env)
		&& check(env->tab[((int)y + 1) / env->coef][(int)x / env->coef], env)
		&& check(env->tab[((int)y - 1) / env->coef][(int)x / env->coef], env)
		&& check(env->tab[(int)y / env->coef][((int)x + 1) / env->coef], env)
		&& check(env->tab[(int)y / env->coef][((int)x - 1) / env->coef], env))
		return (0);
	else
		return (1);
}

void		deplacements(t_env *env)
{
	env->value = -1;
	if (env->key[1])
		depla_vertical(env, 1);
	if (env->key[13])
		depla_vertical(env, 13);
	if (env->key[0])
		depla_horizontal(env, 0);
	if (env->key[2])
		depla_horizontal(env, 2);
	if (env->value != -1)
	{
		deal_items(env, 3);
		deal_items(env, 8);
	}
}
