/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/29 14:00:00 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_sprite_img(t_env *env, double h_percue, int y, t_mlx *sp_t, double diff, double detec, double test)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	p_x = detec * 100. / diff;
	if (y > (env->h_regard + test))
		p_y = (y - (env->h_regard + test)) * 100. / h_percue;
	else
		p_y = y * 100. / h_percue;
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

static void	print_sprite(double d_sp, t_env *env, int i, int cmp)
{
	double	y;
	double	lim;
	double	h_percue;
	double	test;

	double	bep;
	bep = (env->d_ecran * ((env->d_ecran * env->h_mur) / 2 - env->h_jump))
		/ (d_sp * env->d_ecran);

	h_percue = env->d_ecran * (env->h_mur / d_sp);
	y = env->h_regard - bep;
	test = - bep;
//	if (i == 3 || i == 6) // pour avoir une banane plus petite : a revoir
//	{
//		h_percue /= 3;
//		y = env->h_regard + (h_percue / 2);
//		test = + bep;
//	}
	lim = y + h_percue;
	y < 0. ? y = 0. : y;

	double	diff;
	double	detec;
	double	a_i;
	double	a_f;
	a_i = env->sp[i].sprite[cmp].a_i;
	a_f = env->sp[i].sprite[cmp].a_f;
	diff = verif_angle(env->sp[i].sprite[cmp].a1 - env->sp[i].sprite[cmp].a2);
	detec = a_i - env->sp[i].sprite[cmp].a2;
	if (detec < 0)
		detec = (verif_angle(a_i + 90) - verif_angle(env->sp[i].sprite[cmp].a2 + 90));
	detec < 0 ? detec = 0 : detec;
	if (detec > diff)
		detec = diff;

/*	double	d_end;
	d_end = env->sp[i].sprite[cmp].a_f - env->sp[i].sprite[cmp].a2;
	if (d_end < 0)
		d_end = (verif_angle(a_f + 90) - verif_angle(env->sp[i].sprite[cmp].a2 + 90));
	d_end < 0 ? d_end = 0 : d_end;
	if (d_end > diff) //
		d_end = diff; // */
//	printf("            angle i : %f, diff : %f, det : %f\n", env->sp[i].sprite[cmp].a_i, diff, detec);
	env->img_x = env->sp[i].sprite[cmp].win_x;
//	while (detec > d_end && env->img_x < W_WIDTH)
	while (detec > 0 && env->img_x < W_WIDTH)
	{
		env->img_y = y + 1;
		while (env->img_y < lim && env->img_y < W_HEIGHT)
		{
			put_sprite_img(env, h_percue, env->img_y,
					&env->sp_t[i], diff, detec, test);
			env->img_y++;
		}
		detec -= (60. / W_WIDTH);
		env->img_x++;
	}
}

void	print_sprite_object(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sp;
	double	theta;
	t_coord	cd;

	i = 1;
	while (++i <= 6)
	{
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if (env->sp[i].sprite[cmp].det == 1)
			{
				d_sp = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd.x, 2)
						+ pow(env->perso_y - env->sp[i].sprite[cmp].cd.y, 2));
				env->lum = d_sp * 255 / env->lum_int;

				theta = verif_angle(env->d_regard + 90);
				cd = init_lim_coord(env, i, cmp, theta);
				env->sp[i].sprite[cmp].a1 = init_lim_angle(env, cd);
			//	printf("theta 1 : %f, cd (%f,%f), a1: %f, d_regard %d\n", theta, cd.x, cd.y, env->sp[i].sprite[cmp].a1, env->d_regard);
			//	printf("theta 1 : %f, a1: %f, d_regard %d\n", theta, env->sp[i].sprite[cmp].a1, env->d_regard);
				theta = verif_angle(env->d_regard - 90);
				cd = init_lim_coord(env, i, cmp, theta);
				env->sp[i].sprite[cmp].a2 = init_lim_angle(env, cd);
			//	printf("      2 : %f, a2: %f\n", theta, env->sp[i].sprite[cmp].a2);
			//	printf("      2 : %f, cd (%f,%f), a2: %f\n", theta, cd.x, cd.y, env->sp[i].sprite[cmp].a2);
			//	printf("         sp mid : cd (%f,%f), angle i : %f\n", env->sp[i].sprite[cmp].cd.x, env->sp[i].sprite[cmp].cd.y, env->sp[i].sprite[cmp].a_i);
			/****************** TEST ANGLE F ************************/
					printf("angle i : %f, angle f : %f, a1 : %f, a2 : %f d_regard : %d\n", env->sp[i].sprite[cmp].a_i, env->sp[i].sprite[cmp].a_f, env->sp[i].sprite[cmp].a1, env->sp[i].sprite[cmp].a2, env->d_regard);
				print_sprite(d_sp, env, i, cmp);
			}
		}
	}
}
