/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:18:07 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/03 14:34:24 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/03 14:13:15 by cpalmier         ###   ########.fr       */
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

void	affichage_sol(int x, int y, t_env *env)
{

	double ac;
	double m;
	double n;
	double tmp;
	double pos_perso_x;
	double pos_perso_y;
	double pos_sol_x;
	double pos_sol_y;

	pos_perso_x = env->perso_x / (double)env->coef;
	pos_perso_y = env->perso_y / (double)env->coef;
	tmp = (env->h_regard) / ((y - env->h_regard) / env->d_ecran );
	while (y < W_HEIGHT)
	{

		ac = (env->h_regard) / ((double)(y - env->h_regard) / (env->d_ecran * (env->dist / tmp)));
		ac = ac / cos((env->angle - env->d_regard) * M_PI / 180); //algo oeil de poisson
		if (env->angle > 0 && env-> angle <= 90)
		{
			m = cos((M_PI * env->angle) / 180) * ac;
			n = sin((M_PI * env->angle) / 180) * ac;
			pos_sol_x = pos_perso_x + m / env->coef;
			pos_sol_y = pos_perso_y - n / env->coef;
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
		(void)x;
		env->lum = ac * 255 / env->lum_int;
		put_texture_floor(pos_sol_x, pos_sol_y, env, y);
/*		if (((int)pos_sol_x + (int)pos_sol_y) % 2 == 1)
			put_pxl_img(env, x, W_HEIGHT - e, 7);
		else
			put_pxl_img(env, x, W_HEIGHT - e, 6);*/
		put_texture_sky(pos_sol_x, pos_sol_y, env, W_HEIGHT - y);
		y++;
	}
}
