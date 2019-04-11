/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/11 14:40:05 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static double	verif_angle(double angle)
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

static void		door_proximity(t_env *env)
{
	int	cmp;

	cmp = -1;
	while (++cmp < env->sp[5].nb)
		env->sp[5].sprite[cmp].proximity = 0;
}

void			affichage_sprite(t_env *env)
{
	double	a;
	double	d_mur;
	double	h_percue;
	int		x;

	a = env->d_regard + 30;
	a = verif_angle(a);
	x = 0;
	door_proximity(env);
	while (x < W_WIDTH)
	{
		env->angle = a;
		env->angle = verif_angle(env->angle);
		d_mur = detection_mur(env);
		d_mur = d_mur * cos((a - env->d_regard) * M_PI / 180);
		env->dist = d_mur;
		h_percue = env->d_ecran * (env->h_mur / d_mur);
		env->img_x = x;
		print_sprite(env);
		a -= (60. / W_WIDTH);
		x++;
	}
}
