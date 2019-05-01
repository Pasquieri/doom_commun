/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection_mur_vertical.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:47:17 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 19:49:53 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	ft_check_sprite(t_env *env, t_coord cd)
{
	int	i;
	int	j;

	env->orientation = 1;
	if (env->angle > 90 && env->angle < 270)
		i = ((cd.x) - 1) / env->coef;
	else
		i = (int)(cd.x / env->coef);
	j = (int)(cd.y / env->coef);
	if (env->tab[j][i] == DOOR_CLOSE || env->tab[j][i] == DOOR
			|| (env->tab[j][i] >= W_G_TAB && env->tab[j][i] <= W_B_TAB))
		check_door_prox(env, cd, i, j);
	else
		check_sprite(i, j, env, 1, cd);
	if (env->angle > 90 && env->angle < 270)
		i = (int)(cd.x / env->coef);
	else
		i = ((cd.x) - 1) / env->coef;
	check_sprite(i, j, env, 1, cd);
}

int			verif_ver_sp(t_env *env, t_coord *coord)
{
	int	i;
	int	j;

	if (init_coord_lim(env, coord) == -1)
		return (-1);
	i = (int)(coord->x / env->coef);
	j = (int)(coord->y / env->coef);
	if (i < env->x && j < env->x)
	{
		ft_check_sprite(env, *coord);
		if (env->tab[j][i] > 0 && env->tab[j][i] <= 7)
		{
			coord->val = env->tab[j][i];
			return (1);
		}
		i = ((coord->x) - 1) / env->coef;
		if (env->tab[j][i] > 0 && env->tab[j][i] <= 7)
		{
			coord->val = env->tab[j][i];
			return (1);
		}
	}
	return (0);
}
