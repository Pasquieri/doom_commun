/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:45:50 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/07 13:51:41 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int			trig_press(t_env *env)
{
	int	i;

	i = 0;
	if ((env->key[0] || env->key[1] || env->key[2] || env->key[13])
			&& !env->menu)
		deplacements(env);
	if ((env->key[69] || env->key[78] || env->key[123] || env->key[124]
				|| env->key[125] || env->key[126]) && !env->menu)
		rotation_regard(env);
	if (env->key[27] || env->key[24] || env->key[29])
	{
		if (env->key[29])
			env->lum_int = 255;
		if (env->key[27])
			env->lum_int -= 3;
		if (env->key[24])
			env->lum_int += 3;
		env->lum_int < 1 ? env->lum_int = 1 : env->lum_int;
		env->lum_int > 500 ? env->lum_int = 500 : env->lum_int;
	}
	if (env->key[257] && !env->menu)
		env->vitesse = 2;
	if (!env->menu)
		exec_calcul(env, 0, 0);
	
/*	if (env->key[258]) // shift droit : test affichage sprite
	{
		int	sp;
		sp = 0;
		int	l;
		int	x;
		int	y;
		int	m;
		int	n;
	
		l = -1;
		y = -1;
		while (++y < env->sp_t[sp].height)
		{
			x = -1;
			while (++x < env->sp_t[sp].width)
			{
				m = 4 * x + y * env->m[0].s_l;
				n = 4 * x + y * env->sp_t[sp].s_l;
				if (env->sp_t[sp].img_str[n + 3] != -1)
				{
					env->m[0].img_str[m] = env->sp_t[sp].img_str[n];
					env->m[0].img_str[m + 1] = env->sp_t[sp].img_str[n + 1];
					env->m[0].img_str[m + 2] = env->sp_t[sp].img_str[n + 2];
					env->m[0].img_str[m + 3] = env->sp_t[sp].img_str[n + 3];
				}
			}
		}
		mlx_put_image_to_window(env->mlx, env->win, env->m[0].img ,0,0);
	}*/
	return (0);
}
