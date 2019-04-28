/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/21 19:32:11 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_texture_floor(double psx, double psy, t_env *env, int y)
{
	int p_x;
	int	p_y;
	int	i;
	int	j;

	p_x = (int)(psx * 100) % 100;
	p_y = (int)(psy * 100) % 100;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(env->text[0].width * p_x / 100)
		+ (int)(env->text[0].height * p_y / 100) * env->text[0].s_l;
	env->m[0].img_str[i] = luminosite(env->text[0].img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(env->text[0].img_str[j + 1],
			env->lum);
	env->m[0].img_str[i + 2] = luminosite(env->text[0].img_str[j + 2],
			env->lum);
	env->m[0].img_str[i + 3] = (char)0;
}

double		pos_sol_x(double psx, double m, double ac_p, t_env *env)
{
	if (env->angle > 0 && env->angle <= 90)
	{
		m = cos((M_PI * env->angle) / 180) * ac_p;
		return (psx + m / env->coef);
	}
	else if (env->angle > 90 && env->angle <= 180)
	{
		m = -1 * cos((M_PI * env->angle) / 180) * ac_p;
		return (psx - m / env->coef);
	}
	else if (env->angle > 180 && env->angle <= 270)
	{
		m = -1 * cos((M_PI * env->angle) / 180) * ac_p;
		return (psx - m / env->coef);
	}
	else
	{
		m = cos((M_PI * env->angle) / 180) * ac_p;
		return (psx + m / env->coef);
	}
}

double		pos_sol_y(double psy, double n, double ac_p, t_env *env)
{
	if (env->angle > 0 && env->angle <= 90)
	{
		n = sin((M_PI * env->angle) / 180) * ac_p;
		return (psy - n / env->coef);
	}
	else if (env->angle > 90 && env->angle <= 180)
	{
		n = sin((M_PI * env->angle) / 180) * ac_p;
		return (psy - n / env->coef);
	}
	else if (env->angle > 180 && env->angle <= 270)
	{
		n = -1 * sin((M_PI * env->angle) / 180) * ac_p;
		return (psy + n / env->coef);
	}
	else
	{
		n = -1 * sin((M_PI * env->angle) / 180) * ac_p;
		return (psy + n / env->coef);
	}
}

void		affichage_sol(double y, double h_percue, t_env *env)
{
	double ac_sol;
	double tmp;
	double pos_perso_x;
	double pos_perso_y;

	h_percue = 2;
	pos_perso_x = env->perso_x / (double)env->coef;
	pos_perso_y = env->perso_y / (double)env->coef;
	tmp = (env->h_regard) / ((y - env->h_regard) / env->d_ecran);
	while (y < W_HEIGHT)
	{
		ac_sol = (env->d_ecran * ((env->d_ecran * env->h_mur)
		/ 2 + env->h_jump)) / (y - env->h_regard);
		ac_sol = ac_sol / env->d_ecran;
		ac_sol = ac_sol / cos((env->angle - env->d_regard) * M_PI / 180);
		env->lum = ac_sol * 255 / env->lum_int;
		put_texture_floor(pos_sol_x(pos_perso_x, 0, ac_sol, env),
			pos_sol_y(pos_perso_y, 0, ac_sol, env), env, y);
		y++;
	}
}
