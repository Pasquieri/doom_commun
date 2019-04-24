/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/24 16:45:14 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static double	verif_angle(double angle)
{
	if (angle < 0.)
	{
		while (angle < 0.)
			angle = angle + 360.;
	}
	else if (angle > 360.)
	{
		while (angle > 360.)
			angle = angle - 360.;
	}
	if (angle == 360.)
		angle = 0;
	return (angle);
}

static void	put_sprite(t_env *env, double h_percue, int y, t_mlx *sp_t, int x, double test)
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
}

/******************* TEST 1 *************************/
/*static void	put_sprite(t_env *env, double h_percue, int y, t_mlx *sp_t, double diff, double detec, double test)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;


	//	if (env->orientation == 0)
	//		p_x = fmod(COORD.X, (float)env->coef) * 100 / env->coef;
	//	else
	//		p_x = fmod(COORD.Y, (float)env->coef) * 100 / env->coef;
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
}*/

static void	affiche_sprite(double d_sp, t_env *env, int i, int cmp)
{
	double	y;
	int		x;
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

	double	a2;
	double	diff;
	double	detec;

	a2 = env->sp[i].sprite[cmp].a2;
	diff = verif_angle(env->sp[i].sprite[cmp].a1 - a2);
	detec = verif_angle(env->sp[i].sprite[cmp].a_i - a2);
	if (detec > diff)
		detec = env->sp[i].sprite[cmp].a1;
	else
		detec = env->sp[i].sprite[cmp].a_i;
	env->img_x = env->sp[i].sprite[cmp].win_x;
	/***************** TEST 1 : boucle angle *****************/
/*	while (detec > 0 && env->img_x < W_WIDTH) // <==> boucle sur x
	{
		env->img_y = y;
		while (env->img_y < lim && env->img_y < W_HEIGHT)
		{
			put_sprite(env, h_percue, env->img_y, &env->sp_t[i], diff, detec, test);
			env->img_y++;
		}
		detec -= (60. / W_WIDTH);
		env->img_x++;
	}*/
	/*********************************************************/

	/**************** TEST 2 avec p_x calculer pour definir img_x **********/
//	double	p_x;

//	p_x = detec * 100 / diff;
	/*************************************************************************/
//	printf("a1 : %f, a2 : %f, diff : %f\n detec avant : %f, detec apres : %f, win_x : %d, p_x : %f\n", env->sp[i].sprite[cmp].a1, a2, diff, verif_angle(env->sp[i].sprite[cmp].a_i - a2), detec, env->img_x, p_x);
	while (++y < lim && y < W_HEIGHT)
	{
		x = -1;
//		x = p_x * h_percue / 100 - 1; /******* TEST 2 **********/
		env->img_x = env->sp[i].sprite[cmp].win_x;
		while (++x < h_percue && env->img_x < W_WIDTH)
		{
			put_sprite(env, h_percue, y, &env->sp_t[i], x, test);
			env->img_x++;
		}
	}
}

static t_coord	init_lim_coord_1(t_env *env, int k, int cmp, double theta)
{
	t_coord	cd_a;
	t_coord	cd_m;
	t_coord	cd_m_p;

	cd_a = env->sp[k].sprite[cmp].cd; // mid
	cd_m.x = cd_a.x + 2.5;
	cd_m.y = cd_a.y;
	cd_m_p.x = (cd_m.x - cd_a.x) * cos(theta * M_PI / 180)+ cd_a.x;
	cd_m_p.y = cd_a.y - (cd_m.x - cd_a.x) * sin(theta * M_PI / 180);
//	printf("cd_a : (%f,%f), cd_m : (%f,%f), cd_m_p : (%f,%f)\n", cd_a.x, cd_a.y, cd_m.x, cd_m.y, cd_m_p.x, cd_m_p.y);
	return (cd_m_p);
}

