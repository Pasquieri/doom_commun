/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/08 19:30:09 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_texture_floor(double pos_sol_x, double pos_sol_y, t_env *env, int y)
{
	int p_x;
	int	p_y;
	int	i;
	int	j;

	p_x = (int)(pos_sol_x * 100) % 100; 
	p_y = (int)(pos_sol_y * 100) % 100; 
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(env->text[0].width * p_x / 100)
		+ (int)(env->text[0].height * p_y / 100) * env->text[0].s_l;
	env->m[0].img_str[i] = luminosite(env->text[0].img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(env->text[0].img_str[j + 1], env->lum);
	env->m[0].img_str[i + 2] = luminosite(env->text[0].img_str[j + 2], env->lum);
	env->m[0].img_str[i + 3] = (char)0;
}

/*void	affichage_sol(double y, t_env *env)
{

	double ac;
	double m;
	double n;
	double tmp;
	double pos_perso_x;
	double pos_perso_y;
	double pos_sol_x;
	double pos_sol_y;
	double alpha;
	double diffalpha;

	alpha = atan((y - env->h_regard) / env->d_ecran);
	diffalpha = fabs(alpha - atan((y + 1 - env->h_regard) / env->d_ecran)) * (180 / M_PI);
	printf("alpha : %f\n",alpha );
	pos_perso_x = env->perso_x / (double)env->coef; // i,??
	pos_perso_y = env->perso_y / (double)env->coef; // j,??
	tmp = (env->h_regard) / ((y - env->h_regard) / env->d_ecran );
	while (y < W_HEIGHT)
	{
		ac = (env->h_regard) / ((double)(y - env->h_regard) / (env->d_ecran * (env->dist / tmp)));
		ac = ac / cos((env->angle - env->d_regard) * M_PI / 180); //algo oeil de poisson
		if (env->angle > 0 && env-> angle <= 90)
		{
			//m = cos((M_PI * env->angle) / 180) * ac;
			//n = sin((M_PI * env->angle) / 180) * ac;
			m = cos((M_PI * alpha) / 180) * ac;
			n = sin((M_PI * alpha) / 180) * ac;
			pos_sol_x = pos_perso_x + m / env->coef;
			pos_sol_y = pos_perso_y - n / env->coef;
			alpha += diffalpha;
		}
		else if (env->angle > 90 && env-> angle <= 180)
		{
			m = -1 * cos((M_PI * env->angle) / 180) * ac;
			n = sin((M_PI * env->angle) / 180) * ac;
			pos_sol_x = pos_perso_x - m / env->coef;
			pos_sol_y = pos_perso_y - n / env->coef;
		}
		else if (env->angle > 180 && env-> angle <= 270)
		{
			m = -1 * cos((M_PI * env->angle) / 180) * ac;
			n = -1 * sin((M_PI * env->angle) / 180) * ac;
			pos_sol_x = pos_perso_x - m / env->coef;
			pos_sol_y = pos_perso_y + n / env->coef;
		}
		else
		{
			m = cos((M_PI * env->angle) / 180) * ac;
			n = -1 * sin((M_PI * env->angle) / 180) * ac;
			pos_sol_x = pos_perso_x + m / env->coef;
			pos_sol_y = pos_perso_y + n / env->coef;
		}
		env->lum = ac * 255 / env->lum_int;
		put_texture_floor(pos_sol_x, pos_sol_y, env, y);
		y++;
	}
}*/

void	affichage_sol(double y, double h_percue, t_env *env)
{

	double ac_sol;
	double m;
	double n;
	double tmp;
	double pos_perso_x;
	double pos_perso_y;
	double pos_sol_x;
	double pos_sol_y;

	double ac;
	ac = env->dist * env->d_ecran;
	double bc;
	bc = env->d_ecran;
	double ddp;
	ddp = env->d_ecran * env->h_mur;
	double eep;
	eep = h_percue;
	double dc;
	dc = ddp / 2 + env->h_jump;
	double ad;
	ad = dc;
	double be;
	be = (bc * ad) / ac; 
	double bk;
	bk = env->h_regard;
	double by = 0;

//	printf("ac:%.1f bc:%.1f dd':%.1f ee':%.1f dc:%.1f be:%.1f bk:%.1f  \n", ac, bc, ddp, eep, dc, be, bk);

	pos_perso_x = env->perso_x / (double)env->coef;
	pos_perso_y = env->perso_y / (double)env->coef;
	tmp = (env->h_regard) / ((y - env->h_regard) / env->d_ecran);

	while (y < W_HEIGHT)
	{
		by = y - bk;
		ac_sol = (bc * ad) / by;
		ac_sol = ac_sol / env->d_ecran;
//		printf("ac_sol: %.1f\n", ac_sol);
		//ac_sol = (env->h_regard) / ((double)(y - env->h_regard) / (env->d_ecran * (env->dist / tmp)));
		ac_sol = ac_sol / cos((env->angle - env->d_regard) * M_PI / 180); //algo oeil de poisson
		if (env->angle > 0 && env-> angle <= 90)
		{
			m = cos((M_PI * env->angle) / 180) * ac_sol;
			n = sin((M_PI * env->angle) / 180) * ac_sol;
			pos_sol_x = pos_perso_x + m / env->coef;
			pos_sol_y = pos_perso_y - n / env->coef;
		}
		else if (env->angle > 90 && env-> angle <= 180)
		{
			m = -1 * cos((M_PI * env->angle) / 180) * ac_sol;
			n = sin((M_PI * env->angle) / 180) * ac_sol;
			pos_sol_x = pos_perso_x - m / env->coef;
			pos_sol_y = pos_perso_y - n / env->coef;
		}
		else if (env->angle > 180 && env-> angle <= 270)
		{
			m = -1 * cos((M_PI * env->angle) / 180) * ac_sol;
			n = -1 * sin((M_PI * env->angle) / 180) * ac_sol;
			pos_sol_x = pos_perso_x - m / env->coef;
			pos_sol_y = pos_perso_y + n / env->coef;
		}
		else
		{
			m = cos((M_PI * env->angle) / 180) * ac_sol;
			n = -1 * sin((M_PI * env->angle) / 180) * ac_sol;
			pos_sol_x = pos_perso_x + m / env->coef;
			pos_sol_y = pos_perso_y + n / env->coef;
		}
		env->lum = ac_sol * 255 / env->lum_int;
		put_texture_floor(pos_sol_x, pos_sol_y, env, y);
		y++;
	}
}

