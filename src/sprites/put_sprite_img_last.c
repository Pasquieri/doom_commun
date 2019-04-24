/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/23 16:48:14 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_sprite(t_env *env, double h_percue, int y, t_mlx *sp_t, double d_sol, double det, double a1)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

//	p_x = env->img_x * 100. / h_percue;
//	(void)det;
//	(void)a1;
	p_x = det * 100. / a1;

	if (y > (env->h_regard + d_sol))
		p_y = (y - (env->h_regard + d_sol)) * 100. / h_percue;
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
	double	hauteur;
	double	d_sol;

	hauteur = env->h_mur;
	if (i == 3 || i == 8)
		hauteur /= 3;
	h_percue = env->d_ecran * (hauteur / d_sp);
	d_sol = - h_percue / 2;
	if (i == 3 || i == 8)
		d_sol = h_percue / 2;

	double	a1;
	double	a2;
	double	det;
	a2 = env->sp[i].sprite[cmp].t.a2;
	a1 = env->sp[i].sprite[cmp].t.a1 - a2;
	det = env->sp[i].sprite[cmp].f_angle - a2;

/*	double	x;
	double	p;
	env->img_x = env->sp[i].sprite[cmp].f_win_x;
	p = det * 100. / a1;
	x = p * h_percue / 100;
	while (x < h_percue && env->img_x < W_WIDTH)
	{
		y = env->h_regard + d_sol;
		y < 0. ? y = -1. : y;
		lim = y + h_percue;
		while (++y < lim && y < W_HEIGHT) // reste cette partie a modifier ...
			put_sprite(env, h_percue, y, &env->sp_t[i], d_sol, x);
	//	det -= (60. / W_WIDTH);
		env->img_x++;
		x++;
	}*/
	env->img_x = env->sp[i].sprite[cmp].f_win_x;
	while (det > 0. && env->img_x < W_WIDTH)
	{
		y = env->h_regard + d_sol;
		y < 0. ? y = -1. : y;
		lim = y + h_percue;
		while (++y < lim && y < W_HEIGHT) // reste cette partie a modifier ...
			put_sprite(env, h_percue, y, &env->sp_t[i], d_sol, det, a1);
		det -= (60. / W_WIDTH);
		env->img_x++;
	}
}

static	void	init_win_x(t_env *env, int i, int cmp)
{
//	double	d_h;
//	double	d_v;

/*	if (env->sp[i].sprite[cmp].detec[0].on == 1 && env->sp[i].sprite[cmp].detec[1].on == 1)
	{
		if (env->sp[i].sprite[cmp].win_h_x < env->sp[i].sprite[cmp].win_v_x)
		{
			d_h = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_h.x, 2)
				+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_h.y, 2));
			d_v = d_h + 1;
		}
		else if (env->sp[i].sprite[cmp].win_v_x < env->sp[i].sprite[cmp].win_h_x)
		{
			d_v = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_v.x, 2)
				+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_v.y, 2));
			d_h = d_v + 1;
		}
		else
		{
			d_h = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_h.x, 2)
				+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_h.y, 2));
			d_v = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_v.x, 2)
				+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_v.y, 2));
		}
	}
	else
	{
		if (env->sp[i].sprite[cmp].detec[0].on == 1)
		{
			d_h = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_h.x, 2)
				+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_h.y, 2));
			d_v = d_h + 1;
		}
		else
		{
			d_v = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_v.x, 2)
				+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_v.y, 2));
			d_h = d_v + 1;
		}
	}

	if (env->sp[i].sprite[cmp].detec[0].on == 1)
		d_h = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_h.x, 2)
			+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_h.y, 2));
	else
		d_h = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_v.x, 2)
		+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_v.y, 2)) + 1;
	if (env->sp[i].sprite[cmp].detec[1].on == 1)
		d_v = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_v.x, 2)
			+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_v.y, 2));
	else
		d_v = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_h.x, 2)
		+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_h.y, 2)) + 1;

	if (d_h < d_v)
	{*/
		/****************** 18/04/19 ************************/
/*		env->sp[i].sprite[cmp].f_int = env->sp[i].sprite[cmp].cd_h;
		env->sp[i].sprite[cmp].f_win_x = env->sp[i].sprite[cmp].win_h_x;
		env->sp[i].sprite[cmp].f_angle = env->sp[i].sprite[cmp].angle_h;
		*//****************************************************/
/*	}
	else
	{*/
		/******************* 18/04/19 **************************/
/*		env->sp[i].sprite[cmp].f_int = env->sp[i].sprite[cmp].cd_v;
		env->sp[i].sprite[cmp].f_win_x = env->sp[i].sprite[cmp].win_v_x;
		env->sp[i].sprite[cmp].f_angle = env->sp[i].sprite[cmp].angle_v;
		*//********************************************************/
//	}
	env->sp[i].sprite[cmp].f_int = env->sp[i].sprite[cmp].cd_i;
	env->sp[i].sprite[cmp].f_win_x = env->sp[i].sprite[cmp].win_x;
	env->sp[i].sprite[cmp].f_angle = env->sp[i].sprite[cmp].a_i;
//	printf("angle first int : %f\n", env->sp[i].sprite[cmp].t.angle_f_int);
}

