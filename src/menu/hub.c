/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:57:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:54:00 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void		story_affiche(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->story_mlx, 0, 0);
	mlx_string_put(env->mlx, env->win, 250, 70, 0xFFFFFF,
		"Will Rodman, un jeune scientifique ambitieux est reste travailler");
	mlx_string_put(env->mlx, env->win, 250, 130, 0xFFFFFF,
		"tard ce soir de noel.");
	mlx_string_put(env->mlx, env->win, 250, 190, 0xFFFFFF,
		"Passionne par ses recherches, il est alle au dela du raisonnable et");
	mlx_string_put(env->mlx, env->win, 250, 250, 0xFFFFFF,
		"a fusionne l'ADN du singe, du poulpe et du caniche !");
	mlx_string_put(env->mlx, env->win, 250, 310, 0xFFFFFF,
		"L'experience suivait son cours quand tout d'un coup, le Dr Rodman");
	mlx_string_put(env->mlx, env->win, 250, 370, 0xFFFFFF,
		"fut submerge et une seconde tete apparut sur le singe ...");
	mlx_string_put(env->mlx, env->win, 250, 430, 0xFFFFFF,
		"Alors que celui-ci succombe a la terreur, une troisieme tete vient");
	mlx_string_put(env->mlx, env->win, 250, 490, 0xFFFFFF,
		"rejoindre ses comperes.");
	mlx_string_put(env->mlx, env->win, 250, 550, 0xFFFFFF,
		"Pris de panique, le Dr Rodman s'enferme dans son bureau...");
	mlx_string_put(env->mlx, env->win, 250, 650, 0xFFFFFF,
		"Apres une longue attente, il est temps d'agir, prenez votre courage");
	mlx_string_put(env->mlx, env->win, 250, 710, 0xFFFFFF,
		"a deux mains et eliminez toutes ces abominations pour vous echapper!");
	mlx_string_put(env->mlx, env->win, 250, 760, 0xFFFFFF,
		"                Appuyez sur [y] pour commencer !                  ");
}

static void		help_affiche(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->hub_end.img, 200, 400);
	mlx_string_put(env->mlx, env->win, 210, 410, 0xFFFFFF,
		"-- Aide -- Appuyez sur les touches suivantes :");
	mlx_string_put(env->mlx, env->win, 220, 450, 0xFFFFFF,
		"[H] : Ouvrir / Fermer l'aide              [Shift] : Courir");
	mlx_string_put(env->mlx, env->win, 220, 480, 0xFFFFFF,
		"[Enter] : Ouvrir le menu                  [ESC] : Fermer");
	mlx_string_put(env->mlx, env->win, 220, 510, 0xFFFFFF,
		"[WASD] : Se deplacer                      [1] [2] : Skybox");
	mlx_string_put(env->mlx, env->win, 220, 540, 0xFFFFFF,
		"[Fleches] [Souris] : Rotation regard      [1-4] : Hauteur des murs");
	mlx_string_put(env->mlx, env->win, 220, 570, 0xFFFFFF,
		"[+][-] [0][9] : Changer la luminosite     [Space][c] Sauter Baisser");
}

static void		affiche_hub_extra(t_env *env)
{
	char		*message;

	mlx_string_put(env->mlx, env->win, 599, 434, 0xFFFFFF, "+");
	message = chaine_nb("Life : ", env->h_life, 0, 0);
	mlx_string_put(env->mlx, env->win, 170, 10, 0x2B502B, message);
	free(message);
	message = chaine_nb("Monkeys : ", env->h_monkey, 0, 0);
	mlx_string_put(env->mlx, env->win, 170, 50, 0x2B502B, message);
	free(message);
	message = chaine_nb("Ammo : ", env->h_ammo, 0, 0);
	mlx_string_put(env->mlx, env->win, 170, 90, 0x2B502B, message);
	free(message);
	if (env->h_help != 1)
		mlx_string_put(env->mlx, env->win, 170, 130, 0x2B502B,
				"Appuyez sur [H] pour l'aide");
	else
		help_affiche(env);
}

static void		affiche_hub(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->hub_end.img, 200, 400);
	if (env->h_life <= 0)
		mlx_string_put(env->mlx, env->win, 510, 450, 0xD51515,
			"Vous avez perdu :(");
	else
	{
		if (env->h_monkey <= 0)
			mlx_string_put(env->mlx, env->win, 510, 450, 0x32901D,
				"Vous avez gagne :)");
		else
			mlx_string_put(env->mlx, env->win, 365, 450, 0x32901D,
				"Vous aviez presque gagne, il reste des singes :/");
	}
	mlx_string_put(env->mlx, env->win, 400, 500, 0x1A79D3,
		"Appuyez sur [enter] pour revenir au menu");
	mlx_string_put(env->mlx, env->win, 410, 530, 0x1A79D3,
		"Appuyez sur [esc] pour quitter le jeu");
}

void			print_hub(t_env *env)
{
	if (env->h_init == 0)
		hub_init(env);
	if (env->h_story == 0)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->text[23].img, 10, 10);
		if (env->h_end <= 0)
			affiche_hub_extra(env);
		else
			affiche_hub(env);
	}
	else
		story_affiche(env);
}
