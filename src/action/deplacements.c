/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:41:36 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 21:39:14 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

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
			&& check(env->tab[((int)y + 1) / env->coef]
				[(int)x / env->coef], env)
			&& check(env->tab[((int)y - 1) / env->coef]
				[(int)x / env->coef], env)
			&& check(env->tab[(int)y / env->coef]
				[((int)x + 1) / env->coef], env)
			&& check(env->tab[(int)y / env->coef][
				((int)x - 1) / env->coef], env))
		return (0);
	else
		return (1);
}

static void	check_end(t_env *env)
{
	int	i;
	int	j;

	i = (int)(env->perso_x / env->coef);
	j = (int)(env->perso_y / env->coef);
	if (env->tab[j][i] == END && env->h_end == 0)
	{
		if (env->h_monkey <= 0)
		{
			system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
			env->h_end = 1;
			env->lum_int = 0;
			system("/usr/bin/afplay -q 1 src/song/you_win.mp3&");
		}
		else
		{
			system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
			env->h_end = 1;
			env->lum_int = 0;
			system("/usr/bin/afplay -q 1 src/song/try_again.mp3&");
		}
		env->gun = 0;
	}
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
		deal_items(env, 6);
	}
	check_end(env);
}
