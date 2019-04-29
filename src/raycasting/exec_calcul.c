/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:40:29 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/29 21:29:23 by cpalmier         ###   ########.fr       */
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
	while (y < (W_WIDTH * W_HEIGHT))
	{
		env->m[0].img_str[x] = (char)0;
		env->m[0].img_str[x + 1] = (char)0;
		env->m[0].img_str[x + 2] = (char)0;
		env->m[0].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
}

static void	init_var(t_env *env)
{
	env->map_entree = 0;
	env->coef = 200 / (env->x);
	init_env(env);
	env->d_regard = env->perso_r;
	env->gun = 1;
}

static void	print_text(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->sp[5].nb)
	{
		if (env->sp[5].sprite[i].proximity == 1
				&& env->sp[5].sprite[i].open == 0)
			mlx_string_put(env->mlx, env->win, 525, 420, 0xe63d3d,
					"Press E to open");
		else if (env->sp[5].sprite[i].proximity == 1
				&& env->sp[5].sprite[i].open == 1)
			mlx_string_put(env->mlx, env->win, 520, 450, 0xe63d3d,
					"Press E to close");
	}
	i = -1;
	while (++i < env->sp[7].nb)
	{
		if (env->sp[7].sprite[i].proximity == 1)
			mlx_string_put(env->mlx, env->win, 480, 470, 0xe1e3e8,
					"Press Q to change the sky");
	}
}

void		exec_calcul(t_env *env, int init)
{
	env->img_x = 0;
	env->angle_thread = 0;
	if (init == 1)
		init_var(env);
	clean_img(env);
	ft_pthread(env);
	affichage_sprite(env);
	color_case(env);
	print_cercle(env);
	if (env->gun == 1)
		print_gun(env, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->m[0].img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->m[1].img, 960, 20);
	print_text(env);
	print_hub(env);
}
