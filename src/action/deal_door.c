/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:02:33 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/26 21:39:45 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	deal_door(t_env *env)
{
	int	i;
	int	j;
	int	cmp;

	cmp = -1;
	while (++cmp < env->sp[5].nb)
	{
		if (env->sp[5].sprite[cmp].proximity == 1)
		{
			i = env->sp[5].sprite[cmp].i;
			j = env->sp[5].sprite[cmp].j;
			if (env->tab[j][i] == 7)
			{
				env->tab[j][i] = 15;
				env->sp[5].sprite[cmp].open = 1;
			}
			else if (env->tab[j][i] == 15)
			{
				env->tab[j][i] = 7;
				env->sp[5].sprite[cmp].open = 0;
			}
		}
	}
}

void	deal_tab(t_env *env)
{
	int	cmp;

	cmp = -1;
	while (++cmp < env->sp[7].nb)
	{
		if (env->sp[7].sprite[cmp].proximity == 1)
		{
			if (env->skybox == 0)
				env->skybox = 24;
			else if (env->skybox == 24 || env->skybox == 22)
				env->skybox = 0;
		}
	}
}
/***************** RAMASSER LES BANANES ET SERINGUES ********************/
// Quand les items auront la bonne taille, verifier que l'intervalle
//  + / - 2 n'est pas trop grand
static void	check_pos(t_env *env, int k, int cmp)
{
	double	p_x;
	double	p_y;
	double	spr_x;
	double	spr_y;

	p_x = env->perso_x;
	p_y = env->perso_y;
	spr_x = env->sp[k].sprite[cmp].cd.x;
	spr_y = env->sp[k].sprite[cmp].cd.y;
	if (env->sp[k].sprite[cmp].alive == 1)
	{
		if (p_x >= (spr_x - 2) && p_x <= (spr_x + 2)
				&& p_y >= (spr_y - 2) && p_y <= (spr_y + 2))
		{
			if (k == 3)
				env->h_life += 30;
			else if (k == 6)
				env->h_ammo += 15;
			env->sp[k].sprite[cmp].alive = 0;
			env->tab[env->sp[k].sprite[cmp].j][env->sp[k].sprite[cmp].i] = 0;
		}
	}
}

void	deal_items(t_env *env, int k)
{
	int	cmp;
	int	i;
	int	j;

	i = (int)(env->perso_x / env->coef);
	j = (int)(env->perso_y / env->coef);
	cmp = -1;
	while (++cmp < env->sp[k].nb)
	{
		if (env->sp[k].sprite[cmp].i == i
				&& env->sp[k].sprite[cmp].j == j)
			check_pos(env, k, cmp);
	}
}
