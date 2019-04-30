/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:51:35 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 21:38:47 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void		put_pxl_img(t_env *env, int x, int y, int color)
{
	int	i;
	int	k;

	if (color <= 5)
		k = 1;
	else
		k = 0;
	i = 4 * x + y * env->m[k].s_l;
	env->m[k].img_str[i] = (char)env->rgb[color].b;
	env->m[k].img_str[i + 1] = (char)env->rgb[color].g;
	env->m[k].img_str[i + 2] = (char)env->rgb[color].r;
	env->m[k].img_str[i + 3] = (char)env->rgb[color].a;
}