static t_coord	init_lim_coord_2(t_env *env, int k, int cmp, double theta)
{
	t_coord	cd_a;
	t_coord	cd_m;
	t_coord	cd_m_p;

	cd_a = env->sp[k].sprite[cmp].cd; // mid
	cd_m.x = cd_a.x + 2.5;
	cd_m.y = cd_a.y;

//	cd_m_p.x = cd_a.x - ((cd_m.x - cd_a.x) * cos(theta * M_PI / 180)
//		- (cd_m.y - cd_a.y) * sin(theta * M_PI / 180));
//	cd_m_p.y = cd_a.y + ((cd_m.y - cd_a.y) * cos(theta * M_PI / 180)
//			+ (cd_m.x - cd_a.x) * sin(theta * M_PI / 2));
// simplifie :
	cd_m_p.x = cd_a.x - ((cd_m.x - cd_a.x) * cos(theta * M_PI / 180));
	cd_m_p.y = cd_a.y - (cd_m.x - cd_a.x) * sin(theta * M_PI / 180);
//	printf("cd_a : (%f,%f), cd_m : (%f,%f), cd_m_p : (%f,%f)\n", cd_a.x, cd_a.y, cd_m.x, cd_m.y, cd_m_p.x, cd_m_p.y);

	return (cd_m_p);
}

static double	init_lim_angle_1(t_env *env, t_coord cd, t_coord mid)
{
	double	A;
	double	H;
	double	alpha;
	double	a;
	t_coord	pt_tmp;

	pt_tmp.x = cd.x;
	pt_tmp.y = env->perso_y;
	A = sqrt(pow(env->perso_x - pt_tmp.x, 2) + pow(env->perso_y - pt_tmp.y, 2));
	H = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
	alpha = acos(A/H) * 180 / M_PI;
	a = alpha;
	if (env->perso_x >= mid.x && env->perso_y < mid.y)
		a = alpha + 180.;
	else if (env->perso_x < mid.x && env->perso_y < mid.y)
		a = 360. - alpha;
	else if (env->perso_x < mid.x && env->perso_y >= mid.y)
		a = alpha;
	else if (env->perso_x >= mid.x && env->perso_y >= mid.y)
		a = 180. - alpha;
	return (a);
}

static double	init_lim_angle_2(t_env *env, t_coord cd, t_coord mid)
{
	double	A;
	double	H;
	double	alpha;
	double	a;
	t_coord	pt_tmp;

	pt_tmp.x = env->perso_x;
	pt_tmp.y = cd.y;
	A = sqrt(pow(env->perso_x - pt_tmp.x, 2) + pow(env->perso_y - pt_tmp.y, 2));
	H = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
	alpha = acos(A/H) * 180 / M_PI;
	a = alpha;
	if (env->perso_x >= mid.x && env->perso_y < mid.y)
		a = 270. - alpha;
	else if (env->perso_x < mid.x && env->perso_y < mid.y)
		a = 270. + alpha;
	else if (env->perso_x < mid.x && env->perso_y >= mid.y)
		a = 90. - alpha;
	else if (env->perso_x >= mid.x && env->perso_y >= mid.y)
		a = 90. + alpha;
	return (a);
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
				cd = init_lim_coord_1(env, i, cmp, theta);
				env->sp[i].sprite[cmp].a1 = init_lim_angle_1(env, cd,
						env->sp[i].sprite[cmp].cd);
//printf("theta 1 : %f, cd (%f,%f), a1: %f, d_regard %d\n", theta, cd.x, cd.y, env->sp[i].sprite[cmp].a1, env->d_regard);
				theta = verif_angle(env->d_regard - 90);
				cd = init_lim_coord_2(env, i, cmp, theta);
				env->sp[i].sprite[cmp].a2 = init_lim_angle_2(env, cd,
						env->sp[i].sprite[cmp].cd);
//printf("theta 2 : %f, cd (%f,%f), a2: %f\n", theta, cd.x, cd.y, env->sp[i].sprite[cmp].a2);

				affiche_sprite(d_sp, env, i, cmp);
			}
		}
	}
}
