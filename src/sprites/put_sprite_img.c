/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/24 21:28:10 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

/*static void	put_sprite(t_env *env, double h_percue, int y, t_mlx *sp_t, int x, double test)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;


	//	if (env->orientation == 0)
	//		p_x = fmod(COORD.X, (float)env->coef) * 100 / env->coef;
	//	else
	//		p_x = fmod(COORD.Y, (float)env->coef) * 100 / env->coef;
	p_x = x * 100. / h_percue;
	if (y > (env->h_regard + test))
		p_y = (y - (env->h_regard + test)) * 100. / h_percue;
	else
		p_y = y * 100. / h_percue;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(sp_t->width * p_x / 100)
		+ (int)(sp_t->height * p_y / 100) * sp_t->s_l;
	if (!sp_t->img_str[j + 3]) // si pas transparent
	{
		env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
		env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
		env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
		env->m[0].img_str[i + 3] = (char)0;
	}
}*/

/******************* TEST 1 *************************/
static void	put_sprite(t_env *env, double h_percue, int y, t_mlx *sp_t, double diff, double detec, double test)
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
	if (!sp_t->img_str[j + 3]) // si pas transparent
	{
		env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
		env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
		env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
		env->m[0].img_str[i + 3] = (char)0;
	}
}

static void	affiche_sprite(double d_sp, t_env *env, int i, int cmp)
{
	double	y;
	double	lim;
	double	h_percue;
	double	test;

	h_percue = env->d_ecran * (env->h_mur / d_sp);
	y = env->h_regard - (h_percue / 2);
	test = - h_percue / 2;
	if (i == 3 || i == 8) // pour avoir une banane plus petite : a revoir
	{
		h_percue /= 3;
		y = env->h_regard + (h_percue / 2);
		test = h_percue / 2;
	}
	y < 0. ? y = 0. : y;
	lim = y + h_percue;

	double	diff;
	double	detec;
	double	a_i;
	a_i = env->sp[i].sprite[cmp].a_i;
	diff = verif_angle(env->sp[i].sprite[cmp].a1 - env->sp[i].sprite[cmp].a2);
	detec = a_i - env->sp[i].sprite[cmp].a2;
	if (detec < 0)
		detec = (verif_angle(a_i + 90) - verif_angle(env->sp[i].sprite[cmp].a2 + 90));
	detec < 0 ? detec = 0 : detec;
	if (detec > diff)
		detec = diff;

	double	p_x;
	p_x = detec * 100 / diff;
//	printf("            angle i : %f, diff : %f, det : %f, p_x : %f\n", env->sp[i].sprite[cmp].a_i, diff, detec, p_x);

	env->img_x = env->sp[i].sprite[cmp].win_x;
	/***************** TEST 1 : boucle angle *****************/
	while (detec > 0 && env->img_x < W_WIDTH) // <==> boucle sur x
	{
		p_x = detec * 100 / diff;
		env->img_y = y + 1;
		while (env->img_y < lim && env->img_y < W_HEIGHT)
		{
			put_sprite(env, h_percue, env->img_y, &env->sp_t[i], diff, detec, test);
			env->img_y++;
		}
		detec -= (60. / W_WIDTH);
		env->img_x++;
	}
	/*********************************************************/

	/**************** TEST 2 avec p_x calculer pour definir img_x **********/
//	double	p_x;

//	p_x = detec * 100 / diff;
	/*************************************************************************/
//	printf("a1 : %f, a2 : %f, diff : %f\n detec avant : %f, detec apres : %f, win_x : %d, p_x : %f\n", env->sp[i].sprite[cmp].a1, a2, diff, verif_angle(env->sp[i].sprite[cmp].a_i - a2), detec, env->img_x, p_x);
	/***************** Version qui fonctionne sans pourcentage **********/
/*	int		x;
	while (++y < lim && y < W_HEIGHT)
	{
		x = -1;*/
//		x = p_x * h_percue / 100 - 1; /******* TEST 2 **********/
	/*	env->img_x = env->sp[i].sprite[cmp].win_x;
		while (++x < h_percue && env->img_x < W_WIDTH)
		{
			put_sprite(env, h_percue, y, &env->sp_t[i], x, test);
			env->img_x++;
		}
	}*/
	/**********************************************************************/
}

void	put_sprite_img(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sp;
	double	theta;
	t_coord	cd;

	i = 1;
	while (++i < NB_SP) // < 5 pour tous les sprites sp[4] = monkey
	{
		if (i == 5) // porte +  tableau + gun
			i += 3;
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
		//		printf("theta 1 : %f, cd (%f,%f), a1: %f, d_regard %d\n", theta, cd.x, cd.y, env->sp[i].sprite[cmp].a1, env->d_regard);
			//	printf("theta 1 : %f, a1: %f, d_regard %d\n", theta, env->sp[i].sprite[cmp].a1, env->d_regard);
				theta = verif_angle(env->d_regard - 90);
				cd = init_lim_coord(env, i, cmp, theta);
				env->sp[i].sprite[cmp].a2 = init_lim_angle(env, cd);
			//	printf("      2 : %f, a2: %f\n", theta, env->sp[i].sprite[cmp].a2);
		//		printf("      2 : %f, cd (%f,%f), a2: %f\n", theta, cd.x, cd.y, env->sp[i].sprite[cmp].a2);
			//	printf("         sp mid : cd (%f,%f), angle i : %f\n", env->sp[i].sprite[cmp].cd.x, env->sp[i].sprite[cmp].cd.y, env->sp[i].sprite[cmp].a_i);
				affiche_sprite(d_sp, env, i, cmp);
			}
		}
	}
}
