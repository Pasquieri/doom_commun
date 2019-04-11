/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/11 18:19:26 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_sprite_grid(t_env *env, double h_percue, int y, t_mlx *sp_t)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	if (env->orientation == 0)
		p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
	else
		p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
	if (y > (env->h_regard - (h_percue / 2)))
		p_y = (y - (env->h_regard - (h_percue / 2.))) * 100. / h_percue;
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
//		env->m[0].img_str[i] = (char)150;
//		env->m[0].img_str[i + 1] = (char)100;
//		env->m[0].img_str[i + 2] = (char)250;
	}
}

/*static void	give_p_x(float *p_x, t_env *env)
{
	int	perso_i;
	int	perso_j;
	int	sp_i;
	int	sp_j;

	perso_i = (int)(env->perso_x / env->coef);
	perso_j = (int)(env->perso_y / env->coef);
	sp_i = (int)(env->coord_spr.x / env->coef);
	sp_j = (int)(env->coord_spr.y / env->coef);
	if (perso_j == sp_j)
		*p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
	else if (perso_i == sp_i)
		*p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
	else
	{
		if (env->d_regard >= 0 && env->d_regard < 90)
		{
			if (env->orientation == 1)
				*p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
			else
				*p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
		}
		else if (env->d_regard >= 90 && env->d_regard < 360) // tjrs pareil --'
		{
			if (env->orientation == 1)
				*p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
			else
				*p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
		}
	}
}*/

static void	put_sprite_img(t_env *env, double h_percue, int y, t_mlx *sp_t)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;


	//give_p_x(&p_x, env);
	if (env->orientation == 0)
		p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
	else
		p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
	if (y > (env->h_regard - (h_percue / 2)))
		p_y = (y - (env->h_regard - (h_percue / 2.))) * 100. / h_percue;
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
//		env->m[0].img_str[i] = (char)150;
//		env->m[0].img_str[i + 1] = (char)100;
//		env->m[0].img_str[i + 2] = (char)250;
	}
}

static void	affiche_sprite(double d_sprite, t_env *env, int i, int cmp)
{
	double	y;
	double	lim;
	double	h_percue;
	int	a;
	int	b;

	if (i == 5)
	{
		a = env->sp[i].sprite[cmp].i;
		b = env->sp[i].sprite[cmp].j;
		env->sp[i].sprite[cmp].open = 1;
		env->tab[b][a] == 7 ? env->sp[i].sprite[cmp].open = 0 : env->sp[i].sprite[cmp].open;
		if (d_sprite < (3 * env->coef / 2))
			env->sp[i].sprite[cmp].proximity = 1;
		else
			env->sp[i].sprite[cmp].proximity = 0;
		return ;
	}
	h_percue = env->d_ecran * (env->h_mur / d_sprite);
	y = env->h_regard - (h_percue / 2);
	y < 0. ? y = -1. : y;
	lim = env->h_regard + (h_percue / 2);
	if ((i + 10) == GRID || (i + 10) == WIN)
		while (++y < lim && y < W_HEIGHT)
			put_sprite_grid(env, h_percue, y, &env->sp_t[i]);
	else
		while (++y < lim && y < W_HEIGHT)
			put_sprite_img(env, h_percue, y, &env->sp_t[i]);
}

static double	ft_distance(t_env *env, int i, int cmp)
{
	double	dist0;
	double	dist1;
	double	d;

	if (env->sp[i].sprite[cmp].detec[0].on == 1)
		dist0 = env->sp[i].sprite[cmp].detec[0].dist;
	else
		dist0 = env->sp[i].sprite[cmp].detec[1].dist + 1;
	if (env->sp[i].sprite[cmp].detec[1].on == 1)
		dist1 = env->sp[i].sprite[cmp].detec[1].dist;
	else
		dist1 = env->sp[i].sprite[cmp].detec[0].dist + 1;
	env->orientation = 0;
	dist1 < dist0 ? env->orientation = 1 : env->orientation;
	d = dist0;
	dist1 < dist0 ? d = dist1 : d;
	env->coord_spr = env->sp[i].sprite[cmp].detec[env->orientation].cd;
	return (d);
}

void	print_sprite(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sprite;

	i = -1;
	while (++i < 6) // < 5 pour tous les sprites sp[4] = monkey
	{
		if (i == 4)
			i++;
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if ((env->sp[i].sprite[cmp].detec[0].on == 1)
					|| (env->sp[i].sprite[cmp].detec[1].on == 1))
			{
				d_sprite = ft_distance(env, i, cmp);
				//do_door(env, i, cmp, d_sprite);
			//	if (env->sp[i].val == COLUMN || env->sp[i].val == BANANA)
			//		d_sprite = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd.x, 2)
			//				+ pow(env->perso_y - env->sp[i].sprite[cmp].cd.y, 2));
				env->lum = d_sprite * 255 / env->lum_int;
				if (d_sprite <= env->dist)
					affiche_sprite(d_sprite, env, i, cmp);
			}
			env->sp[i].sprite[cmp].detec[0].on = 0;
			env->sp[i].sprite[cmp].detec[1].on = 0;
		}
	}
}

/* test sprite */

/*static void	print_sprite_grid(t_env *env) // GRID && WIN
{
	int	i;
	int	cmp;
	double	d_sprite;
	double	h_percue;

	i = -1;
	while (++i < 2) // QUE GRID && WIN : 0 && 1
	{
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if ((env->sp[i].sprite[cmp].detec[0].on == 1)
					|| (env->sp[i].sprite[cmp].detec[1].on == 1))
			{
				d_sprite = ft_distance(env, i, cmp);
				env->lum = d_sprite * 255 / env->lum_int;
				h_percue = env->d_ecran * (env->h_mur / d_sprite);
				if (d_sprite <= env->dist)
					affiche_sprite(h_percue, env, i);
			}
			env->sp[i].sprite[cmp].detec[0].on = 0;
			env->sp[i].sprite[cmp].detec[1].on = 0;
		}
	}
}

void	print_sprite(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sprite;
	double	h_percue;

	print_sprite_grid(env);
	i = 1;
	while (++i < 4)  // COLUMN && BANANA : 2 && 3
	{
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if ((env->sp[i].sprite[cmp].detec[0].on == 1)
					|| (env->sp[i].sprite[cmp].detec[1].on == 1))
			{
				d_sprite = ft_distance(env, i, cmp);
				if (env->sp[i].val == COLUMN || env->sp[i].val == BANANA)
					d_sprite = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd.x, 2) + pow(env->perso_y - env->sp[i].sprite[cmp].cd.y, 2));
			//	env->coord_spr = env->sp[i].sprite[cmp].cd;
				env->lum = d_sprite * 255 / env->lum_int;
				h_percue = env->d_ecran * (env->h_mur / d_sprite);
				if (d_sprite <= env->dist)
					affiche_sprite(h_percue, env, i);
			}
			env->sp[i].sprite[cmp].detec[0].on = 0;
			env->sp[i].sprite[cmp].detec[1].on = 0;
		}
	}
}*/

//	printf("coord milieu : (%f,%f), coord_spr : (%f,%f)\n", env->sp[i].sprite[cmp].cd.x, env->sp[i].sprite[cmp].cd.y, env->coord_spr.x, env->coord_spr.y);

			/*if (env->sp[i].sprite[cmp].detec[0].on == 1)
				printf("i = %d horizontal DETEC : %d\n",i, i + 10);
			if (env->sp[i].sprite[cmp].detec[1].on == 1)
				printf("i = %d vertical DETEC : %d\n\n",i, i + 10);*/
