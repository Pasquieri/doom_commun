/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:53:44 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 19:46:11 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void			color_case_extra(t_env *env, t_color_case *c_case)
{
	while (++c_case->y < (c_case->j * env->coef + env->coef))
	{
		c_case->x = c_case->i * env->coef - 1;
		c_case->color = 1;
		if (env->tab[c_case->j][c_case->i] == 7 ||
				env->tab[c_case->j][c_case->i] == 15)
			c_case->color = 2;
		else if (env->tab[c_case->j][c_case->i] == 10 ||
				env->tab[c_case->j][c_case->i] == 11)
			c_case->color = 3;
		else if (env->tab[c_case->j][c_case->i] == 12 ||
				env->tab[c_case->j][c_case->i] == 13
			|| env->tab[c_case->j][c_case->i] == 16)
			c_case->color = 4;
		else if (env->tab[c_case->j][c_case->i] == END)
			c_case->color = 5;
		while (++c_case->x < (c_case->i * env->coef + env->coef))
			put_pxl_img(env, c_case->x, c_case->y, c_case->color);
	}
}

void				color_case(t_env *env)
{
	t_color_case	c_case;

	c_case.j = -1;
	while (++c_case.j < env->y)
	{
		c_case.i = -1;
		while (++c_case.i < env->x)
		{
			if (((env->tab[c_case.j][c_case.i] > 0
							&& env->tab[c_case.j][c_case.i] <= 7)
					|| (env->tab[c_case.j][c_case.i] >= 9
						&& env->tab[c_case.j][c_case.i] <= 16))
					&& env->tab[c_case.j][c_case.i] != 14)
			{
				c_case.y = c_case.j * env->coef - 1;
				color_case_extra(env, &c_case);
			}
		}
	}
}

static void			cercle(t_env *env, t_cercle param)
{
	int				x;
	int				y;
	int				m;

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

void				print_cercle(t_env *env)
{
	t_cercle		param_cercle;

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
