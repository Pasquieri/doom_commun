/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:25:44 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/14 21:30:44 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/wolf3d.h"

/**************************** ADD TEST ********************************/
/*static void	fill_hor(int index_sp, int k, t_env *env, t_coord cd)
{
	if (env->sp[index_sp].sprite[k].det == 0)
	{
		env->sp[index_sp].sprite[k].det = 1;
		env->sp[index_sp].sprite[k].det_hor = 1;
		env->sp[index_sp].sprite[k].cd_i = cd;
		env->sp[index_sp].sprite[k].o_i = 0;
		env->sp[index_sp].sprite[k].win_x = env->img_x;
	}
}

static void	fill_ver(int index_sp, int k, t_env *env, t_coord cd)
{
	double	d_ver;
	double	d_hor;

	if (env->sp[index_sp].sprite[k].det_hor == 1)
	{
		d_ver = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
		d_ver = d_ver * cos((env->angle - env->d_regard) * M_PI / 180);
		d_hor = sqrt(pow(env->perso_x - env->sp[index_sp].sprite[k].cd_i.x, 2)
				+ pow(env->perso_y - env->sp[index_sp].sprite[k].cd_i.y, 2));
		d_hor = d_hor * cos((env->angle - env->d_regard) * M_PI / 180);
		if (d_ver < d_hor)
			env->sp[index_sp].sprite[k].det = 0;
		env->sp[index_sp].sprite[k].det_hor = 0;
	//	pour eviter de rerentrer dedans a tester
	}
	if (env->sp[index_sp].sprite[k].det == 0)
	{
		env->sp[index_sp].sprite[k].det = 1;
		env->sp[index_sp].sprite[k].cd_i = cd;
		env->sp[index_sp].sprite[k].o_i = 1;
		env->sp[index_sp].sprite[k].win_x = env->img_x;
	}
}*/
/***********************************************************************/

void	check_sprite(int i, int j, t_env *env, int orientation, t_coord cd)
{
	int		value;
	int		k;
	int		index_sp;
	double	dist;

	value = -1;
	if (env->tab[j][i] >= 10 && env->tab[j][i] <= 15)
		value = env->tab[j][i];
	env->tab[j][i] == DOOR ? value = 15 : value;
	if (value != -1)
	{
		k = -1;
		index_sp = value - 10;
		while (++k < env->sp[index_sp].nb)
		{
			if (env->sp[index_sp].sprite[k].i == i
					&& env->sp[index_sp].sprite[k].j == j)
			{
				/*************** ADD TEST 12/04 **************/
			//	if (orientation == 0)
			//		fill_hor(index_sp, k, env, cd);
			//	else
			//		fill_ver(index_sp, k, env, cd);
				/********************************************/

				/*********GRID && WIN ***************/
				dist = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
				dist = dist * cos((env->angle - env->d_regard) * M_PI / 180);
				env->sp[index_sp].sprite[k].detec[orientation].on = 1;
				env->sp[index_sp].sprite[k].detec[orientation].dist = dist;
				env->sp[index_sp].sprite[k].detec[orientation].cd = cd;
				/************************************/

				/******************* ADD 14/04 ***************************/
				env->sp[index_sp].sprite[k].det = 1; // 14/04
				if (orientation == 0 && env->sp[index_sp].sprite[k].cd_h.x == -1 && (env->sp[index_sp].sprite[k].cd_h.y == -1))
				{
					env->sp[index_sp].sprite[k].cd_h = cd;
					env->sp[index_sp].sprite[k].win_h_x = env->img_x;
				}
				else if (orientation == 1 && env->sp[index_sp].sprite[k].cd_v.x == -1 && (env->sp[index_sp].sprite[k].cd_v.y == -1))
				{
					env->sp[index_sp].sprite[k].cd_v = cd;
					env->sp[index_sp].sprite[k].win_v_x = env->img_x;
				}
				/***********************************************************/
			}
		}
	}
}
