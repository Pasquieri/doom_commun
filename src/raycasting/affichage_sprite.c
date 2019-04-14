/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/14 21:22:28 by cpalmier         ###   ########.fr       */
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
	while (++k < 6)
	{
		if (k == 4)
			k++;
		cmp = -1;
		while (++cmp < env->sp[k].nb)
		{
			env->sp[k].sprite[cmp].cd_h.x = -1;
			env->sp[k].sprite[cmp].cd_h.y = -1;
			env->sp[k].sprite[cmp].cd_v.x = -1;
			env->sp[k].sprite[cmp].cd_v.y = -1;
			//env->sp[k].sprite[cmp].detec[0].cd.x = -1;
			//env->sp[k].sprite[cmp].detec[0].cd.y = -1;
			//env->sp[k].sprite[cmp].detec[1].cd.x = -1;
			//env->sp[k].sprite[cmp].detec[1].cd.y = -1;
			env->sp[k].sprite[cmp].det = 0;
			env->sp[k].sprite[cmp].win_x = 0;
		}
	}
}

/************** TEST PREMIERE COORD ********************/
/*static void	printf_sprite(t_env *env)
{
	int	i;
	int	cmp;

	i = -1;
	while (++i < 6) // < 5 pour tous les sprites sp[4] = monkey
	{
		if (i == 4)
			i++;
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if (env->sp[i].sprite[cmp].det == 1)
			{
				printf("sp[%d].sprite[%d] : coord i : (%f, %f), orient : %d win_X : %d\n",i,cmp, env->sp[i].sprite[cmp].cd_i.x, env->sp[i].sprite[cmp].cd_i.y, env->sp[i].sprite[cmp].o_i, env->sp[i].sprite[cmp].win_x);
			}
		}
	}
}*/
/**************************************************/

void			affichage_sprite(t_env *env)
{
	double	a;
	double	d_mur;
	int		x;

	a = env->d_regard + 30;
	a = verif_angle(a);
	x = -1;
	door_proximity(env);
	sprite_init(env); // ADD initialise les coords i de chaque sprite == -1;
	while (++x < W_WIDTH)
	{
		env->angle = a;
		env->angle = verif_angle(env->angle);
		d_mur = detection_mur(env);
		d_mur = d_mur * cos((a - env->d_regard) * M_PI / 180);
		env->dist = d_mur;
		env->img_x = x;
		print_sprite(env);
		a -= (60. / W_WIDTH);
	}
	put_sprite_img(env);
//	printf_sprite(env);
}


