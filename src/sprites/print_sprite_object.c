/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 20:50:32 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	calcul_pourcent(t_env *env, t_sprite sp)
{
	double	a_win;

	if (sp.a_i > sp.a1 || verif_angle(sp.a_i + 90) > verif_angle(sp.a1 + 90))
		sp.a_i = sp.a1;
	if (sp.a_f < sp.a2 || verif_angle(sp.a_f + 90) < verif_angle(sp.a2 + 90))
		sp.a_f = sp.a2;
	env->d_begin = sp.a_i - sp.a2;
	env->d_end = sp.a_f - sp.a2;
	env->diff = verif_angle(sp.a1 - sp.a2);
	if (env->d_begin < 0)
		env->d_begin = verif_angle(sp.a_i + 90) - verif_angle(sp.a2 + 90);
	env->d_begin < 0 ? env->d_begin = 0 : env->d_begin;
	if (env->d_begin > env->diff)
		env->d_begin = env->diff;
	if (env->d_end < 0)
		env->d_end = verif_angle(sp.a_f + 90) - verif_angle(sp.a2 + 90);
	if (env->d_end > env->diff)
		env->d_end = env->diff;
	a_win = verif_angle(env->d_regard + 30) - sp.a_i;
	if (a_win < 0)
		a_win = verif_angle(env->d_regard + 120) - verif_angle(sp.a_i + 90);
	a_win > 60. ? a_win = 60. : a_win;
	env->img_x = (int)(1200. * a_win / 60.);
}

static int	monkey_texture(t_env *env, int i, int cmp)
{
	int	tmp;

	tmp = i;
	if (i == 4)
	{
		if ((env->sp[4].sprite[cmp].monkey % 8) == 2
					|| (env->sp[4].sprite[cmp].monkey % 8) == 1)
			tmp = 10;
		else if ((env->sp[4].sprite[cmp].monkey % 8) == 6
					|| (env->sp[4].sprite[cmp].monkey % 8) == 7)
			tmp = 11;
		else
			tmp = 4;
	}
	return (tmp);
}

static void	proportion(t_env *env, double d_sp, double *bep, double *h_percue)
{
	*bep = (env->d_ecran * ((env->d_ecran * (env->h_mur / 10)) / 2
			- env->h_jump)) / (d_sp * env->d_ecran);
	*h_percue /= 4;
}

static void	print_sprite(double d_sp, t_env *env, int i, int cmp)
{
	double	y;
	double	lim;
	double	h_percue;
	double	bep;
	int		tmp;

	tmp = monkey_texture(env, i, cmp);
	bep = ((env->d_ecran * ((env->d_ecran * env->h_mur) / 2 - env->h_jump))
			/ (d_sp * env->d_ecran));
	h_percue = env->d_ecran * (env->h_mur / d_sp);
	if (i == 3 || i == 6)
		proportion(env, d_sp, &bep, &h_percue);
	y = env->h_regard - bep;
	lim = y + h_percue - 1;
	y < 0. ? y = 0. : y;
	calcul_pourcent(env, env->sp[i].sprite[cmp]);
	while (env->d_begin > env->d_end && env->img_x < W_WIDTH)
	{
		env->img_y = y;
		while (++env->img_y < lim && env->img_y < W_HEIGHT)
			put_sprite_img(env, h_percue, &env->sp_t[tmp], bep);
		env->d_begin -= (60. / W_WIDTH);
		env->img_x++;
	}
}

void		print_sprite_object(t_env *env, int i, int cmp)
{
	double	d_sp;
	double	theta;
	t_coord	cd;

	env->sp[i].sprite[cmp].a_mid = init_lim_angle(env,
		env->sp[i].sprite[cmp].cd);
	d_sp = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd.x, 2)
		+ pow(env->perso_y - env->sp[i].sprite[cmp].cd.y, 2));
	d_sp = d_sp * cos((env->sp[i].sprite[cmp].a_mid - env->d_regard)
		* M_PI / 180);
	env->lum = d_sp * 255 / env->lum_int;
	theta = verif_angle(env->d_regard + 90);
	cd = init_lim_coord(env, i, cmp, theta);
	env->sp[i].sprite[cmp].a1 = init_lim_angle(env, cd);
	theta = verif_angle(env->d_regard - 90);
	cd = init_lim_coord(env, i, cmp, theta);
	env->sp[i].sprite[cmp].a2 = init_lim_angle(env, cd);
	print_sprite(d_sp, env, i, cmp);
}
