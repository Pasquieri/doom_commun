/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:40:11 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:41:29 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static void		put_pxl(t_env *env, int x, int y, int color)
{
	int			i;

	i = 4 * x + y * env->menu_txt.s_l;
	env->menu_txt.img_str[i] = (char)env->rgb[color].b;
	env->menu_txt.img_str[i + 1] = (char)env->rgb[color].g;
	env->menu_txt.img_str[i + 2] = (char)env->rgb[color].r;
	env->menu_txt.img_str[i + 3] = (char)env->rgb[color].a;
}

void			menu_init(t_env *env)
{
	int			x;
	int			y;

	env->menu_txt.img = mlx_new_image(env->mlx, 600, 420);
	env->menu_txt.img_str = mlx_get_data_addr(env->menu_txt.img,
			&env->menu_txt.bpp, &env->menu_txt.s_l, &env->menu_txt.end);
	y = -1;
	while (++y < (W_HEIGHT - 450))
	{
		x = -1;
		while (++x < (W_WIDTH - 600))
			put_pxl(env, x, y, 8);
	}
}
