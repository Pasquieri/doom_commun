/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_arrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:39:51 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:41:25 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	arrow_menu(t_env *env)
{
	if (env->key[125])
		env->menu_select++;
	if (env->key[126])
		env->menu_select--;
	if (env->menu_select == 0 || env->menu_select == -1)
		env->menu_select = 1;
	if (env->menu_select > 6)
		env->menu_select = 6;
	open_menu(env);
}
