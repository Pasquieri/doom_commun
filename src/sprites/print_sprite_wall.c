/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 22:23:16 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	put_sprite_grid(t_env *env, double h_p, int y, t_mlx *sp_t, double bep)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	if (env->orientation == 0)
		p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
	else
		p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
	if (y > (env->h_regard - bep))
		p_y = (y - (env->h_regard - bep)) * 100. / h_p;
	else
		p_y = y * 100. / h_p;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(sp_t->width * p_x / 100)
		+ (int)(sp_t->height * p_y / 100) * sp_t->s_l;
	if (!sp_t->img_str[j + 3])
	{
		env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
		env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
		env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
		env->m[0].img_str[i + 3] = (char)0;
	}
}

static void	check_proximity(double d_sprite, t_env *env, int k, int cmp)
{
	int	a;
	int	b;

	if (k == 5)
	{
		a = env->sp[k].sprite[cmp].i;
		b = env->sp[k].sprite[cmp].j;
		env->sp[k].sprite[cmp].open = 1;
		if (env->tab[b][a] == 7)
			env->sp[k].sprite[cmp].open = 0;
		if (d_sprite < (3 * env->coef / 2))
			env->sp[k].sprite[cmp].proximity = 1;
		else
			env->sp[k].sprite[cmp].proximity = 0;
	}
	else
	{
		if (d_sprite < env->coef)
			env->sp[k].sprite[cmp].proximity = 1;
		else
			env->sp[k].sprite[cmp].proximity = 0;
	}
}

static void	print_sprite(double d_sprite, t_env *env, int k, int cmp)
{
	double	y;
	double	lim;
	double	h_percue;
	double	bep;

	if (k == 5 || k == 7)
	{
		check_proximity(d_sprite, env, k, cmp);
		return ;
	}
	bep = (env->d_ecran * ((env->d_ecran * env->h_mur) / 2 - env->h_jump))
		/ (d_sprite * env->d_ecran);
	h_percue = env->d_ecran * (env->h_mur / d_sprite);
	y = env->h_regard - bep;
	lim = y + h_percue;
	y < 0. ? y = -1. : y;
	if ((k + 10) == GRID || (k + 10) == WIN)
		while (++y < lim && y < W_HEIGHT)
		{
			if ((k + 10) == GRID || ((int)y + env->img_x) % 2 == 0)
				put_sprite_grid(env, h_percue, y, &env->sp_t[k], bep);
		}
}

static double	ft_distance(t_env *env, int k, int cmp)
{
	double	dist0;
	double	dist1;

	if (env->sp[k].sprite[cmp].detec[0].on == 1)
		dist0 = env->sp[k].sprite[cmp].detec[0].dist;
	else
		dist0 = env->sp[k].sprite[cmp].detec[1].dist + 1;
	if (env->sp[k].sprite[cmp].detec[1].on == 1)
		dist1 = env->sp[k].sprite[cmp].detec[1].dist;
	else
		dist1 = env->sp[k].sprite[cmp].detec[0].dist + 1;
	env->orientation = 0;
	dist1 < dist0 ? env->orientation = 1 : env->orientation;
	env->coord_spr = env->sp[k].sprite[cmp].detec[env->orientation].cd;
	if (dist1 < dist0)
		return (dist1);
	return (dist0);
}

void	print_sprite_wall(t_env *env)
{
	int		k;
	int		cmp;
	double	d_sprite;

	k = -1;
	while (++k < NB_SP - 1)
	{
		cmp = -1;
		while (++cmp < env->sp[k].nb)
		{
			if ((env->sp[k].sprite[cmp].detec[0].on == 1)
					|| (env->sp[k].sprite[cmp].detec[1].on == 1))
			{
				d_sprite = ft_distance(env, k, cmp);
				env->lum = d_sprite * 255 / env->lum_int;
				if (d_sprite <= env->dist)
					print_sprite(d_sprite, env, k, cmp);
			}
			env->sp[k].sprite[cmp].detec[0].on = 0;
			env->sp[k].sprite[cmp].detec[1].on = 0;
		}
	}
}
