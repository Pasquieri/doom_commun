/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/12 20:50:32 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	put_sprite(t_env *env, double h_percue, int y, t_mlx *sp_t, int x)
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

static void	affiche_sprite(double d_sp, t_env *env, int i, int cmp)
{
	double	y;
	int		x;
	double	lim;
	double	h_percue;

	h_percue = env->d_ecran * (env->h_mur / d_sp);
	y = env->h_regard - (h_percue / 2);
	y < 0. ? y = -1. : y;
	lim = env->h_regard + (h_percue / 2);
	while (++y < lim && y < W_HEIGHT)
	{
		x = env->sp[i].sprite[cmp].win_x - 1;
		while (++x < h_percue)
		{
			env->img_x = x;
			put_sprite(env, h_percue, y, &env->sp_t[i], x - env->sp[i].sprite[cmp].win_x);
		}
	}
}

void	put_sprite_img(t_env *env)
{
	int	i;
	int	cmp;
	double	d_sp;

	i = 1;
	while (++i < 4) // < 5 pour tous les sprites sp[4] = monkey
	{
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if (env->sp[i].sprite[cmp].det == 1)
			{
				d_sp = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd.x, 2)
					+ pow(env->perso_y - env->sp[i].sprite[cmp].cd.y, 2));
				env->lum = d_sp * 255 / env->lum_int;
				if (d_sp <= env->dist)
					affiche_sprite(d_sp, env, i, cmp);
			}
		}
	}
}







//	printf("coord milieu : (%f,%f), coord_spr : (%f,%f)\n", env->sp[i].sprite[cmp].cd.x, env->sp[i].sprite[cmp].cd.y, env->coord_spr.x, env->coord_spr.y);

			/*if (env->sp[i].sprite[cmp].detec[0].on == 1)
				printf("i = %d horizontal DETEC : %d\n",i, i + 10);
			if (env->sp[i].sprite[cmp].detec[1].on == 1)
				printf("i = %d vertical DETEC : %d\n\n",i, i + 10);*/

/*static double	ft_distance(t_env *env, int i, int cmp)
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
}*/
