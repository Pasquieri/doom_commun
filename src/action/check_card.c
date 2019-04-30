/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_card.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 21:45:45 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/30 21:39:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	check_north(t_env *env, int i, int mjx)
{
	int msx;
	int	msy;

	msx = ((int)(env->sp[4].sprite[i].cd.x - 1) / env->coef) / 1;
	msy = ((int)(env->sp[4].sprite[i].cd.y) / env->coef) / 1;
	if (msx == mjx)
		return ;
	if (env->tab[msy][msx] != FLOOR && env->tab[msy][msx] != MONKEY)
		return ;
	env->sp[4].sprite[i].cd.x -= 0.3;
}

void	check_south(t_env *env, int i, int mjx)
{
	int msx;
	int	msy;

	msx = ((int)(env->sp[4].sprite[i].cd.x + 1) / env->coef) / 1;
	msy = ((int)(env->sp[4].sprite[i].cd.y) / env->coef) / 1;
	if (msx == mjx)
		return ;
	if (env->tab[msy][msx] != FLOOR && env->tab[msy][msx] != MONKEY)
		return ;
	env->sp[4].sprite[i].cd.x += 0.3;
}

void	check_east(t_env *env, int i, int mjy)
{
	int msx;
	int	msy;

	msx = ((int)(env->sp[4].sprite[i].cd.x) / env->coef) / 1;
	msy = ((int)(env->sp[4].sprite[i].cd.y - 1) / env->coef) / 1;
	if (msy == mjy)
		return ;
	if (env->tab[msy][msx] != FLOOR && env->tab[msy][msx] != MONKEY)
		return ;
	env->sp[4].sprite[i].cd.y -= 0.3;
}

void	check_west(t_env *env, int i, int mjy)
{
	int msx;
	int	msy;

	msx = ((int)(env->sp[4].sprite[i].cd.x) / env->coef) / 1;
	msy = ((int)(env->sp[4].sprite[i].cd.y + 1) / env->coef) / 1;
	if (msy == mjy)
		return ;
	if (env->tab[msy][msx] != FLOOR && env->tab[msy][msx] != MONKEY)
		return ;
	env->sp[4].sprite[i].cd.y += 0.3;
}

void	check_card(t_env *env, int mjx, int mjy, int i)
{
	if (env->sp[4].sprite[i].cd.x / env->coef > env->perso_x / env->coef)
		check_north(env, i, mjx);
	else
		check_south(env, i, mjx);
	if (env->sp[4].sprite[i].cd.y / env->coef > env->perso_y / env->coef)
		check_east(env, i, mjy);
	else
		check_west(env, i, mjy);
}
