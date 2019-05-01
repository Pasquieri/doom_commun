/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 20:52:04 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

int			verif_hor_grid(t_env *env, t_coord *coord, int k, int cmp)
{
	int	i;
	int	j;

	if (init_coord_lim(env, coord) == -1)
		return (-1);
	i = (int)(coord->x / env->coef);
	j = (int)(coord->y / env->coef);
	if (i < env->x && j < env->x)
	{
		if (i == env->sp[k].sprite[cmp].i && j == env->sp[k].sprite[cmp].j)
			return (1);
		j = ((coord->y) - 1) / env->coef;
		if (i == env->sp[k].sprite[cmp].i && j == env->sp[k].sprite[cmp].j)
			return (1);
	}
	return (0);
}

int			verif_ver_grid(t_env *env, t_coord *coord, int k, int cmp)
{
	int	i;
	int	j;

	if (init_coord_lim(env, coord) == -1)
		return (-1);
	i = (int)(coord->x / env->coef);
	j = (int)(coord->y / env->coef);
	if (i < env->x && j < env->x)
	{
		if (i == env->sp[k].sprite[cmp].i && j == env->sp[k].sprite[cmp].j)
			return (1);
		i = ((coord->x) - 1) / env->coef;
		if (i == env->sp[k].sprite[cmp].i && j == env->sp[k].sprite[cmp].j)
			return (1);
	}
	return (0);
}

static void	print_sprite(double d_sprite, t_env *env, int k)
{
	double	y;
	double	lim;
	double	h_percue;
	double	bep;

	bep = (env->d_ecran * ((env->d_ecran * env->h_mur) / 2 - env->h_jump))
		/ (d_sprite * env->d_ecran);
	h_percue = env->d_ecran * (env->h_mur / d_sprite);
	y = env->h_regard - bep;
	lim = y + h_percue;
	y < 0. ? y = -1. : y;
	if ((k + 10) == GRID || (k + 10) == WIN)
		while (++y < lim && y < W_HEIGHT)
		{
			env->img_y = y;
			if ((k + 10) == GRID || ((int)y + env->img_x) % 2 == 0)
				put_sprite_grid(env, h_percue, &env->sp_t[k], bep);
		}
}

void		print_sprite_wall(t_env *env, int i, int cmp)
{
	int		xf;
	double	a;
	double	dist;

	env->img_x = env->sp[i].sprite[cmp].win_x;
	xf = env->sp[i].sprite[cmp].win_x_f;
	a = verif_angle(env->sp[i].sprite[cmp].a_i);
	while (++env->img_x <= xf && env->img_x < W_WIDTH)
	{
		env->angle = verif_angle(a);
		dist = detection_grid_win(env, i, cmp);
		dist = dist * cos((a - env->d_regard) * M_PI / 180);
		env->lum = dist * 255 / env->lum_int;
		print_sprite(dist, env, i);
		a -= (60. / W_WIDTH);
	}
}
