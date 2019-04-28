/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:17:26 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/28 23:17:28 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void		number_sprite(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < NB_SP)
		env->sp[i].nb = 0;
	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if (env->tab[j][i] == DOOR)
				env->sp[5].nb++;
			else if (env->tab[j][i] >= 10 && env->tab[j][i] <= 16)
				env->sp[env->tab[j][i] - 10].nb++;
			else if (env->tab[j][i] >= 4 && env->tab[j][i] <= 6)
				env->sp[7].nb++;
		}
	}
}

static void	fill_info_sprite(t_sp *sp, int *x, int i, int j)
{
	double	pos_x;
	double	pos_y;
	double	coef;

	coef = 5.;
	sp->sprite[*x].i = i;
	sp->sprite[*x].j = j;
	sp->sprite[*x].alive = 1;
	if (sp->val == MONKEY)
	{
		pos_x = i * coef + coef / 2;
		pos_y = j * coef + coef / 2;
		sp->sprite[*x].cd.x = pos_x;
		sp->sprite[*x].cd.y = pos_y;
	}
	else if (sp->val == COLUMN || sp->val == BANANA || sp->val == SYRINGE)
	{
		pos_x = i * coef + coef / 2;
		pos_y = j * coef + coef / 2;
		sp->sprite[*x].cd.x = pos_x;
		sp->sprite[*x].cd.y = pos_y;
	}
	*x += 1;
}

void		init_tab_sprite2(t_env *env, int k, int x)
{
	int		j;
	int		i;

	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if (k == 5 && env->tab[j][i] == 15)
				env->sp[k].sprite[x].open = 1;
			if (env->tab[j][i] == env->sp[k].val
					|| (k == 5 && env->tab[j][i] == 15) || (k == 7
						&& (env->tab[j][i] == 5 || env->tab[j][i] == 6)))
				fill_info_sprite(&env->sp[k], &x, i, j);
		}
	}
}

void		init_tab_sprite(t_env *env)
{
	int	k;
	int	x;

	k = -1;
	while (++k < NB_SP)
	{
		env->sp[k].val = k + 10;
		k == 5 ? env->sp[k].val = 7 : env->sp[k].val;
		k == 7 ? env->sp[k].val = 4 : env->sp[k].val;
		x = 0;
		if (!(env->sp[k].sprite = (t_sprite *)malloc(sizeof(t_sprite)
						* (env->sp[k].nb + 1))))
			return ;
		init_tab_sprite2(env, k, x);
	}
	env->free_sprite = 1;
}
