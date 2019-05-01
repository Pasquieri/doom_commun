/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:15:20 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 18:02:01 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	fill_sort_tab(t_env *env, t_sort *sort, int nb_det)
{
	int	i;
	int	cmp;
	int	k;

	k = 0;
	i = -1;
	while (++i <= 6)
	{
		cmp = -1;
		while (++cmp < env->sp[i].nb)
		{
			if (env->sp[i].sprite[cmp].det == 1 && k < nb_det)
			{
				sort[k].i = i;
				sort[k].cmp = cmp;
				sort[k].dist = env->sp[i].sprite[cmp].d_sp;
				k++;
			}
		}
	}
}

static void	sort_sprite(t_sort *sort, int nb_det)
{
	int		k;
	int		i;
	t_sort	tmp;

	k = -1;
	i = 0;
	while (++k < nb_det && ++i < nb_det)
	{
		if (sort[i].dist < sort[k].dist)
		{
			tmp.i = sort[k].i;
			tmp.cmp = sort[k].cmp;
			tmp.dist = sort[k].dist;
			sort[k].i = sort[i].i;
			sort[k].cmp = sort[i].cmp;
			sort[k].dist = sort[i].dist;
			sort[i].i = tmp.i;
			sort[i].cmp = tmp.cmp;
			sort[i].dist = tmp.dist;
			k = -1;
			i = 0;
		};
	}
}

static void	print_sort(t_env *env, t_sort *sort, int nb_det)
{
	while (--nb_det >= 0)
		print_sprite_object(env, sort[nb_det].i, sort[nb_det].cmp);
	free(sort);
}

void		order_sprite(t_env *env)
{
	int		i;
	int		cmp;
	int		nb_det;
	t_sort	*sort;

	i = -1;
	nb_det = 0;
	while (++i <= 6)
	{
		cmp = -1;
		while (++cmp < env->sp[i].nb)
			if (env->sp[i].sprite[cmp].det == 1)
			{
				nb_det++;
				env->sp[i].sprite[cmp].d_sp = sqrt(pow(env->perso_x
						- env->sp[i].sprite[cmp].cd.x, 2)
						+ pow(env->perso_y - env->sp[i].sprite[cmp].cd.y, 2));
			}
	}
	if (!(sort = (t_sort *)malloc(sizeof(t_sort) * nb_det)))
		return ;
	fill_sort_tab(env, sort, nb_det);
	sort_sprite(sort, nb_det);
	print_sort(env, sort, nb_det);
}
