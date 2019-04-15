/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/15 21:01:39 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_sprite(t_env *env, double h_percue, int y, t_mlx *sp_t, int x, double test)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;


//	if (env->orientation == 0)
//		p_x = fmod(COORD.X, (float)env->coef) * 100 / env->coef;
//	else
//		p_x = fmod(COORD.Y, (float)env->coef) * 100 / env->coef;
	p_x = x * 100. / h_percue;
	if (y > (env->h_regard + test))
		p_y = (y - (env->h_regard + test)) * 100. / h_percue;
	else
		p_y = y * 100. / h_percue;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(sp_t->width * p_x / 100)
		+ (int)(sp_t->height * p_y / 100) * sp_t->s_l;
	if (!sp_t->img_str[j + 3]) // si pas transparent
	{
	env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
	env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
	env->m[0].img_str[i + 3] = (char)0;
//		env->m[0].img_str[i] = (char)150;
//		env->m[0].img_str[i + 1] = (char)100;
//		env->m[0].img_str[i + 2] = (char)250;
	}
}

static void	affiche_sprite(double d_sp, t_env *env, int i, int cmp)
{
	double	y;
	int		x;
	double	lim;
	double	h_percue;
	double	test;

	h_percue = env->d_ecran * (env->h_mur / d_sp);
	y = env->h_regard - (h_percue / 2);
	test = - h_percue / 2;
	if (i == 3 || i == 8) // pour avoir une banane plus petite : a revoir
	{
		h_percue /= 3;
		y = env->h_regard + (h_percue / 2);
		test = h_percue / 2;
	}
	y < 0. ? y = -1. : y;
	lim = y + h_percue;
	while (++y < lim && y < W_HEIGHT)
	{
		x = -1;
		env->img_x = env->sp[i].sprite[cmp].win_x;
		while (++x < h_percue && env->img_x < W_WIDTH)
		{
			put_sprite(env, h_percue, y, &env->sp_t[i], x, test);
			env->img_x++;
		}
	}
}

static	void	init_win_x(t_env *env, int i, int cmp)
{
	double	d_h;
	double	d_v;

	if (env->sp[i].sprite[cmp].detec[0].on == 1)
		d_h = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_h.x, 2)
			+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_h.y, 2));
	else
		d_h = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_v.x, 2)
		+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_v.y, 2)) + 1;
	if (env->sp[i].sprite[cmp].detec[1].on == 1)
		d_v = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_v.x, 2)
			+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_v.y, 2));
	else
		d_v = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_h.x, 2)
		+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_h.y, 2)) + 1;
	if (d_h < d_v)
		env->sp[i].sprite[cmp].win_x = env->sp[i].sprite[cmp].win_h_x;
	else
		env->sp[i].sprite[cmp].win_x = env->sp[i].sprite[cmp].win_v_x;
}

void	put_sprite_img(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sp;

	i = 1;
	while (++i < NB_SP) // < 5 pour tous les sprites sp[4] = monkey
	{
		if (i == 5) // porte +  tableau + gun
			i += 3;
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if (env->sp[i].sprite[cmp].det == 1)
			{
				d_sp = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd.x, 2)
					+ pow(env->perso_y - env->sp[i].sprite[cmp].cd.y, 2));
				env->lum = d_sp * 255 / env->lum_int;
				init_win_x(env, i, cmp);
				if (d_sp <= env->dist)
					affiche_sprite(d_sp, env, i, cmp);
			}
		}
	}
}
