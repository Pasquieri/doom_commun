/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:45:50 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/06 09:03:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	key_menu_extra(t_env *env)
{
	if (env->menu_select == 3)
	{
		if (re_pars("./map/map.2", env) == -1)
		{
			env->menu = 1;
			env->map_entree = -1;
		}
		else
		{
			free_sprite(env);
			exec_calcul(env, 315, 1);
			env->map_entree = 0;
		}
	}
	if (env->menu_select == 4)
	{
		if (re_pars("./map/map.3", env) == -1)
		{
			env->menu = 1;
			env->map_entree = -1;
		}
		else
		{
			free_sprite(env);
			exec_calcul(env, 225, 1);
			env->map_entree = 0;
		}
	}
	if (env->menu_select == 5)
	{
		if (re_pars("./map/map.4", env) == -1)
		{
			env->menu = 1;
			env->map_entree = -1;
		}
		else
		{
			free_sprite(env);
			exec_calcul(env, 0, 1);
			env->map_entree = 0;
		}
	}
	if (env->menu == 1)
		open_menu(env);
	if (env->menu_select == 6)
	{
		system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
		exit(0);
	}
}

void		key_invalid_menu(t_env *env)
{
	env->menu = 0;
	if (env->menu_select <= 2)
	{
		if (re_pars("./map/map.1", env) == -1)
		{
			env->menu = 1;
			env->map_entree = -1;
		}
		else
		{
			free_sprite(env);
			exec_calcul(env, 0, 1);
			env->map_entree = 0;
		}
	}
	key_menu_extra(env);
}

void		key_valid_menu(t_env *env)
{
	env->menu = 0;
	if (env->menu_select == 2)
	{
		if (re_pars("./map/map.1", env) == -1)
		{
			env->menu = 1;
			env->map_entree = -1;
		}
		else
		{
			free_sprite(env);
			exec_calcul(env, 0, 1);
			env->map_entree = 0;
		}
	}
	key_menu_extra(env);
}
