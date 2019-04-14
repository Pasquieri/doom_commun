/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_mur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/14 20:45:23 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void		affichage_ciel(t_env *env, int y, double bep)
{
	float	lim;
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	y = -1;
	lim = (env->h_regard - bep);
	p_x = (100. * env->angle) / 120.;
	while (++y < lim && y < W_HEIGHT)
	{
		p_y = (100. * y) / (W_HEIGHT);
		i = 4 * env->img_x + y * env->m[0].s_l;
		j = 4 * (int)(env->text[env->skybox].width * p_x / 100)
			+ (int)(env->text[env->skybox].height * (p_y + (100 - (env->h_regard
			* 100 / W_HEIGHT))) / 100) * env->text[env->skybox].s_l;
		env->m[0].img_str[i] = env->text[env->skybox].img_str[j];
		env->m[0].img_str[i + 1] = env->text[env->skybox].img_str[j + 1];
		env->m[0].img_str[i + 2] = env->text[env->skybox].img_str[j + 2];
	}
}

static void		affichage(double h_percue, t_env *env, int x)
{
	double	y;
	double	lim;

	double ddp;
	ddp = env->d_ecran * env->h_mur;
	double adp;
	adp = ddp / 2 - env->h_jump;
	double bc;
	bc = env->d_ecran;
	double ac;
	ac = env->dist * env->d_ecran;
	double bep;
	bep = (bc * adp) / ac;

	(void)x;
	lim = env->h_regard - (env->coef_h_wall * bep);
	if (!env->skybox)
		affichage_plafond(lim, h_percue, env);
	else
		affichage_ciel(env, 0, bep);

/*	y = -1;
	while (++y < lim && y < 870.)
		put_pxl_img(env, x, y, 6);
	y--;*/
	env->cmp_wall = env->coef_h_wall;
	while (env->cmp_wall > 0)
	{
		y = env->h_regard - (env->cmp_wall * bep) ;
		y < 0 ? y = 0 : y;
		lim = y + h_percue + 1;
		env->lum = env->dist * 255 / env->lum_int;
		env->wall_nb == 7 ? env->wall_nb = 8 : env->wall_nb;
		if (env->cmp_wall == 1 && env->wall_nb == 8)
			env->wall_nb = 7;
		while (++y <= lim && y < 870.)
			put_texture_img(env, h_percue, y, &env->text[env->wall_nb], bep);
		env->cmp_wall -= 2;
	}
	y = env->h_regard - bep + h_percue;
	affichage_sol(y, h_percue, env);
/*	y--;
	while (++y < 870.)
		put_pxl_img(env, x, y, 7);*/
}

static double	verif_angle(double angle)
{
	if (angle < 0.)
	{
		while (angle < 0.)
			angle = angle + 360.;
	}
	else if (angle > 360.)
	{
		while (angle > 360.)
			angle = angle - 360.;
	}
	if (angle == 360.)
		angle = 0.;
	return (angle);
}

void			*affichage_mur(void *tab)
{
	t_env	env;
	double	a;
	double	dist;
	double	h_percue;
	int		x;

	env = *(t_env *)tab;
	a = env.d_regard + env.angle_thread;
	a = verif_angle(a);
	x = env.img_x;
	while (x < (env.nb_colonne))
	{
		env.angle = a;
		env.angle = verif_angle(env.angle);
		dist = detection_mur(&env);
		dist = dist * cos((a - env.d_regard) * M_PI / 180);
		env.dist = dist;
		h_percue = env.d_ecran * (env.h_mur / dist);
		env.lim_sol = env.h_regard + (h_percue / 2);
		env.img_x = x;
		affichage(h_percue, &env, x);
		a -= (60. / W_WIDTH);
		x++;
	}
	return (NULL);
}
