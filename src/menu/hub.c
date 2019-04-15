/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:12:49 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/15 18:04:19 by mpasquie         ###   ########.fr       */
/*   Updated: 2019/04/06 09:26:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/wolf3d.h"

static void		put_pxl(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->hub_end.s_l;
	env->hub_end.img_str[i] = (char)env->rgb[color].b;
	env->hub_end.img_str[i + 1] = (char)env->rgb[color].g;
	env->hub_end.img_str[i + 2] = (char)env->rgb[color].r;
	env->hub_end.img_str[i + 3] = (char)env->rgb[color].a;
}

static void		story_affiche(t_env *env)
{
	int		i;

	i = 30;
	mlx_put_image_to_window(env->mlx, env->win, env->story_mlx, 0, 0);
	mlx_string_put(env->mlx, env->win, 250, 100 - i, 0xFFFFFF,
			"Will Rodeman, un jeune scientifque ambitieux est reste travailler");
	mlx_string_put(env->mlx, env->win, 250, 200 - i, 0xFFFFFF,
			"tard ce soir de noel. Passionne par ses recherches, il est alle au");
	mlx_string_put(env->mlx, env->win, 250, 300 - i, 0xFFFFFF,
			"dela du raisonnable et a fusionne l ADN du singe, du poulpe et du");
	mlx_string_put(env->mlx, env->win, 250, 400 - i, 0xFFFFFF,
			"caniche ! se laissant submerger par ces creatures a plusieurs tetes.");
	mlx_string_put(env->mlx, env->win, 250, 500 - i, 0xFFFFFF,
			"Pris de panique, Dr Rodman s enferme dans son bureau ..");
	mlx_string_put(env->mlx, env->win, 250, 600 - i, 0xFFFFFF,
			"Prenez votre courage a deux mains et eliminez toutes ces abominations");
	mlx_string_put(env->mlx, env->win, 250, 700 - i, 0xFFFFFF,
			"pour vous echapper !");
	mlx_string_put(env->mlx, env->win, 250, 800 - i, 0xFFFFFF,
			"Appuyer sur [y] pour commencer !");
}

void			hub_init(t_env *env)
{
	int	x;
	int	y;

	env->story_mlx = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	env->hub_end.img = mlx_new_image(env->mlx, (W_WIDTH - 400), (W_HEIGHT - 660));
	env->hub_end.img_str = mlx_get_data_addr(env->hub_end.img, &env->hub_end.bpp,
			&env->hub_end.s_l, &env->hub_end.end);
	y = -1;
	while (++y < (W_HEIGHT - 660))
	{
		x = -1;
		while (++x < (W_WIDTH - 400))
			put_pxl(env, x, y, 8);
	}
	env->h_init = 1;
	env->h_life = 100;
//env->h_monkey = 0;
	env->h_monkey = env->sp[4].nb; // nombre de singe
	env->h_ammo = 30;
	env->h_end = 0;
	env->h_story = 1;
}

static void		help_affiche(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->hub_end.img, 200, 400);
	mlx_string_put(env->mlx, env->win, 210, 410, 0xFFFFFF,
			"-- Aide -- Appuyer sur les touches suivantes :");
	mlx_string_put(env->mlx, env->win, 220, 450, 0xFFFFFF,
			"[H] : Ouvrir / Fermer l'aide              [Shift] : Courir");
	mlx_string_put(env->mlx, env->win, 220, 480, 0xFFFFFF,
			"[Enter] : Ouvrir le menu                  [ESC] : Fermer");
	mlx_string_put(env->mlx, env->win, 220, 510, 0xFFFFFF,
			"[WASD] : Se deplacer                      [1] [2] : Skybox");
	mlx_string_put(env->mlx, env->win, 220, 540, 0xFFFFFF,
			"[Fleches] [Souris] : Rotation regard      [1-4] : Hauteur des murs");
	mlx_string_put(env->mlx, env->win, 220, 570, 0xFFFFFF,
			"[+][-] [0][9] : Changer la luminosite     [Space] : Sauter [c] : accroupis");
}

void			print_hub(t_env *env)
{
	char	*message;

	if (env->h_init == 0)
		hub_init(env);
	//env->h_end = 1; //Met fin au niveau
	//env->h_life = 0; // vie du personnage
	//env->h_help = 1; // 1 == affiche l'aide et 0 == l'enleve
	if (env->h_story == 0)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->text[23].img, 10, 10);
		if (env->h_end <= 0)
		{
			mlx_string_put(env->mlx, env->win, 599, 434, 0xFFFFFF,
					"+");
			
			message = chaine_nb("Life : ", env->h_life);
			mlx_string_put(env->mlx, env->win, 170, 10, 0x2B502B, message);
			free(message);
			
			message = chaine_nb("Monkeys : ", env->h_monkey);
			mlx_string_put(env->mlx, env->win, 170, 50, 0x2B502B, message);
			free(message);
			
			message = chaine_nb("Ammo : ", env->h_ammo);
			mlx_string_put(env->mlx, env->win, 170, 90, 0x2B502B, message);
			free(message);
			
			if (env->h_help != 1)
				mlx_string_put(env->mlx, env->win, 170, 130, 0x2B502B,
						"Appuyer sur [H] pour l'aide");
			else
				help_affiche(env);
		}
		else
		{
			mlx_put_image_to_window(env->mlx, env->win, env->hub_end.img, 200, 400);
			if (env->h_life <= 0)
				mlx_string_put(env->mlx, env->win, 510, 450, 0xD51515,
						"Vous avez perdu :(");
			else
				mlx_string_put(env->mlx, env->win, 510, 450, 0x32901D,
						"Vous avez gagne :)");
			mlx_string_put(env->mlx, env->win, 400, 500, 0x1A79D3,
						"Appuyer sur [enter] pour revenir au menu");
			mlx_string_put(env->mlx, env->win, 410, 530, 0x1A79D3,
						"Appuyer sur [esc] pour quitter le jeu");
		}
	}
	else
		story_affiche(env);
}

// donc pour afficher le message de fin il faut que env->H_end = 1
// pour le message de victoire le perso doit finir avec de la vie
// pour le message de defaite le perso doit finir sans vie
