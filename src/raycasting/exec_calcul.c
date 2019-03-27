/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:40:29 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/27 15:44:56 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void		clean_img(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (200 * 200))
	{
		env->m[1].img_str[x] = (char)0;
		env->m[1].img_str[x + 1] = (char)0;
		env->m[1].img_str[x + 2] = (char)0;
		env->m[1].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
	y = 0;
	x = 0;
	while (y < (1200 * 870))
	{
		env->m[0].img_str[x] = (char)0;
		env->m[0].img_str[x + 1] = (char)0;
		env->m[0].img_str[x + 2] = (char)0;
		env->m[0].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
}

static void	print_text(t_env *env)
{
	int	x;
	int	y;

	x = (int)(env->perso_x / env->coef);
	y = (int)(env->perso_y / env->coef);
	if (env->door.on == 1
			&& (env->tab[y][x + 1] == 7 || env->tab[y][x - 1] == 7
				|| env->tab[y - 1][x] == 7 || env->tab[y + 1][x] == 7))
		mlx_string_put(env->mlx, env->win, 550, 430, 0xe63d3d, "Press E to open");
	if (env->door.off == 1
			&& (env->tab[y][x + 1] == 15 || env->tab[y][x - 1] == 15
				|| env->tab[y - 1][x] == 15 || env->tab[y + 1][x] == 15))
		mlx_string_put(env->mlx, env->win, 550, 430, 0xe63d3d, "Press E to close");
}

static void	init_var(t_env *env, int d_regard)
{
	env->map_entree = 0;
	env->coef = 200 / (env->x);
	init_env(env);
	env->d_regard = d_regard;

	init_sprite(env);
	//	env->inv.gun = 1; // faire quand obj ramasse
	env->inv.lim_gun[0] = 0;   // pour les 4 imgs dans la sprite sheet :
	env->inv.lim_gun[1] = 150; // separation (x) entre chaque 
	env->inv.lim_gun[2] = 365; // theoriquement ... a voir si besoin de le 
	env->inv.lim_gun[3] = 575; // pour chaque sprite sheet ...
	env->inv.lim_gun[4] = 732;
}

void	exec_calcul(t_env *env, int d_regard, int init)
{
	if (init == 1)
		init_var(env, d_regard);
	env->door.on = 0;
	clean_img(env);
	affichage_mur(env);
	color_case(env);
//	quadrillage(env); // enlever pour plus de lisibilite sur la mini map
	print_cercle(env)
;
	//	printf("sprite : {%c,%c,%c,%c}\n", env->sp[1].img_str[400],env->sp[1].img_str[401],env->sp[1].img_str[402],env->sp[1].img_str[403]);
	if (env->inv.gun == 1)
		print_gun(env, 2);
	mlx_put_image_to_window(env->mlx, env->win, env->m[0].img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->m[1].img, 960, 20);
	print_text(env);
}
