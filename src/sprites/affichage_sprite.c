/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/29 22:14:56 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void		initialize_struct(t_env *env, int k, int cmp)
{
	env->sp[k].sprite[cmp].det = 0;
	env->sp[k].sprite[cmp].win_x = 0;
	env->sp[k].sprite[cmp].detec[0].on = 0;
	env->sp[k].sprite[cmp].cd_h.x = -1;
	env->sp[k].sprite[cmp].cd_h.y = -1;
	env->sp[k].sprite[cmp].win_h_x = 0;
	env->sp[k].sprite[cmp].detec[1].on = 0;
	env->sp[k].sprite[cmp].cd_v.x = -1;
	env->sp[k].sprite[cmp].cd_v.y = -1;
	env->sp[k].sprite[cmp].win_v_x = 0;
	env->sp[k].sprite[cmp].check = 0;
}

/*static void	check_obj_behind_wall(t_env *env)
{
	int		k;
	int		cmp;
	double	d_sp;

	k = 1;
	while (++k <= 6)
	{
		k == 5 ? k = k + 1 : k;
		cmp = -1;
		while (++cmp < env->sp[k].nb)
		{
			if (env->sp[k].sprite[cmp].det == 1
					&& env->sp[k].sprite[cmp].check == 0)
			{
				d_sp = sqrt(pow(env->perso_x - env->sp[k].sprite[cmp].cd_i.x, 2)
						+ pow(env->perso_y - env->sp[k].sprite[cmp].cd_i.y, 2));
				env->sp[k].sprite[cmp].check = 1;
				if (d_sp > env->dist)
					initialize_struct(env, k, cmp);
				// rajouter une comparaison avec le milieu du sprite pour 
				// trouver le vrai 1er angle : monkey
			}
		}
	}
}*/

/*static void	check_obj_behind_wall(t_env *env)
{
	int		i;
	int		cmp;
	double	d_sp;

	i = 1;
	while (++i <= 6)
	{
		i == 5 ? i = i + 1 : i;
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if (env->sp[i].sprite[cmp].det == 1)
			//		&& env->sp[i].sprite[cmp].alive == 1)
			{
					//printf(" BEFORE a_i : %f, win_x : %d, o_i : %d\n", env->sp[i].sprite[cmp].a_i, env->sp[i].sprite[cmp].win_x, env->sp[i].sprite[cmp].o_i);
				if (env->img_x == env->sp[i].sprite[cmp].win_x)
			//	if (env->sp[i].sprite[cmp].check == 0)
				{
					d_sp = sqrt(pow(env->perso_x - env->sp[i].sprite[cmp].cd_i.x, 2)
					+ pow(env->perso_y - env->sp[i].sprite[cmp].cd_i.y, 2));
					d_sp = d_sp * cos((env->angle - env->d_regard) * M_PI / 180);
					int init;
					init = 0;
					if (d_sp > env->dist)
					{
						initialize_struct(env, i, cmp);
						init = 1;
					}
			//		printf("INIT ? : %d a_i : %f, win_x ; %d\n", init, env->sp[i].sprite[cmp].a_i, env->sp[i].sprite[cmp].win_x);
				}
			}
		}
	}
}*/

static void		sprite_init(t_env *env)
{
	int	k;
	int	cmp;

	k = -1;
	while (++k < 8)
	{
		cmp = -1;
		while (++cmp < env->sp[k].nb)
			initialize_struct(env, k, cmp);
	}
}

static void		action_proximity(t_env *env)
{
	int	cmp;

	cmp = -1;
	while (++cmp < env->sp[5].nb)
		env->sp[5].sprite[cmp].proximity = 0;
	cmp = -1;
	while (++cmp < env->sp[7].nb)
		env->sp[7].sprite[cmp].proximity = 0;
}


void			affichage_sprite(t_env *env)
{
	double	a;
	int		x;

	a = env->d_regard + 30;
	a = verif_angle(a);
	x = -1;
	action_proximity(env);
	sprite_init(env);
	while (++x < W_WIDTH)
	{
		env->angle = verif_angle(a);
		detection_mur_sp(env);
		env->dist = env->dist * cos((a - env->d_regard) * M_PI / 180);
		env->img_x = x;
	//	check_obj_behind_wall(env);
		print_sprite_wall(env);
		a -= (60. / W_WIDTH);
	}
	print_sprite_object(env);
}


