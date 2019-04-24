/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:25:44 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/23 17:18:51 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/wolf3d.h"

void	check_grid_win(t_env *env, t_coord cd, int orient, int i, int j)
{
	int		k;
	int		index_sp;
	double	dist;

	k = -1;
	index_sp = env->tab[j][i] - 10;
	if (env->tab[j][i] == DOOR)
		index_sp = 5;
	while (++k < env->sp[index_sp].nb)
	{
		if (env->sp[index_sp].sprite[k].i == i
				&& env->sp[index_sp].sprite[k].j == j)
		{
			dist = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
			dist = dist * cos((env->angle - env->d_regard) * M_PI / 180);
			env->sp[index_sp].sprite[k].detec[orient].on = 1;
			env->sp[index_sp].sprite[k].detec[orient].dist = dist;
			env->sp[index_sp].sprite[k].detec[orient].cd = cd;
		}
	}
}

/**************************** ADD TEST ********************************/
static void	fill_hor(int index_sp, int k, t_env *env, t_coord cd)
{
	if (env->sp[index_sp].sprite[k].det == 0)
	{
		env->sp[index_sp].sprite[k].det = 1;
		env->sp[index_sp].sprite[k].det_hor = 1;
		env->sp[index_sp].sprite[k].cd_i = cd;
		env->sp[index_sp].sprite[k].o_i = 0;
		env->sp[index_sp].sprite[k].a_i = env->angle;
		env->sp[index_sp].sprite[k].win_x = env->img_x;
//		printf("hor : angle = %f, win_x = %d, sprite : %d\n", env->angle, env->img_x, index_sp);
	}
}

static void	fill_ver(int index_sp, int k, t_env *env, t_coord cd)
{
	double	d_ver;
	double	d_hor;

	if (env->sp[index_sp].sprite[k].det_hor == 1
			&& env->img_x == env->sp[index_sp].sprite[k].win_x)
	{
		d_ver = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
		d_ver = d_ver * cos((env->angle - env->d_regard) * M_PI / 180);
		d_hor = sqrt(pow(env->perso_x - env->sp[index_sp].sprite[k].cd_i.x, 2)
				+ pow(env->perso_y - env->sp[index_sp].sprite[k].cd_i.y, 2));
		d_hor = d_hor * cos((env->angle - env->d_regard) * M_PI / 180);
		if (d_ver < d_hor)
			env->sp[index_sp].sprite[k].det = 0;
		env->sp[index_sp].sprite[k].det_hor = 0;
	//	printf("deux det : a1 = %f, a2 : %f, win_x_1 = %d, win_x_2 : %d, sprite : %dd_ho : %f, d_ver : %f\n", env->sp[index_sp].sprite[k].a_i, env->angle, env->sp[index_sp].sprite[k].win_x, env->img_x, index_sp, d_hor, d_ver);
	//	pour eviter de rerentrer dedans a tester
	}
	if (env->sp[index_sp].sprite[k].det == 0)
	{
		env->sp[index_sp].sprite[k].det = 1;
		env->sp[index_sp].sprite[k].cd_i = cd;
		env->sp[index_sp].sprite[k].o_i = 1;
		env->sp[index_sp].sprite[k].a_i = env->angle;
		env->sp[index_sp].sprite[k].win_x = env->img_x;
	//	printf("ver : angle = %f, win_x = %d, sprite : %d\n", env->angle, env->img_x, index_sp);
	}
}
/***********************************************************************/

void	check_sprite(int i, int j, t_env *env, int orient, t_coord cd)
{
	int		value;
	int		k;
	int		index_sp;

	value = -1;
	// 12 = COLUMN / 13 = BANANA / 14 = MONKEY / 18 = SYRINGE
	if ((env->tab[j][i] >= 12 && env->tab[j][i] <= 14) || env->tab[j][i] == 18)
		value = env->tab[j][i];
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
				if (orient == 0)
					fill_hor(index_sp, k, env, cd);
				else
					fill_ver(index_sp, k, env, cd);
				/********************************************/
				/******************* ADD 14/04 ***************************/
			//	env->sp[index_sp].sprite[k].det = 1; // 14/04
			//	if (env->sp[index_sp].sprite[k].detec[orient].on != 1)
			//	{
			//		env->sp[index_sp].sprite[k].detec[orient].on = 1;
			//		if (orient == 0
			//				&& env->sp[index_sp].sprite[k].cd_h.x == -1 && (env->sp[index_sp].sprite[k].cd_h.y == -1))
			//		{
			//			env->sp[index_sp].sprite[k].cd_h = cd;
			//			env->sp[index_sp].sprite[k].win_h_x = env->img_x;
			//			env->sp[index_sp].sprite[k].angle_h = env->angle; // 18/04
			//		}
			//		else if (orient == 1
			//			&& env->sp[index_sp].sprite[k].cd_v.x == -1 && (env->sp[index_sp].sprite[k].cd_v.y == -1))
			//		{
			//			env->sp[index_sp].sprite[k].cd_v = cd;
			//			env->sp[index_sp].sprite[k].win_v_x = env->img_x;
			//			env->sp[index_sp].sprite[k].angle_v = env->angle; // 18/04
			//		}
			//	}
				/***********************************************************/
			}
		}
	}
}