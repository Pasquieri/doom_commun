/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection_mur_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:43:51 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/21 19:15:29 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	ft_distance(t_coord coord1, t_coord coord2, t_env *env)
{
	double	dist1;
	double	dist2;
	t_coord	perso;

	perso.x = env->perso_x;
	perso.y = env->perso_y;
	dist1 = sqrt(pow(perso.x - coord1.x, 2) + pow(perso.y - coord1.y, 2));
	dist2 = sqrt(pow(perso.x - coord2.x, 2) + pow(perso.y - coord2.y, 2));
	if (dist1 <= dist2)
		env->dist = dist1;
	else
		env->dist = dist2;
}

void		detection_mur_sp(t_env *env)
{
	double	xa;
	double	ya;
	t_coord	coord1;
	t_coord	coord2;
	t_coef	coef;

	init_var_hor(env, &ya, &xa, &coord1);
	coef_hor(env, &coef.x, &coef.y);
	while (verif_hor_sp(env, &coord1) == 0)
	{
		coord1.x += (xa * coef.x);
		coord1.y += (ya * coef.y);
	}
	init_var_ver(env, &ya, &xa, &coord2);
	coef_ver(env, &coef.x, &coef.y);
	while (verif_ver_sp(env, &coord2) == 0)
	{
		coord2.x += (xa * coef.x);
		coord2.y += (ya * coef.y);
	}
	ft_distance(coord1, coord2, env);
}
