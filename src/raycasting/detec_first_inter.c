/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detec_first_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:49:16 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/11 19:24:11 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int			intersection_horizontal(t_env *env, t_coord *cd)
{
	double		ya;
	double		coef_y;
	double		coef_x;
	double		tmp;


	ya = 0;
	cd->x = env->perso_x;
	cd->y = env->perso_y;
	coef_y = 1;
	coef_x = 1;
	if (env->angle > 0. && env->angle < 180.)
		ya =  fmod(env->perso_y, env->coef);
	else
		ya =  env->coef - fmod(env->perso_y, env->coef);
	if (env->angle > 0 && env->angle < 180)
		cd->y -= ya;
	else
		cd->y += ya;
	tmp = (ya / tan(env->angle * M_PI / 180));
	if (!(env->angle > 0 && env->angle < 180))
		cd->x -= tmp;
	else
		cd->x += tmp;
	return (1);
}

int			intersection_vertical(t_env *env, t_coord *cd)
{
	double		xa;
	double		coef_x;
	double		coef_y;

	xa = 0.;
	cd->x = env->perso_x;
	cd->y = env->perso_y;
	coef_x = 1.;
	coef_y = 1.;
	if (env->angle > 90. && env->angle < 270.)
		coef_x = -1.;
	if (!(env->angle > 90. && env->angle < 270.))
		coef_y = -1.;
	if (env->angle > 90. && env->angle < 270.)
		xa =  fmod(env->perso_x, env->coef);
	else
		xa =  env->coef - fmod(env->perso_x, env->coef);
	cd->x += xa * coef_x;
	cd->y = env->perso_y + ((xa * coef_y) * tan(env->angle * M_PI / 180));
	return (1);
}
