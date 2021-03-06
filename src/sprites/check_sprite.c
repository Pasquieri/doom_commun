/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:25:44 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 20:53:51 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	fill_hor(int index_sp, int k, t_env *env, t_coord cd)
{
	if (env->sp[index_sp].sprite[k].det == 0
			&& env->sp[index_sp].sprite[k].check_i == 0)
	{
		env->sp[index_sp].sprite[k].det = 1;
		env->sp[index_sp].sprite[k].det_hor = 1;
		env->sp[index_sp].sprite[k].cd_i = cd;
		env->sp[index_sp].sprite[k].o_i = 0;
		env->sp[index_sp].sprite[k].a_i = env->angle;
		env->sp[index_sp].sprite[k].win_x = env->img_x;
	}
	if (env->sp[index_sp].sprite[k].check_f == 0
			&& env->sp[index_sp].sprite[k].check_i == 1)
	{
		env->sp[index_sp].sprite[k].det_hor_f = 1;
		env->sp[index_sp].sprite[k].cd_f = cd;
		env->sp[index_sp].sprite[k].o_f = 0;
		env->sp[index_sp].sprite[k].a_f = env->angle;
		env->sp[index_sp].sprite[k].win_x_f = env->img_x;
	}
}

static void	fill_ver_final(int index_sp, int k, t_env *env, t_coord cd)
{
	double	d_ver;
	double	d_hor;

	if (env->sp[index_sp].sprite[k].det_hor_f == 1)
	{
		d_ver = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
		d_ver = d_ver * cos((env->angle - env->d_regard) * M_PI / 180);
		d_hor = sqrt(pow(env->perso_x - env->sp[index_sp].sprite[k].cd_i.x, 2)
				+ pow(env->perso_y - env->sp[index_sp].sprite[k].cd_i.y, 2));
		d_hor = d_hor * cos((env->angle - env->d_regard) * M_PI / 180);
		if (d_ver < d_hor)
			env->sp[index_sp].sprite[k].det_hor_f = 0;
	}
	if (env->sp[index_sp].sprite[k].det_hor_f == 0)
	{
		env->sp[index_sp].sprite[k].cd_f = cd;
		env->sp[index_sp].sprite[k].o_f = 1;
		env->sp[index_sp].sprite[k].a_f = env->angle;
		env->sp[index_sp].sprite[k].win_x_f = env->img_x;
	}
}

static void	fill_info(t_env *env, int index_sp, int k, t_coord cd)
{
	env->sp[index_sp].sprite[k].det = 1;
	env->sp[index_sp].sprite[k].cd_i = cd;
	env->sp[index_sp].sprite[k].o_i = 1;
	env->sp[index_sp].sprite[k].a_i = env->angle;
	env->sp[index_sp].sprite[k].win_x = env->img_x;
}

static void	fill_ver(int index_sp, int k, t_env *env, t_coord cd)
{
	double	d_ver;
	double	d_hor;

	if (env->sp[index_sp].sprite[k].det_hor == 1
			&& env->sp[index_sp].sprite[k].check_i == 0
			&& env->angle == env->sp[index_sp].sprite[k].a_i)
	{
		d_ver = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
		d_ver = d_ver * cos((env->angle - env->d_regard) * M_PI / 180);
		d_hor = sqrt(pow(env->perso_x - env->sp[index_sp].sprite[k].cd_i.x, 2)
				+ pow(env->perso_y - env->sp[index_sp].sprite[k].cd_i.y, 2));
		d_hor = d_hor * cos((env->angle - env->d_regard) * M_PI / 180);
		if (d_ver < d_hor)
			env->sp[index_sp].sprite[k].det = 0;
		env->sp[index_sp].sprite[k].det_hor = 0;
	}
	if (env->sp[index_sp].sprite[k].det == 0
			&& env->sp[index_sp].sprite[k].check_i == 0)
		fill_info(env, index_sp, k, cd);
	if (env->sp[index_sp].sprite[k].check_f == 0
			&& env->sp[index_sp].sprite[k].check_i == 1)
		fill_ver_final(index_sp, k, env, cd);
}

void		check_sprite(int i, int j, t_env *env, t_coord cd)
{
	int		value;
	int		k;
	int		index_sp;

	value = -1;
	if ((env->tab[j][i] >= GRID && env->tab[j][i] <= SYRINGE))
		value = env->tab[j][i];
	value == DOOR_CLOSE ? value = -1 : value;
	if (value != -1)
	{
		k = -1;
		index_sp = value - 10;
		while (++k < env->sp[index_sp].nb)
		{
			if (env->sp[index_sp].sprite[k].i == i
					&& env->sp[index_sp].sprite[k].j == j
					&& env->sp[index_sp].sprite[k].alive == 1)
			{
				if (env->orientation == 0)
					fill_hor(index_sp, k, env, cd);
				else if (env->orientation == 1)
					fill_ver(index_sp, k, env, cd);
			}
		}
	}
}
