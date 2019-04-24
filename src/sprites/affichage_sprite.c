/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/24 16:35:07 by cpalmier         ###   ########.fr       */
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

static void		sprite_init(t_env *env)
{
	int	k;
	int	cmp;

	k = -1;
	while (++k < NB_SP)
	{
		if (k == 6)
			k += 2;
		cmp = -1;
		while (++cmp < env->sp[k].nb)
		{
			env->sp[k].sprite[cmp].det = 0;
			env->sp[k].sprite[cmp].f_win_x = 0;
			env->sp[k].sprite[cmp].detec[0].on = 0;
			env->sp[k].sprite[cmp].cd_h.x = -1;
			env->sp[k].sprite[cmp].cd_h.y = -1;
			env->sp[k].sprite[cmp].win_h_x = 0;
			env->sp[k].sprite[cmp].detec[1].on = 0;
			env->sp[k].sprite[cmp].cd_v.x = -1;
			env->sp[k].sprite[cmp].cd_v.y = -1;
			env->sp[k].sprite[cmp].win_v_x = 0;
		}
	}
}

/*static void	clean(t_env *env) // a supp
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (200 * 200))
	{
		env->m[1].img_str[x] = (char)0;
		env->m[1].img_str[x + 1] = (char)0;
		env->m[1].img_str[x + 2] = (char)0;
		env->m[1].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
}*/

void			affichage_sprite(t_env *env)
{
	double	a;
	int		x;

	a = env->d_regard + 30;
	a = verif_angle(a);
	x = -1;
	door_proximity(env);
	sprite_init(env); // ADD initialise les coords i de chaque sprite == -1;
//	clean(env); // a supp
	while (++x < W_WIDTH)
	{
		env->angle = verif_angle(a);
		detection_mur_sp(env);
		env->dist = env->dist * cos((a - env->d_regard) * M_PI / 180);
		env->img_x = x;
		print_sprite_wall(env);
		a -= (60. / W_WIDTH);
	}
//	put_sprite_img(env);
}


