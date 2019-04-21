/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:02:33 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/10 05:13:15 by cpalmier         ###   ########.fr       */
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
