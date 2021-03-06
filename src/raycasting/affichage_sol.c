/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/30 21:37:35 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	put_texture_floor(double psx, double psy, t_env *env, int b)
{
	int p_x;
	int	p_y;
	int	i;
	int	j;
	int	flou;

	p_x = (int)(psx * 100) % 100;
	p_y = (int)(psy * 100) % 100;
	i = 4 * env->img_x + env->dy * env->m[0].s_l;
	j = 4 * (int)(env->text[b].width * p_x / 100)
		+ (int)(env->text[b].height * p_y / 100) * env->text[b].s_l;
	env->m[0].img_str[i] = luminosite(env->text[b].img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(env->text[b].img_str[j + 1],
			env->lum);
	env->m[0].img_str[i + 2] = luminosite(env->text[b].img_str[j + 2],
			env->lum);
	flou = 100 - env->h_life;
	flou < 0 ? flou = 0 : flou;
	env->m[0].img_str[i + 3] = (char)flou;
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

double		calc_ac_sol(t_env *env, double y)
{
	double ac_sol;

	ac_sol = (env->d_ecran * ((env->d_ecran * env->h_mur)
		/ 2 + env->h_jump)) / (y - env->h_regard);
	ac_sol = ac_sol / env->d_ecran;
	ac_sol = ac_sol / cos((env->angle - env->d_regard) * M_PI / 180);
	return (ac_sol);
}

void		affichage_sol(double y, double h_percue, t_env *env)
{
	double ac_sol;
	double pos_perso_x;
	double pos_perso_y;

	h_percue = 2;
	pos_perso_x = env->perso_x / (double)env->coef;
	pos_perso_y = env->perso_y / (double)env->coef;
	while (y < W_HEIGHT)
	{
		ac_sol = calc_ac_sol(env, y);
		env->lum = ac_sol * 255 / env->lum_int;
		env->dy = y;
		if (env->tab[(int)pos_sol_y(pos_perso_y, 0, ac_sol, env)]
			[(int)pos_sol_x(pos_perso_x, 0, ac_sol, env)] == DOOR_CLOSE)
			put_texture_floor(pos_sol_x(pos_perso_x, 0, ac_sol, env),
				pos_sol_y(pos_perso_y, 0, ac_sol, env), env, 9);
		else if (env->tab[(int)pos_sol_y(pos_perso_y, 0, ac_sol, env)]
			[(int)pos_sol_x(pos_perso_x, 0, ac_sol, env)] == END)
			put_texture_floor(pos_sol_x(pos_perso_x, 0, ac_sol, env),
				pos_sol_y(pos_perso_y, 0, ac_sol, env), env, 10);
		else
			put_texture_floor(pos_sol_x(pos_perso_x, 0, ac_sol, env),
				pos_sol_y(pos_perso_y, 0, ac_sol, env), env, 0);
		y++;
	}
}
