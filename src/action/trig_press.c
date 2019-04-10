/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:45:50 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/10 04:02:35 by cpalmier         ###   ########.fr       */
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
	if (env->key[27] || env->key[24])
	{
		if (env->key[27])
			env->lum_int -= 3;
		if (env->key[24])
			env->lum_int += 3;
		env->lum_int < 1 ? env->lum_int = 1 : env->lum_int;
		env->lum_int > 500 ? env->lum_int = 500 : env->lum_int;
	}
	if (!env->menu)
		exec_calcul(env, 0, 0);
	return (0);
}
