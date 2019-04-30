/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_plafond.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/30 21:44:20 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	put_texture_sky(double pos_px, double pos_py, t_env *env, int y)
{
	int p_x;
	int	p_y;
	int	i;
	int	j;
	int	flou;

	p_x = (int)(pos_px * 100) % 100;
	p_y = (int)(pos_py * 100) % 100;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(env->text[21].width * p_x / 100)
		+ (int)(env->text[21].height * p_y / 100) * env->text[21].s_l;
	env->m[0].img_str[i] = luminosite(env->text[21].img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(env->text[21].img_str[j + 1],
			env->lum);
	env->m[0].img_str[i + 2] = luminosite(env->text[21].img_str[j + 2],
			env->lum);
	flou = 100 - env->h_life;
	flou < 0 ? flou = 0 : flou;
	env->m[0].img_str[i + 3] = (char)flou;
}

double		pos_plafond_x(double ppx, double m, double ac_p, t_env *env)
{
	if (env->angle > 0 && env->angle <= 90)
	{
		m = cos((M_PI * env->angle) / 180) * ac_p;
		return (ppx + m / env->coef);
	}
	else if (env->angle > 90 && env->angle <= 180)
	{
		m = -1 * cos((M_PI * env->angle) / 180) * ac_p;
		return (ppx - m / env->coef);
	}
	else if (env->angle > 180 && env->angle <= 270)
	{
		m = -1 * cos((M_PI * env->angle) / 180) * ac_p;
		return (ppx - m / env->coef);
	}
	else
	{
		m = cos((M_PI * env->angle) / 180) * ac_p;
		return (ppx + m / env->coef);
	}
}

double		pos_plafond_y(double ppy, double n, double ac_p, t_env *env)
{
	if (env->angle > 0 && env->angle <= 90)
	{
		n = sin((M_PI * env->angle) / 180) * ac_p;
		return (ppy - n / env->coef);
	}
	else if (env->angle > 90 && env->angle <= 180)
	{
		n = sin((M_PI * env->angle) / 180) * ac_p;
		return (ppy - n / env->coef);
	}
	else if (env->angle > 180 && env->angle <= 270)
	{
		n = -1 * sin((M_PI * env->angle) / 180) * ac_p;
		return (ppy + n / env->coef);
	}
	else
	{
		n = -1 * sin((M_PI * env->angle) / 180) * ac_p;
		return (ppy + n / env->coef);
	}
}

void		affichage_plafond(double y, double h_percue, t_env *env)
{
	double ac_p;
	double tmp;
	double pos_perso_x;
	double pos_perso_y;

	h_percue = 2;
	pos_perso_x = env->perso_x / (double)env->coef;
	pos_perso_y = env->perso_y / (double)env->coef;
	tmp = (env->h_regard) / ((y - env->h_regard) / env->d_ecran);
	while (y > 0)
	{
		ac_p = (env->h_regard) / ((double)(y - env->h_regard)
				/ (env->d_ecran * (env->dist / tmp)));
		ac_p = ac_p / cos((env->angle - env->d_regard) * M_PI / 180);
		env->lum = ac_p * 255 / env->lum_int;
		put_texture_sky(pos_plafond_x(pos_perso_x, 0, ac_p, env),
			pos_plafond_y(pos_perso_y, 0, ac_p, env), env, y);
		y--;
	}
}
