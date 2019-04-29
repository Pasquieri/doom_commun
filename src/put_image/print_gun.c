/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 03:55:38 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/29 12:33:59 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	deal_shoot(t_env *env, int o)
{
	int	i;
	int	j;
	int	k;
	int	index;

	index = env->shoot[o].index;
	k = env->shoot[o].k;
	i = env->sp[index].sprite[k].i;
	j = env->sp[index].sprite[k].j;
	if (env->tab[j][i] == WIN || env->tab[j][i] == MONKEY)
	{
		if (env->tab[j][i] == MONKEY)
			env->h_monkey--;
		env->sp[index].sprite[k].alive = 0;
		env->tab[env->sp[index].sprite[k].j][env->sp[index].sprite[k].i] = 0;
		env->tab[j][i] = 0;
	}
	env->shoot[0].det = 0;
	env->shoot[1].det = 0;
}

static void	shoot(t_env *env)
{
	double	d_v;
	double	d_h;

	env->angle = env->d_regard;
	detec_shoot(env);
	d_h = -1;
	d_v = -1;
	if (env->shoot[0].det == 0 || env->shoot[1].det == 0)
	{
		if (env->shoot[0].det == 1)
			d_h = env->shoot[0].d;
		if (env->shoot[1].det == 1)
			d_v = env->shoot[1].d;
		d_h == - 1 ? d_h = d_v + 1 : d_h;
		d_v == - 1 ? d_v = d_h + 1 : d_v;
		if (d_h < d_v && d_h <= env->dist)
			deal_shoot(env, 0);
		else if (d_v <= d_h && d_v <= env->dist)
			deal_shoot(env, 1);
	}
}

void	print_gun(t_env *env, int k)
{
	int	i;
	int	j;
	int	x;
	int	y;

	if (k != 0)
		shoot(env);
	x = 400;
	while (++x < W_WIDTH)
	{
		y = 455 + k;
		while (++y < W_HEIGHT)
		{
			i = 4 * x + y * env->m[0].s_l;
			j = 4 * (x - 400) + (y - 455 + k) * env->sp_t[8].s_l;
			if (env->sp_t[8].img_str[j + 3] != -1)
			{
				env->m[0].img_str[i] = env->sp_t[8].img_str[j];
				env->m[0].img_str[i + 1] = env->sp_t[8].img_str[j + 1];
				env->m[0].img_str[i + 2] = env->sp_t[8].img_str[j + 2];
				env->m[0].img_str[i + 3] = env->sp_t[8].img_str[j + 3];
			}
		}
	}
}
