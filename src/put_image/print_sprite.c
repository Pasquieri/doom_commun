/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/06 10:07:43 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	print_gun(t_env *env, int k)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 600; // position dans la fenetre (x,y);
	y = 665;
	while (++y < 870)
	{
		x = 600;
		while (++x <= (600 + (env->inv.lim_gun[k] - env->inv.lim_gun[k - 1])))
		{
			i = 4 * x + y * env->m[0].s_l;
			j = 4 * (x - 600 + env->inv.lim_gun[k - 1]) + (y - 665) * env->sp_t[6].s_l; // + lim[0] pour decaler la limite d'avant pour la bonne image
			if (env->sp_t[6].img_str[j + 3] != -1) // si pas transparent
			{
				env->m[0].img_str[i] = env->sp_t[6].img_str[j]; // sp[6] == gun
				env->m[0].img_str[i + 1] = env->sp_t[6].img_str[j + 1];
				env->m[0].img_str[i + 2] = env->sp_t[6].img_str[j + 2];
				env->m[0].img_str[i + 3] = env->sp_t[6].img_str[j + 3];
			}
		}
	}
}

static void	put_sprite_img(t_env *env, double h_percue, int y, t_mlx *sp_t)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	if (env->orientation == 0)
		p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef; ///
	else
		p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
	if (y > (env->h_regard - (h_percue / 2)))
		p_y = (y - (env->h_regard - (h_percue / 2.))) * 100. / h_percue;
	else
		p_y = y * 100. / h_percue;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(sp_t->width * p_x / 100)
		+ (int)(sp_t->height * p_y / 100) * sp_t->s_l;
//	if (sp_t->img_str[j + 3] != -1) // si pas transparent
	{
//	env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
//	env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
//	env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
//	env->m[0].img_str[i + 3] = (char)0;
		env->m[0].img_str[i] = (char)150;
		env->m[0].img_str[i + 1] = (char)100;
		env->m[0].img_str[i + 2] = (char)250;
	}
}

static void	affiche_sprite(double h_percue, t_env *env, int i)
{
	int	y;
	float	lim;

	y = env->h_regard - (h_percue / 2) - 1;
	y < 0 ? y = -1 : y;
	lim = env->h_regard + (h_percue / 2);
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
		dist0 = env->sp[i].sprite[cmp].detec[1].dist;
	if (env->sp[i].sprite[cmp].detec[1].on == 1)
		dist1 = env->sp[i].sprite[cmp].detec[1].dist;
	else
		dist1 = env->sp[i].sprite[cmp].detec[0].dist;
	d = dist0;
	env->orientation = 0;
	env->coord_spr = env->sp[i].sprite[cmp].detec[0].cd;
	dist1 < dist0 ? d = dist1 : d;
	dist1 < dist0 ? env->orientation = 1 : env->orientation;
	dist1 < dist0 ? env->coord_spr = env->sp[i].sprite[cmp].detec[1].cd : env->coord_spr;
	return (d);
}

void	print_sprite(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sprite;
	double	h_percue;

	i = -1;
	while (++i < 4) // < 5 pour tous les sprites sp[4] = monkey
	{
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			//if (env->sp[i].sprite[cmp].detec[0].on == 1)
			//	printf("i = %d horizontal DETEC : %d\n",i, i + 10);
			//if (env->sp[i].sprite[cmp].detec[1].on == 1)
			//	printf("i = %d vertical DETEC : %d\n\n",i, i + 10);
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
