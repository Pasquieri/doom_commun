/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:49:20 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/25 15:49:22 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	attack(t_env *env, int i)
{
	int mJx = (env->perso_x / env->coef) / 1;
	int mJy = (env->perso_y / env->coef) / 1;
	int x;
	int y;

	x = 0;
	y = 0;
	if (((int)(env->sp[4].sprite[i].cd.x-3) / env->coef) / 1 == mJx)
		x = 1;
	else if(((int)(env->sp[4].sprite[i].cd.x+3) / env->coef) / 1 == mJx)
		x = 1;
	if (((int)(env->sp[4].sprite[i].cd.y-3) / env->coef) / 1 == mJy)
		y = 1;
	else if (((int)(env->sp[4].sprite[i].cd.y+3) / env->coef) / 1 == mJy)
		y = 1;
	if (x && y)
		env->h_life -= 2;		
}

void	runToPlayer(t_env *env, int i) // colision mur a add
{
	int mJx;
	mJx = (env->perso_x / env->coef) / 1;
	int mJy;
	mJy = (env->perso_y / env->coef) / 1;

	if (env->sp[4].sprite[i].cd.x / env->coef != env->perso_x / env->coef &&
	 env->sp[4].sprite[i].cd.y / env->coef != env->perso_y / env->coef)
	{
		if (env->sp[4].sprite[i].cd.x / env->coef > env->perso_x / env->coef 
			&& (((int)(env->sp[4].sprite[i].cd.x-1) / env->coef) / 1 != mJx))
			env->sp[4].sprite[i].cd.x -= 0.3;
		else if(((int)(env->sp[4].sprite[i].cd.x+1) / env->coef) / 1 != mJx)
			env->sp[4].sprite[i].cd.x += 0.3;
		if (env->sp[4].sprite[i].cd.y / env->coef > env->perso_y / env->coef
			&& (((int)(env->sp[4].sprite[i].cd.y-1) / env->coef) / 1 != mJy))
			env->sp[4].sprite[i].cd.y -= 0.3;
		else if (((int)(env->sp[4].sprite[i].cd.y+1) / env->coef) / 1 != mJy)
			env->sp[4].sprite[i].cd.y += 0.3;
		env->tab[(int)(env->sp[4].sprite[i].cd.y / env->coef)][(int)(env->sp[4].sprite[i].cd.x / env->coef)] = 14;
	}
}

void	ft_monkey(t_env *env)
{
	int k = env->sp[4].nb;
	int i = 0;
	while (i < k)
	{
		if (env->time % 10 == 0)
			attack(env, i);
		if (env->sp[4].sprite[i].det == 1 && env->time % 1 == 0)
			runToPlayer(env, i);
		i++;
	}
}