/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:45:50 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/29 21:30:45 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	key_menu_extra_3(t_env *env)
{
	if (env->menu_select == 4)
	{
		if (re_pars("./map/map.3", env) == -1)
		{
			env->menu = 1;
			env->map_entree = -1;
		}
		else
		{
			if (env->free_sprite == 1)
				free_sprite(env);
			exec_calcul(env, 1);
			env->map_entree = 0;
			env->menu_select = 1;
			ft_play_music(0, 's');
		}
	}
}

static void	key_menu_extra_2(t_env *env)
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
			if (env->free_sprite == 1)
				free_sprite(env);
			exec_calcul(env, 1);
			env->map_entree = 0;
			env->menu_select = 1;
			ft_play_music(0, 's');
		}
	}
	key_menu_extra_3(env);
}

static void	key_menu_extra(t_env *env)
{
	if (env->menu_select == 5)
	{
		if (re_pars("./map/map.4", env) == -1)
		{
			env->menu = 1;
			env->map_entree = -1;
		}
		else
		{
			if (env->free_sprite == 1)
				free_sprite(env);
			exec_calcul(env, 1);
			env->map_entree = 0;
			env->menu_select = 1;
			ft_play_music(0, 's');
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
			ft_play_music(0, 's');
		}
		else
		{
			if (env->free_sprite == 1)
				free_sprite(env);
			exec_calcul(env, 1);
			env->map_entree = 0;
			ft_play_music(0, 's');
		}
	}
	key_menu_extra_2(env);
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
			if (env->map_entree == 0)
				free_sprite(env);
			exec_calcul(env, 1);
			env->map_entree = 0;
			env->menu_select = 1;
			ft_play_music(0, 's');
		}
	}
	key_menu_extra_2(env);
	key_menu_extra(env);
}
