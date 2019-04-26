/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/26 19:36:14 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_sprite_grid(t_env *env, double h_percue, int y, t_mlx *sp_t, double bep)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	if (env->orientation == 0)
			p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
	else
			p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
	if (y > (env->h_regard - bep))
		p_y = (y - (env->h_regard - bep)) * 100. / h_percue;
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
//	test_grid(env, h_percue, y, sp_t); // cf plus bas pour un test
}

static void	check_proximity(double d_sprite, t_env *env, int k, int cmp)
{
	int	a;
	int	b;

	if (k == 5)
	{
		a = env->sp[k].sprite[cmp].i;
		b = env->sp[k].sprite[cmp].j;
		env->sp[k].sprite[cmp].open = 1;
		env->tab[b][a] == 7 ? env->sp[k].sprite[cmp].open = 0 : env->sp[k].sprite[cmp].open;
		if (d_sprite < (3 * env->coef / 2))
			env->sp[k].sprite[cmp].proximity = 1;
		else
			env->sp[k].sprite[cmp].proximity = 0;
	}
	else
	{
		if (d_sprite < env->coef)
			env->sp[k].sprite[cmp].proximity = 1;
		else
			env->sp[k].sprite[cmp].proximity = 0;
	}
}

static void	print_sprite(double d_sprite, t_env *env, int k, int cmp)
{
	double	y;
	double	lim;
	double	h_percue;
	double bep;

	if (k == 5 || k == 7) /************ DOOR **************/
	{
		check_proximity(d_sprite, env, k, cmp);
		return ;
	} /****************************************************/
	bep = (env->d_ecran * ((env->d_ecran * env->h_mur) / 2 - env->h_jump))
		/ (d_sprite * env->d_ecran);
	h_percue = env->d_ecran * (env->h_mur / d_sprite);
	y = env->h_regard - bep;
	y < 0. ? y = -1. : y;
	lim = y + h_percue;
	if ((k + 10) == GRID || (k + 10) == WIN)
		while (++y < lim && y < W_HEIGHT)
		{
			if ((k + 10) == GRID || ((int)y + env->img_x) % 2 == 0)
				put_sprite_grid(env, h_percue, y, &env->sp_t[k], bep);
		}
}

static double	ft_distance(t_env *env, int k, int cmp)
{
	double	dist0;
	double	dist1;

	if (env->sp[k].sprite[cmp].detec[0].on == 1)
		dist0 = env->sp[k].sprite[cmp].detec[0].dist;
	else
		dist0 = env->sp[k].sprite[cmp].detec[1].dist + 1;
	if (env->sp[k].sprite[cmp].detec[1].on == 1)
		dist1 = env->sp[k].sprite[cmp].detec[1].dist;
	else
		dist1 = env->sp[k].sprite[cmp].detec[0].dist + 1;
	env->orientation = 0;
	dist1 < dist0 ? env->orientation = 1 : env->orientation;
	env->coord_spr = env->sp[k].sprite[cmp].detec[env->orientation].cd;
	if (dist1 < dist0)
		return (dist1);
	return (dist0);
}

void	print_sprite_wall(t_env *env)
{
	int	k;
	int	cmp;
	double	d_sprite;

	k = -1;
	while (++k < NB_SP)
	{
		if (k == 6) // 6 = gun && 7 = tableau
			k++;
		//	k += 2;
		cmp = -1;
		while (++cmp < env->sp[k].nb)
		{
			if ((env->sp[k].sprite[cmp].detec[0].on == 1)
					|| (env->sp[k].sprite[cmp].detec[1].on == 1))
			{
				d_sprite = ft_distance(env, k, cmp);
				env->lum = d_sprite * 255 / env->lum_int;
				if (d_sprite <= env->dist)
					print_sprite(d_sprite, env, k, cmp);
			}
			env->sp[k].sprite[cmp].detec[0].on = 0;
			env->sp[k].sprite[cmp].detec[1].on = 0;
		}
	}
}







//	printf("coord milieu : (%f,%f), coord_spr : (%f,%f)\n", env->sp[i].sprite[cmp].cd.x, env->sp[i].sprite[cmp].cd.y, env->coord_spr.x, env->coord_spr.y);

			/*if (env->sp[i].sprite[cmp].detec[0].on == 1)
				printf("i = %d horizontal DETEC : %d\n",i, i + 10);
			if (env->sp[i].sprite[cmp].detec[1].on == 1)
				printf("i = %d vertical DETEC : %d\n\n",i, i + 10);*/





/*********** TEST GRID 4 murs *************/

/*static void	test_grid(t_env *env, double h_percue, int y, t_mlx *sp_t)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;
	t_coord	cd;
	double	dist;

	cd = env->coord_spr;
	if (env->orientation == 0)
	{
		if (env->d_regard >= 0 && env->d_regard < 180)
			cd.y -= env->coef;
		else
			cd.y += env->coef;
		p_x = fmod(cd.x, (float)env->coef) * 100 / env->coef;
	}
	else
	{
		if (env->d_regard >= 90 && env->d_regard < 270)
			cd.x -= env->coef;
		else
			cd.x += env->coef;
		p_x = fmod(cd.y, (float)env->coef) * 100 / env->coef;
	}
	dist = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y , 2));
	dist = dist * cos((env->angle - env->d_regard) * M_PI / 180);
	h_percue = env->d_regard * (env->h_mur / dist);

	if (y > (env->h_regard - (h_percue / 2)))
		p_y = (y - (env->h_regard - (h_percue / 2.))) * 100. / h_percue;
	else
		p_y = y * 100. / h_percue;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(sp_t->width * p_x / 100)
		+ (int)(sp_t->height * p_y / 100) * sp_t->s_l;
	if (!sp_t->img_str[j + 3]) // si pas transparent
	{
	//env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
	//env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
	//env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
	env->m[0].img_str[i + 3] = (char)0;
		env->m[0].img_str[i] = (char)150;
		env->m[0].img_str[i + 1] = (char)100;
		env->m[0].img_str[i + 2] = (char)250;
	}
}*/
