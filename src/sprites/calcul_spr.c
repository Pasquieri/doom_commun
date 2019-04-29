/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_spr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:47:18 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/29 20:28:45 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

double	verif_angle(double angle)
{
	if (angle < 0.)
	{
		while (angle < 0.)
			angle = angle + 360.;
	}
	else if (angle > 360.)
	{
		while (angle > 360.)
			angle = angle - 360.;
	}
	if (angle == 360.)
		angle = 0.;
	return (angle);
}

t_coord	init_lim_coord(t_env *env, int k, int cmp, double theta)
{
	t_coord	cd_a;
	t_coord	cd_m;
	t_coord	cd_m_p;

	cd_a = env->sp[k].sprite[cmp].cd;
	cd_m.x = cd_a.x + 2.5;
	cd_m.y = cd_a.y;
	cd_m_p.x = cd_a.x + ((cd_m.x - cd_a.x) * cos(theta * M_PI / 180));
	cd_m_p.y = cd_a.y - (cd_m.x - cd_a.x) * sin(theta * M_PI / 180);
	return (cd_m_p);
}

double	init_lim_angle(t_env *env, t_coord cd)
{
	double	a;
	double	h;
	double	alpha;
	double	angle;
	t_coord	pt_tmp;

	pt_tmp.x = cd.x;
	pt_tmp.y = env->perso_y;
	a = sqrt(pow(env->perso_x - pt_tmp.x, 2) + pow(env->perso_y - pt_tmp.y, 2));
	h = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
	alpha = acos(a/h) * 180 / M_PI;
	angle = alpha;
	if (env->perso_x > cd.x && env->perso_y < cd.y)
		angle = alpha + 180.;
	else if (env->perso_x < cd.x && env->perso_y < cd.y)
		angle = 360. - alpha;
	else if (env->perso_x < cd.x && env->perso_y > cd.y)
		angle = alpha;
	else if (env->perso_x > cd.x && env->perso_y > cd.y)
		angle = 180. - alpha;
	else if (env->perso_x == cd.x && env->perso_y < cd.y) // pas sure
		a = 270.;
	else if (env->perso_x == cd.x && env->perso_y > cd.y) //
		a = 90.;
	else if (env->perso_x < cd.x && env->perso_y == cd.y) //
		a = 0.;
	else if (env->perso_x > cd.x && env->perso_y ==  cd.y) //
		a = 180.;
	return (angle);
}
