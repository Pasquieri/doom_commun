/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_mur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/03 18:49:37 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"
/*
static int		affichage_ciel(double h_percue, t_env *env, int x, float y)
{
	float	lim;
	float	pourcent_x;
	float	pourcent_y;
	int		i;
	int		j;

	y = -1;
	lim = (env->h_regard - (h_percue / 2));
	//printf("limite ciel:%f\n",lim);
	pourcent_x = (100. * x) / env->nb_colonne;
	while (++y < lim && y < W_HEIGHT)
	{
		pourcent_y = (100. * y) / (W_HEIGHT);
		i = 4 * x + y * env->m[0].s_l;
		j = 4 * (int)(env->text[22].width * pourcent_x / 100)
			+ (int)(env->text[22].height * (pourcent_y + (100 - (env->h_regard
								* 100 / W_HEIGHT))) / 100) * env->text[22].s_l;
	//	j = 4 * (int)(env->text[22].width * pourcent_x / 100)
	//		+ (int)(env->text[22].height * (pourcent_y / 100)) * env->text[22].s_l;
		env->m[0].img_str[i] = env->text[22].img_str[j];
		env->m[0].img_str[i + 1] = env->text[22].img_str[j + 1];
		env->m[0].img_str[i + 2] = env->text[22].img_str[j + 2];
		//env->m[0].img_str[i] = luminosite(env->text[22].img_str[j], env->lum);
		//env->m[0].img_str[i + 1] = luminosite(env->text[22].img_str[j + 1], env->lum);
		//env->m[0].img_str[i + 2] = luminosite(env->text[22].img_str[j + 2], env->lum);
	}
	return (y - 1);
}*/

/*static void		affichage(double h_percue, t_env *env, int x)
{
	float	y;
	float	lim;

	//y = 0;
	//y = affichage_ciel(h_percue, env, x, y);
	y = env->h_regard - (h_percue / 2);
	//	lim = (env->h_regard + (h_percue / 2));
	lim = env->lim_sol;
	while (++y < lim && y < 870.) // affichage_mur
		put_texture_img(env, h_percue, y, &env->text[env->wall_nb]);
	affichage_sol(x, y, env);
}*/

static void		affichage(double h_percue, t_env *env, int x)
{
	float	y;
	float	lim;

	y = -1;
	lim = env->h_regard - (h_percue / 2);
	while (++y < lim && y < 870.)
		put_pxl_img(env, x, y, 6);
	y--;
	lim = env->lim_sol;
	while (++y < lim && y < 870.) // affichage_mur
		put_texture_img(env, h_percue, y, &env->text[env->wall_nb]);
	y--;
	while (++y < 870.)
		put_pxl_img(env, x, y, 7);
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
		dist = detection_mur(env);
		dist = dist * cos((a - env->d_regard) * M_PI / 180);
		env->dist = dist;
		h_percue = env->d_ecran * (env->h_mur / dist);
		env->lum = dist * 255 / env->lum_int;
		env->lim_sol = env->h_regard + (h_percue / 2); //
		env->img_x = x;
		affichage(h_percue, env, x);
		print_sprite(env);
		a -= (60. / (env->nb_colonne));
		x++;
	}
}
