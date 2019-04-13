/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_plafond.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/08 17:03:53 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_texture_sky(double pos_sol_x, double pos_sol_y, t_env *env, int y)
{
	int p_x;
	int	p_y;
	int	i;
	int	j;

	p_x = (int)(pos_sol_x * 100) % 100; 
	p_y = (int)(pos_sol_y * 100) % 100; 
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(env->text[21].width * p_x / 100)
		+ (int)(env->text[21].height * p_y / 100) * env->text[21].s_l;
	env->m[0].img_str[i] = luminosite(env->text[21].img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(env->text[21].img_str[j + 1], env->lum);
	env->m[0].img_str[i + 2] = luminosite(env->text[21].img_str[j + 2], env->lum);
	env->m[0].img_str[i + 3] = (char)0;
}

void	affichage_plafond(double y, double h_percue, t_env *env)
{

	double ac_plafond;
	double m;
	double n;
	double tmp;
	double pos_perso_x;
	double pos_perso_y;
	double pos_plafond_x;
	double pos_plafond_y;

	double ac;
	ac = env->dist * env->d_ecran;
	double bc;
	bc = env->d_ecran;
	double ddp;
	ddp = env->d_ecran * env->h_mur;
	double eep;
	eep = h_percue;
	double cdp;
	cdp = ddp / 2 - env->h_jump;
	double adp;
	adp = cdp;
	double bep;
	bep = (bc * adp) / ac; 
	double bk;
	bk = env->h_regard;
	double by = 0;

	pos_perso_x = env->perso_x / (double)env->coef;
	pos_perso_y = env->perso_y / (double)env->coef;
	tmp = (env->h_regard) / ((y - env->h_regard) / env->d_ecran );
	while (y > 0)
	{
		by = bk - y;
		//printf("%.1f\n", by);
		ac_plafond = (bc * adp) / by;
		ac_plafond = ac_plafond / env->d_ecran;

		//ac_plafond = (env->h_regard) / ((double)(y - env->h_regard) / (env->d_ecran * (env->dist / tmp)));
		ac_plafond = ac_plafond / cos((env->angle - env->d_regard) * M_PI / 180); //algo oeil de poisson
		if (env->angle > 0 && env-> angle <= 90)
		{
			m = cos((M_PI * env->angle) / 180) * ac_plafond;
			n = sin((M_PI * env->angle) / 180) * ac_plafond;
			pos_plafond_x = pos_perso_x + m / env->coef;
			pos_plafond_y = pos_perso_y - n / env->coef;
		}
		else if (env->angle > 90 && env-> angle <= 180)
		{
			m = -1 * cos((M_PI * env->angle) / 180) * ac_plafond;
			n = sin((M_PI * env->angle) / 180) * ac_plafond;
			pos_plafond_x = pos_perso_x - m / env->coef;
			pos_plafond_y = pos_perso_y - n / env->coef;
		}
		else if (env->angle > 180 && env-> angle <= 270)
		{
			m = -1 * cos((M_PI * env->angle) / 180) * ac_plafond;
			n = -1 * sin((M_PI * env->angle) / 180) * ac_plafond;
			pos_plafond_x = pos_perso_x - m / env->coef;
			pos_plafond_y = pos_perso_y + n / env->coef;
		}
		else
		{
			m = cos((M_PI * env->angle) / 180) * ac_plafond;
			n = -1 * sin((M_PI * env->angle) / 180) * ac_plafond;
			pos_plafond_x = pos_perso_x + m / env->coef;
			pos_plafond_y = pos_perso_y + n / env->coef;
		}
		env->lum = ac_plafond * 255 / env->lum_int;
		put_texture_sky(pos_plafond_x, pos_plafond_y, env, y);
		y--;
	}
}
