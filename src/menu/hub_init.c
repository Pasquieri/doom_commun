/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:01:59 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/27 17:12:38 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void		put_pxl(t_env *env, int x, int y, int color)
{
	int			i;

	i = 4 * x + y * env->hub_end.s_l;
	env->hub_end.img_str[i] = (char)env->rgb[color].b;
	env->hub_end.img_str[i + 1] = (char)env->rgb[color].g;
	env->hub_end.img_str[i + 2] = (char)env->rgb[color].r;
	env->hub_end.img_str[i + 3] = (char)env->rgb[color].a;
}

void			hub_init(t_env *env)
{
	int			x;
	int			y;

	env->story_mlx = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	env->hub_end.img = mlx_new_image(env->mlx, (1200 - 400), (870 - 660));
	env->hub_end.img_str = mlx_get_data_addr(env->hub_end.img,
			&env->hub_end.bpp, &env->hub_end.s_l, &env->hub_end.end);
	y = -1;
	while (++y < (W_HEIGHT - 660))
	{
		x = -1;
		while (++x < (W_WIDTH - 400))
			put_pxl(env, x, y, 8);
	}
	env->h_init = 1;
	env->h_life = 100;
	env->h_monkey = env->sp[4].nb;
	env->h_ammo = 30;
	env->h_end = 0;
	env->h_story = 1;
}
