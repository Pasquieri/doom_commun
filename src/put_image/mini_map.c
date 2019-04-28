/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:53:44 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/28 18:05:34 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	init_coord(t_coord *coord1, t_coord *coord3, t_env *env)
{
	coord3->x = coord1->x;
	coord3->y = coord1->y - env->coef;
}

void		quadrillage(t_env *env)
{
	int		i;
	int		j;
	t_coord	coord1;
	t_coord	coord2;
	t_coord	coord3;

	j = -1;
	while (++j <= env->y)
	{
		coord1.y = j * env->coef;
		coord2.y = j * env->coef;
		i = -1;
		while (++i <= env->x)
		{
			coord1.x = i * env->coef;
			coord2.x = (i + 1) * env->coef;
			if ((i + 1) <= env->x)
				ft_trace_seg(env, coord1, coord2);
			if (j > 0)
			{
				init_coord(&coord1, &coord3, env);
				ft_trace_seg(env, coord1, coord3);
			}
		}
	}
}

static void	cercle(t_env *env, t_cercle param)
{
	int x;
	int y;
	int m;

	x = 0;
	y = param.rayon;
	m = 5 - 4 * param.rayon;
	while (x <= y)
	{
		put_pxl_img(env, x + param.coord.x, -y + param.coord.y, param.color);
		put_pxl_img(env, y + param.coord.x, -x + param.coord.y, param.color);
		put_pxl_img(env, y + param.coord.x, x + param.coord.y, param.color);
		put_pxl_img(env, x + param.coord.x, y + param.coord.y, param.color);
		put_pxl_img(env, -x + param.coord.x, y + param.coord.y, param.color);
		put_pxl_img(env, -x + param.coord.x, -y + param.coord.y, param.color);
		put_pxl_img(env, -y + param.coord.x, x + param.coord.y, param.color);
		put_pxl_img(env, -y + param.coord.x, -x + param.coord.y, param.color);
		if (m > 0)
		{
			y--;
			m = m - 8 * y;
		}
		x++;
		m = m + 8 * x + 4;
	}
}

void		print_cercle(t_env *env)
{
	t_cercle	param_cercle;

	param_cercle.coord.x = env->perso_x;
	param_cercle.coord.y = env->perso_y;
	param_cercle.rayon = 5;
	param_cercle.color = 3;
	while (param_cercle.rayon >= 0)
	{
		cercle(env, param_cercle);
		param_cercle.rayon--;
	}
}
