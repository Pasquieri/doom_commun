/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:59:10 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 21:38:42 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	print_tab(t_env *env, float p_y, float p_x, t_mlx *sp)
{
	int		i;
	int		j;
	float	p_x_tab;
	float	p_y_tab;

	if (p_y < 33.3 || p_y > 66.6 || p_x < 29 || p_x > 71)
		return ;
	else
	{
		p_x_tab = (p_x - 29) * 100 / 42.0;
		p_y_tab = (p_y - 33.3) * 100 / 33.4;
		i = 4 * env->img_x + env->img_y * env->m[0].s_l;
		j = 4 * (int)(sp->width * p_x_tab / 100)
			+ (int)(sp->height * p_y_tab / 100) * sp->s_l;
		env->m[0].img_str[i] = luminosite((int)sp->img_str[j], env->lum);
		env->m[0].img_str[i + 1] = luminosite(sp->img_str[j + 1], env->lum);
		env->m[0].img_str[i + 2] = luminosite(sp->img_str[j + 2], env->lum);
		env->m[0].img_str[i + 3] = (char)0;
	}
}
