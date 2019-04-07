/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:12:49 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/07 13:20:08 by mpasquie         ###   ########.fr       */
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

void			hub_init(t_env *env)
{
	int	x;
	int	y;

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
//	env->H_mlx = mlx_new_image(env->mlx, 400, 75);
//	env->H_end_mlx = mlx_new_image(env->mlx, (W_WIDTH - 400), (W_HEIGHT - 660));
	env->H_init = 1;
	env->H_life = 100;
//	env->H_monkey = 0;
	env->H_monkey = env->sp[4].nb; // nombre de singe
	env->H_ammo = 30;
	env->H_end = 0;
}

void			print_hub(t_env *env)
{
	if (env->H_init == 0)
		hub_init(env);
	//env->H_end = 1;
	//env->H_life = 0;
	mlx_put_image_to_window(env->mlx, env->win, env->text[23].img, 10, 10);
	if (env->H_end <= 0)
	{
		mlx_string_put(env->mlx, env->win, 599, 434, 0xFFFFFF,
				"+");
		mlx_string_put(env->mlx, env->win, 30, 740, 0x2B502B,
				chaine_nb("Life : ", env->H_life));
		mlx_string_put(env->mlx, env->win, 30, 780, 0x2B502B,
				chaine_nb("Monkeys : ", env->H_monkey));
		mlx_string_put(env->mlx, env->win, 30, 820, 0x2B502B,
				chaine_nb("Ammo : ", env->H_ammo));
	}
	else
	{
		//mlx_put_image_to_window(env->mlx, env->win, env->H_end_mlx, 200, 400);
		mlx_put_image_to_window(env->mlx, env->win, env->hub_end.img, 200, 400);
		if (env->H_life <= 0)
			mlx_string_put(env->mlx, env->win, 510, 450, 0xD51515,
					"Vous avez perdu :(");
		else
			mlx_string_put(env->mlx, env->win, 510, 450, 0x32901D,
					"Vous avez gagne :)");
		mlx_string_put(env->mlx, env->win, 400, 500, 0x1A79D3,
					"Appuyer sur [espace] pour revenir au menu");
		mlx_string_put(env->mlx, env->win, 410, 530, 0x1A79D3,
					"Appuyer sur [esc] pour quitter le jeu");
	}
}

// donc pour afficher le message de fin il faut que env->H_end = 1
// pour le message de victoire le perso doit finir avec de la vie
// pour le message de defaite le perso doit finir sans vie
