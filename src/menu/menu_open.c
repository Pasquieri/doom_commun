/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:37:03 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:41:37 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void			affiche_menu_valide(t_env *env, t_color_menu *color_menu)
{
	mlx_string_put(env->mlx, env->win, 380, 330, color_menu->black_color,
				"-DOOM- : appuyer sur entrer pour selectionner");
	mlx_string_put(env->mlx, env->win, 560, 530, color_menu->play_color,
				"Jouer");
	mlx_string_put(env->mlx, env->win, 560, 560, color_menu->map1_color,
				"Niveau 1");
	mlx_string_put(env->mlx, env->win, 560, 590, color_menu->map2_color,
				"Niveau 2");
	mlx_string_put(env->mlx, env->win, 560, 620, color_menu->map3_color,
				"Niveau 3");
	mlx_string_put(env->mlx, env->win, 560, 650, color_menu->map4_color,
				"Niveau 4");
	mlx_string_put(env->mlx, env->win, 560, 680, color_menu->exit_color,
				"Quitter");
}

static void			affiche_menu_invalide(t_env *env, t_color_menu *color_menu)
{
	mlx_string_put(env->mlx, env->win, 495, 330, color_menu->black_color,
				"-DOOM- : map invalide");
	mlx_string_put(env->mlx, env->win, 560, 530, color_menu->map1_color,
				"Niveau 1");
	mlx_string_put(env->mlx, env->win, 560, 560, color_menu->map2_color,
				"Niveau 2");
	mlx_string_put(env->mlx, env->win, 560, 590, color_menu->map3_color,
				"Niveau 3");
	mlx_string_put(env->mlx, env->win, 560, 620, color_menu->map4_color,
				"Niveau 4");
	mlx_string_put(env->mlx, env->win, 560, 650, color_menu->exit_color,
				"Quitter");
}

static void			init_color(t_color_menu *color_menu)
{
	color_menu->black_color = 0xFFFFFF;
	color_menu->red_color = 0xc00000;
	color_menu->play_color = color_menu->black_color;
	color_menu->exit_color = color_menu->black_color;
	color_menu->map1_color = color_menu->black_color;
	color_menu->map2_color = color_menu->black_color;
	color_menu->map3_color = color_menu->black_color;
	color_menu->map4_color = color_menu->black_color;
}

void				open_menu(t_env *env)
{
	t_color_menu	color_menu;

	init_color(&color_menu);
	if (env->menu_select == 1)
		color_menu.play_color = color_menu.red_color;
	else if (env->menu_select == 2)
		color_menu.map1_color = color_menu.red_color;
	else if (env->menu_select == 3)
		color_menu.map2_color = color_menu.red_color;
	else if (env->menu_select == 4)
		color_menu.map3_color = color_menu.red_color;
	else if (env->menu_select == 5)
		color_menu.map4_color = color_menu.red_color;
	else if (env->menu_select == 6)
		color_menu.exit_color = color_menu.red_color;
	mlx_put_image_to_window(env->mlx, env->win, env->text[20].img, 0, -10);
	if (env->menu_txt.img == NULL)
		menu_init(env);
	mlx_put_image_to_window(env->mlx, env->win, env->menu_txt.img, 305, 300);
	if (env->map_entree == 0)
		affiche_menu_valide(env, &color_menu);
	else
		affiche_menu_invalide(env, &color_menu);
}
