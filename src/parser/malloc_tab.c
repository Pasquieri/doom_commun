/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:40:33 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 17:53:37 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		malloc_tab(t_env *env)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!(env->tab = (int **)malloc(sizeof(int *) * env->y)))
	{
		free(env->tab);
		return (error_message(3, env));
	}
	while (i < env->x)
	{
		if (!(env->tab[i] = (int *)malloc(sizeof(int) * env->x)))
		{
			while (j <= i)
			{
				free(env->tab[j]);
				j++;
			}
			free(env->tab);
			return (error_message(3, env));
		}
		i++;
	}
	return (0);
}
