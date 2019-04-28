/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:49:20 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/27 17:28:00 by mpasquie         ###   ########.fr       */
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
	{
		env->h_life -= 2;
		system("/usr/bin/afplay -q 1 src/song/scream.mp3&");
	}
	if (env->h_life < 1)
		env->h_end = 1;
}

void	check_north(t_env *env, int i, int mJx)
{
	int mSx;
	int	mSy;

	mSx = ((int)(env->sp[4].sprite[i].cd.x - 1) / env->coef) / 1;
	mSy = ((int)(env->sp[4].sprite[i].cd.y) / env->coef) / 1;
	if (mSx == mJx)
		return ;
/*	if (env->tab[mSx][mSy] != FLOOR && env->tab[mSx][mSy] != MONKEY)
	{
		return;
		printf("obstacle: %d (north)\n",env->tab[mSx][mSy] );
	}*/
	env->sp[4].sprite[i].cd.x -= 0.3;
}

void	check_south(t_env *env, int i, int mJx)
{
	int mSx;
	int	mSy;

	mSx = ((int)(env->sp[4].sprite[i].cd.x + 1) / env->coef) / 1;
	mSy = ((int)(env->sp[4].sprite[i].cd.y) / env->coef) / 1;
	if (mSx == mJx)
		return ;
	/*if (env->tab[mSx][mSy] != FLOOR && env->tab[mSx][mSy] != MONKEY)
	{
		return;
		printf("obstacle: %d (south)\n",env->tab[mSx][mSy] );
	}*/
	env->sp[4].sprite[i].cd.x += 0.3;
}

void	check_east(t_env *env, int i, int mJy)
{
	int mSx;
	int	mSy;

	mSx = ((int)(env->sp[4].sprite[i].cd.x) / env->coef) / 1;
	mSy = ((int)(env->sp[4].sprite[i].cd.y - 1) / env->coef) / 1;
	if (mSy == mJy)
		return ;
	/*if (env->tab[mSx][mSy] != FLOOR && env->tab[mSx][mSy] != MONKEY)
	{
		return;
		printf("obstacle: %d (east)\n",env->tab[mSx][mSy] );
	}*/
	env->sp[4].sprite[i].cd.y -= 0.3;
}

void	check_west(t_env *env, int i, int mJy)
{
	int mSx;
	int	mSy;

	mSx = ((int)(env->sp[4].sprite[i].cd.x) / env->coef) / 1;
	mSy = ((int)(env->sp[4].sprite[i].cd.y + 1) / env->coef) / 1;
	if (mSy == mJy)
		return ;
	/*if (env->tab[mSx][mSy] != FLOOR && env->tab[mSx][mSy] != MONKEY)
	{
		return;
		printf("obstacle: %d (west)\n",env->tab[mSx][mSy] );
	}*/
	env->sp[4].sprite[i].cd.y += 0.3;
}

void	runToPlayer(t_env *env, int i) // colision mur a add
{
	int mJx;
	int mJy;

	mJx = (env->perso_x / env->coef) / 1;
	mJy = (env->perso_y / env->coef) / 1;
	if (env->sp[4].sprite[i].cd.x / env->coef > env->perso_x / env->coef)
		check_north(env, i, mJx);
	else 
		check_south(env, i, mJx);
	if (env->sp[4].sprite[i].cd.y / env->coef > env->perso_y / env->coef)
		check_east(env, i, mJy);
	else
		check_west(env, i, mJy);
	env->tab[(int)(env->sp[4].sprite[i].cd.y / env->coef)][(int)(env->sp[4].sprite[i].cd.x / env->coef)] = 14;
	
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