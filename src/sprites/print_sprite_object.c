/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 20:10:42 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_sprite_img(t_env *env, double h_percue, t_mlx *sp_t, double diff, double bep)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	p_x = env->d_begin * 100. / diff;
	if (env->img_y > (env->h_regard - bep))
		p_y = (env->img_y - (env->h_regard - bep)) * 100. / h_percue;
	else
		p_y = env->img_y * 100. / h_percue;
	i = 4 * env->img_x + env->img_y * env->m[0].s_l;
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

static void	calcul_pourcent(t_env *env, t_sprite sp, double diff)
{
	double	a_win;

//	printf("BEFORE a_i : %f, a1 : %f, a_f : %f, a2 : %f\n", sp.a_i, sp.a1, sp.a_f, sp.a2);
	if (sp.a_i > sp.a1 || verif_angle(sp.a_i + 90) > verif_angle(sp.a1 + 90)) // ??
		sp.a_i = sp.a1;
	if (sp.a_f < sp.a2 || verif_angle(sp.a_f + 90) < verif_angle(sp.a2 + 90))
		sp.a_f = sp.a2;
//	printf("AFTER a_i : %f, a1 : %f, a_f : %f, a2 : %f\n", sp.a_i, sp.a1, sp.a_f, sp.a2);

	env->d_begin = sp.a_i - sp.a2;
	env->d_end = sp.a_f - sp.a2;
//	printf("BEFORE d_begin : %f d_end : %f\n", env->d_begin, env->d_end);

	if (env->d_begin < 0)
		env->d_begin = verif_angle(sp.a_i + 90) - verif_angle(sp.a2 + 90);
	env->d_begin < 0 ? env->d_begin = 0 : env->d_begin; // ??
	if (env->d_begin > diff)
		env->d_begin = diff;
	if (env->d_end < 0)
		env->d_end = verif_angle(sp.a_f + 90) - verif_angle(sp.a2 + 90);
	if (env->d_end > diff)
		env->d_end = diff;
//	printf("AFTER d_begin : %f d_end : %f\n\n", env->d_begin, env->d_end);

	a_win = verif_angle(env->d_regard + 30) - sp.a_i;
	if (a_win < 0)
		a_win = verif_angle(env->d_regard + 120) - verif_angle(sp.a_i + 90);
	a_win > 60. ? a_win = 60. : a_win;
	env->img_x = (int)(1200. * a_win / 60.);
}

static void	print_sprite(double d_sp, t_env *env, int i, int cmp)
{
	double	y;
	double	lim;
	double	h_percue;
	double	diff;
	double	bep;
	int tmp;

	tmp = i;
	if (i == 4)
	{
		if ((env->sp[4].sprite[cmp].monkey % 4) == 0
				|| (env->sp[4].sprite[cmp].monkey % 4) == 2)
			tmp = 4;
		else if ((env->sp[4].sprite[cmp].monkey % 4) == 1)
			tmp = 10;
		else if ((env->sp[4].sprite[cmp].monkey % 4) == 3)
			tmp = 11;
	}
	bep = (env->d_ecran * ((env->d_ecran * env->h_mur) / 2 - env->h_jump))
		/ (d_sp * env->d_ecran);
	h_percue = env->d_ecran * (env->h_mur / d_sp);
	y = env->h_regard - bep;
	if (i == 3 || i == 6)
		h_percue /= 4;
	lim = y + h_percue - 1;
	y < 0. ? y = 0. : y;
	diff = verif_angle(env->sp[i].sprite[cmp].a1 - env->sp[i].sprite[cmp].a2);
	calcul_pourcent(env, env->sp[i].sprite[cmp], diff);
	while (env->d_begin > env->d_end && env->img_x < W_WIDTH)
	{
		env->img_y = y;
		while (++env->img_y < lim && env->img_y < W_HEIGHT)
			put_sprite_img(env, h_percue, &env->sp_t[tmp], diff, bep);
		env->d_begin -= (60. / W_WIDTH);
		env->img_x++;
	}
}


void	print_sprite_object(t_env *env, int i, int cmp)
{
//	int	i;
//	int	cmp;
	double	d_sp;
	double	theta;
	t_coord	cd;

//	i = 1;
//	while (++i <= 6)
//	{
//		cmp = -1;
//		while (++cmp < env->sp[i].nb)
//		{
//			if (env->sp[i].sprite[cmp].det == 1)
			{
				env->sp[i].sprite[cmp].a_mid = init_lim_angle(env, env->sp[i].sprite[cmp].cd);
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
//		}
//	}
}
