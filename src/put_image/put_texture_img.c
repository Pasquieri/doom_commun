/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:49:23 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/12 20:51:44 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

char		luminosite(int text, int coef)
{
	int		tmp;

	if (text < 0)
		text = text + 256;
	tmp = text - coef;
	tmp < 0 ? tmp = 0 : tmp;
	tmp > 255 ? tmp = 255 : tmp;
	return ((char)tmp);
}

void		put_texture_img(t_env *env, double h_percue, int y, t_mlx *text, double bep)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	if (env->orientation == 0)
		p_x = fmod(env->coord_mur.x, (float)env->coef) * 100 / env->coef;
	else
		p_x = fmod(env->coord_mur.y, (float)env->coef) * 100 / env->coef;
	if (y > (env->h_regard - (env->cmp_wall * bep)))
		p_y = (y - (env->h_regard - (env->cmp_wall * bep))) * 100. / h_percue;
	else
		p_y = y * 100. / h_percue;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(text->width * p_x / 100)
		+ (int)(text->height * p_y / 100) * text->s_l;
	env->m[0].img_str[i] = luminosite((int)text->img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(text->img_str[j + 1], env->lum);
	env->m[0].img_str[i + 2] = luminosite(text->img_str[j + 2], env->lum);
	env->m[0].img_str[i + 3] = (char)0;
	if (env->wall_nb >= 4 && env->wall_nb <= 6 && env->cmp_wall == 1)
	{
		env->img_y = y;
		print_tab(env, p_y, p_x, &env->sp_t[7]); // sp[7] == tableau
	}
}
