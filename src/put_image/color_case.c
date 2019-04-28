/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:57:17 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/28 23:57:19 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	color_case2(t_env *env, int i, int j)
{
	int		y;
	int		x;
	int		color;

	y = j * env->coef - 1;
	while (++y < (j * env->coef + env->coef))
	{
		x = i * env->coef - 1;
		color = 1;
		if (env->tab[j][i] == 7 || env->tab[j][i] == 15)
			color = 2;
		else if (env->tab[j][i] == 10 || env->tab[j][i] == 11)
			color = 3;
		else if (env->tab[j][i] == 12 || env->tab[j][i] == 13
			|| env->tab[j][i] == 14 || env->tab[j][i] == 16)
			color = 4;
		else if (env->tab[j][i] == END)
			color = 5;
		while (++x < (i * env->coef + env->coef))
			put_pxl_img(env, x, y, color);
	}
}

void	color_case(t_env *env)
{
	int	i;
	int	j;

	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if ((env->tab[j][i] > 0 && env->tab[j][i] <= 7)
					|| (env->tab[j][i] >= 9 && env->tab[j][i] <= 16))
				color_case2(env, i, j);
		}
	}
}