static void	init_lim_cd(t_env *env, int k, int cmp)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = env->perso_x / env->coef;
	j = env->perso_y / env->coef;
	x = env->sp[k].sprite[cmp].c.mid.x;
	y = env->sp[k].sprite[cmp].c.mid.y;

/*	if (i == env->sp[k].sprite[cmp].i && j != env->sp[k].sprite[cmp].j)
	{
		if (env->d_regard > 0 && env->d_regard <= 180)
		{
			env->sp[k].sprite[cmp].coin1 = env->sp[k].sprite[cmp].c.left_b;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.right_b;
		}
		else
		{
			env->sp[k].sprite[cmp].coin1 = env->sp[k].sprite[cmp].c.right_h;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.left_h;
		}
	}
	else if (j == env->sp[k].sprite[cmp].j && i != env->sp[k].sprite[cmp].i)
	{
		if (env->d_regard > 90 && env->d_regard <= 270)
		{
			env->sp[k].sprite[cmp].coin1 = env->sp[k].sprite[cmp].c.right_b;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.right_h;
		}
		else
		{
			env->sp[k].sprite[cmp].coin1 = env->sp[k].sprite[cmp].c.left_h;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.left_b;
		}
	}
	else*/
	{
		if (env->perso_x <= x && env->perso_y <= y)
		{
			env->sp[k].sprite[cmp].coin1 = env->sp[k].sprite[cmp].c.right_h;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.left_b;
		}
		else if (env->perso_x > x && env->perso_y <= y)
		{
			env->sp[k].sprite[cmp].coin1 = env->sp[k].sprite[cmp].c.right_b;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.left_h;
		}
		else if (env->perso_x > x && env->perso_y > y)
		{
			env->sp[k].sprite[cmp].coin1 = env->sp[k].sprite[cmp].c.left_b;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.right_h;
		}
		else if (env->perso_x <= x && env->perso_y > y)
		{
			env->sp[k].sprite[cmp].coin1  = env->sp[k].sprite[cmp].c.left_h;
			env->sp[k].sprite[cmp].coin2 = env->sp[k].sprite[cmp].c.right_b;
		}
	}
}

static void	init_angle(t_env *env, int k, int cmp)
{
	t_coord	pt1;
	t_coord	pt2;
	double	A;
	double	H;
	double	alpha;
// 1 //
	pt1.x = env->sp[k].sprite[cmp].coin1.x;
	pt1.y = env->perso_y;
	pt2.x = env->perso_x;
	pt2.y = env->sp[k].sprite[cmp].coin2.y;
// 2 //
	A = sqrt(pow(env->perso_x - pt1.x, 2) + pow(env->perso_y - pt1.y, 2));
	H = sqrt(pow(env->perso_x - env->sp[k].sprite[cmp].coin1.x, 2)
		+ pow(env->perso_y - env->sp[k].sprite[cmp].coin1.y, 2));
	alpha = acos(A/H) * 180 / M_PI;
// 3.1 //
	if (env->perso_x > env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y < env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a1 = alpha + 180.;
	else if (env->perso_x < env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y < env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a1 = 360. - alpha;
	else if (env->perso_x < env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y > env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a1 = alpha;
	else if (env->perso_x > env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y > env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a1 = 180. - alpha;
//	printf("alpha : %f, a1 : %f, env->angle : %f\n", alpha, env->sp[k].sprite[cmp].t.a1, env->sp[k].sprite[cmp].t.angle_f_int);
// 3.2 //
	A = sqrt(pow(env->perso_x - pt2.x, 2) + pow(env->perso_y - pt2.y, 2));
	H = sqrt(pow(env->perso_x - env->sp[k].sprite[cmp].coin2.x, 2)
		+ pow(env->perso_y - env->sp[k].sprite[cmp].coin2.y, 2));
	alpha = acos(A/H) * 180 / M_PI;
	if (env->perso_x > env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y < env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a2 = 270. - alpha;
	else if (env->perso_x < env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y < env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a2 = 270. + alpha;
	else if (env->perso_x < env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y > env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a2 = 90. - alpha;
	else if (env->perso_x > env->sp[k].sprite[cmp].c.mid.x
			&& env->perso_y > env->sp[k].sprite[cmp].c.mid.y)
		env->sp[k].sprite[cmp].t.a2 = 90. + alpha;
//	printf("alpha : %f, a2 : %f, env->angle : %f\n", alpha, env->sp[k].sprite[cmp].t.a2, env->sp[k].sprite[cmp].t.angle_f_int);
}

void	put_sprite_img(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sp;

	i = 1;
	while (++i < NB_SP) // < 5 pour tous les sprites sp[4] = monkey
	{
		if (i == 5) // porte + tableau + gun
			i += 3;
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if (env->sp[i].sprite[cmp].det == 1)
			{
				d_sp = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].c.mid.x, 2)
					+ pow(env->perso_y - env->sp[i].sprite[cmp].c.mid.y, 2));
				env->lum = d_sp * 255 / env->lum_int;

				init_win_x(env, i, cmp); // inutile si deja fait ds check_sprite
				init_lim_cd(env, i , cmp);
				init_angle(env, i, cmp);
				//if (d_sp <= env->dist) // a gerer d'une certaine maniere ...
				affiche_sprite(d_sp, env, i, cmp);
			}
		}
	}
}