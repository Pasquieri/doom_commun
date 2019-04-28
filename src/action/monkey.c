/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:49:20 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/28 17:47:43 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	attack_bruit(int x, int y, t_env *env)
{
	if (x && y && env->h_end == 0)
	{
		env->h_life -= 10;
		if (env->h_end <= 0)
		{
			if (env->h_life > 0)
				system("/usr/bin/afplay -q 1 src/song/hit.mp3&");
			else
			{
				system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
				system("/usr/bin/afplay -q 1 src/song/scream.mp3&");
				env->h_end = 1;
				env->lum_int = 0;
				system("/usr/bin/afplay -q 1 src/song/you_loose.mp3&");
				env->gun = 0;
			}
		}
	}
}

void	attack(t_env *env, int i)
{
	int mjx;
	int mjy;
	int x;
	int y;

	mjx = (env->perso_x / env->coef) / 1;
	mjy = (env->perso_y / env->coef) / 1;
	x = 0;
	y = 0;
	if (((int)(env->sp[4].sprite[i].cd.x - 3) / env->coef) / 1 == mjx)
		x = 1;
	else if (((int)(env->sp[4].sprite[i].cd.x + 3) / env->coef) / 1 == mjx)
		x = 1;
	if (((int)(env->sp[4].sprite[i].cd.y - 3) / env->coef) / 1 == mjy)
		y = 1;
	else if (((int)(env->sp[4].sprite[i].cd.y + 3) / env->coef) / 1 == mjy)
		y = 1;
	attack_bruit(x, y, env);
	if (env->h_life < 1)
		env->h_end = 1;
}

void	runtoplayer(t_env *env, int i)
{
	int	mjx;
	int mjy;
	int pmx;
	int pmy;

	mjx = (env->perso_x / env->coef) / 1;
	mjy = (env->perso_y / env->coef) / 1;
	pmx = (int)(env->sp[4].sprite[i].cd.x / env->coef);
	pmy = (int)(env->sp[4].sprite[i].cd.y / env->coef);
	check_card(env, mjx, mjy, i);
	env->tab[(int)(env->sp[4].sprite[i].cd.y / env->coef)]
	[(int)(env->sp[4].sprite[i].cd.x / env->coef)] = 14;
	env->sp[4].sprite[i].j = (int)(env->sp[4].sprite[i].cd.y / env->coef / 1);
	env->sp[4].sprite[i].i = (int)(env->sp[4].sprite[i].cd.x / env->coef / 1);
	if ((int)(env->sp[4].sprite[i].cd.y / env->coef / 1) != pmy / 1
		|| (int)(env->sp[4].sprite[i].cd.x / env->coef / 1) != pmx / 1)
		env->tab[pmy][pmx] = 0;
}

void	ft_monkey(t_env *env)
{
	int k;
	int i;

	k = env->sp[4].nb;
	i = 0;
	while (i < k)
	{
		if (env->time % 10 == 0)
			attack(env, i);
		if (env->sp[4].sprite[i].det == 1 && env->time % 1 == 0)
			runtoplayer(env, i);
		i++;
	}
}
