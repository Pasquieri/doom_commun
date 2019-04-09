/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_mur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int		affichage_ciel(double h_percue, t_env *env, int x, float y)
{
	float	lim;
	float	pourcent_x;
	float	pourcent_y;
	int		i;
	int		j;

	y = -1;
	lim = (env->h_regard - (h_percue / 2));
//	pourcent_x = (100. * x) / env->nb_colonne;
	pourcent_x = (100. * env->angle) / 120.;
	while (++y < lim && y < W_HEIGHT)
	{
		pourcent_y = (100. * y) / (W_HEIGHT);
		i = 4 * x + y * env->m[0].s_l;
		j = 4 * (int)(env->text[22].width * pourcent_x / 100)
			+ (int)(env->text[22].height * (pourcent_y + (100 - (env->h_regard
								* 100 / W_HEIGHT))) / 100) * env->text[22].s_l;
		env->m[0].img_str[i] = env->text[22].img_str[j];
		env->m[0].img_str[i + 1] = env->text[22].img_str[j + 1];
		env->m[0].img_str[i + 2] = env->text[22].img_str[j + 2];
	}
	return (y - 1);
}

static void		affichage(double h_percue, t_env *env, int x)
{
	double	y;
	double	lim;

	(void)x;
	y = env->h_regard + (h_percue / 2);
	affichage_sol(y, env);
	y = env->h_regard - (h_percue / 2);
	if (!env->skybox)
		affichage_plafond(y, env);
	else
		affichage_ciel(h_percue, env, x, 0);
/*	y = -1;
	while (++y < lim && y < 870.)
		put_pxl_img(env, x, y, 6);
	y--;*/
	y < 0 ? y = 0 : y;
	lim = env->lim_sol;
	env->lum = env->dist * 255 / env->lum_int;
	while (++y < lim && y < 870.)
		put_texture_img(env, h_percue, y, &env->text[env->wall_nb]);
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

void			affichage_mur(t_env *env)
{
	double	a;
	double	dist;
	double	h_percue;
	int		x;

	a = env->d_regard + 30;
	a = verif_angle(a);
	x = 0;
	while (x < (env->nb_colonne))
	{
		env->angle = a;
		env->angle = verif_angle(env->angle);
		env->sp_nb = 0; // add
		dist = detection_mur(env);
		dist = dist * cos((a - env->d_regard) * M_PI / 180);
		env->dist = dist;
		h_percue = env->d_ecran * (env->h_mur / dist);
		env->lim_sol = env->h_regard + (h_percue / 2); //
		env->img_x = x;
		affichage(h_percue, env, x);
		print_sprite(env);
		a -= (60. / (env->nb_colonne));
		x++;
	}
}
