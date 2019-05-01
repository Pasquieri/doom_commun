/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:41:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/05/01 15:10:11 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void	ft_arrow_menu(t_env *env)
{
	arrow_menu(env);
	env->key[125] = 0;
	env->key[126] = 0;
}

int			key_apply(t_env *env)
{
	if (env->jump != 0)
		ft_jump(env);
	else if (env->crouch == -1 || env->crouch == 1)
		ft_crouch(env);
	ft_monkey(env);
	env->time += 1;
	if (env->time > 10000)
		env->time = 1;
	if ((env->key[125] || env->key[126]) && env->menu == 1)
		ft_arrow_menu(env);
	if (!env->menu)
		trig_press(env);
	return (0);
}
