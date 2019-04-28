/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 03:55:38 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/28 17:10:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	print_gun(t_env *env, int k)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 400;
	while (++x < W_WIDTH)
	{
		y = 455 + k;
		while (++y < W_HEIGHT)
		{
			i = 4 * x + y * env->m[0].s_l;
			j = 4 * (x - 400) + (y - 455 + k) * env->sp_t[8].s_l;
			if (env->sp_t[8].img_str[j + 3] != -1)
			{
				env->m[0].img_str[i] = env->sp_t[8].img_str[j];
				env->m[0].img_str[i + 1] = env->sp_t[8].img_str[j + 1];
				env->m[0].img_str[i + 2] = env->sp_t[8].img_str[j + 2];
				env->m[0].img_str[i + 3] = env->sp_t[8].img_str[j + 3];
			}
		}
	}
}
