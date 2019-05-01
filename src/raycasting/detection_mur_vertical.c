/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection_mur_vertical.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:47:17 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 19:34:16 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

int			verif_ver(t_env *env, t_coord *coord)
{
	int	i;
	int	j;

	if (init_coord_lim(env, coord) == -1)
		return (-1);
	i = (int)(coord->x / env->coef);
	j = (int)(coord->y / env->coef);
	if (i < env->x && j < env->x)
	{
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

int			coef_ver(t_env *env, int *coef_x, int *coef_y)
{
	*coef_x = 1;
	*coef_y = 1;
	if (env->angle > 90. && env->angle < 270.)
		*coef_x = -1;
	if (!(env->angle > 90. && env->angle <= 270.))
		*coef_y = -1;
	return (0);
}

static void	init_coord(t_env *env, t_coord *coord, int coef, int cas)
{
	int	a;

	a = 0;
	if (cas == 1)
	{
		a = env->perso_x;
		while ((coef == 1) && (a % env->coef) != 0)
			a++;
		while ((coef == -1) && (a % env->coef) != 0)
			a--;
		coord->x = a;
		coord->y = env->perso_y;
	}
	else if (cas == 2)
	{
		a = env->perso_y;
		while ((coef == 1) && (a % env->coef) != 0)
			a++;
		while ((coef == -1) && (a % env->coef) != 0)
			a--;
		coord->x = env->perso_x;
		coord->y = a;
	}
}

int			init_var_ver(t_env *env, double *ya, double *xa, t_coord *coord2)
{
	int	coef;

	coef = 1;
	if (env->angle == 0. || env->angle == 180.)
	{
		*ya = 0;
		*xa = env->coef;
		env->angle == 180. ? coef = -1 : coef;
		init_coord(env, coord2, coef, 1);
	}
	else if (env->angle == 90. || env->angle == 270.)
	{
		*ya = env->coef;
		*xa = 0;
		env->angle == 90. ? coef = -1 : coef;
		init_coord(env, coord2, coef, 2);
	}
	else
	{
		*xa = env->coef;
		*ya = env->coef * tan(env->angle * M_PI / 180);
		if (intersection_vertical(env, coord2) == 1)
			return (1);
	}
	return (0);
}
