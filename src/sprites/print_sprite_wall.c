/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 19:11:17 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static int	init_coord_lim(t_env *env, t_coord *coord)
{
	int	lim;

	lim = env->x * env->coef;
	if (coord->x > lim || coord->y > lim || coord->x < 0 || coord->y < 0)
	{
		coord->x > lim ? coord->x = lim : coord->x;
		coord->y > lim ? coord->y = lim : coord->y;
		coord->x < 0 ? coord->x = 0 : coord->x;
		coord->y < 0 ? coord->y = 0 : coord->y;
		return (-1);
	}
	return (0);
}

static int		verif_hor_grid(t_env *env, t_coord *coord, int k, int cmp)
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

static int		verif_ver_grid(t_env *env, t_coord *coord, int k, int cmp)
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

static double	ft_distance(t_coord coord1, t_coord coord2, t_env *env)
{
	double	dist1;
	double	dist2;
	t_coord	perso;

	perso.x = env->perso_x;
	perso.y = env->perso_y;
	dist1 = sqrt(pow(perso.x - coord1.x, 2) + pow(perso.y - coord1.y, 2));
	dist2 = sqrt(pow(perso.x - coord2.x, 2) + pow(perso.y - coord2.y, 2));
	if (dist1 <= dist2)
	{
		env->orientation = 0;
		env->coord_spr = coord1;
		return (dist1);
	}
	else
	{
		env->orientation = 1;
		env->coord_spr = coord2;
		return (dist2);
	}
}

static double	detection_grid_win(t_env *env, int k, int cmp)
{
	double	xa;
	double	ya;
	t_coord	coord1;
	t_coord	coord2;
	t_coef	coef;

	init_var_hor(env, &ya, &xa, &coord1);
	coef_hor(env, &coef.x, &coef.y);
	while (verif_hor_grid(env, &coord1, k, cmp) == 0)
	{
		coord1.x += (xa * coef.x);
		coord1.y += (ya * coef.y);
	}
	init_var_ver(env, &ya, &xa, &coord2);
	coef_ver(env, &coef.x, &coef.y);
	while (verif_ver_grid(env, &coord2, k, cmp) == 0)
	{
		coord2.x += (xa * coef.x);
		coord2.y += (ya * coef.y);
	}
	return (ft_distance(coord1, coord2, env));
}

static void	put_sprite_grid(t_env *env, double h_p, int y, t_mlx *sp_t, double bep)
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
		p_y = (y - (env->h_regard - bep)) * 100. / h_p;
	else
		p_y = y * 100. / h_p;
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
			if ((k + 10) == GRID || ((int)y + env->img_x) % 2 == 0)
				put_sprite_grid(env, h_percue, y, &env->sp_t[k], bep);
		}
}

void	print_sprite_wall(t_env *env, int i, int cmp)
{
	int	xf;
	double	a;
	double	dist;
//	double	h_percue;

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
