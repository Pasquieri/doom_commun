/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 05:08:38 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 21:40:59 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	free_sprite(t_env *env)
{
	int	k;

	k = -1;
	while (++k < NB_SP)
		free(env->sp[k].sprite);
	env->free_sprite = 0;
}
