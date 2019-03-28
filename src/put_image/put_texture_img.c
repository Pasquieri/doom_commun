/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:49:23 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/28 19:03:35 by cpalmier         ###   ########.fr       */
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

void		put_texture_img(t_env *env, double h_percue, int y, t_mlx *text)
{
	float	pourcent_x;
	float	pourcent_y;
	int		i;
	int		j;

	if (env->orientation == 1)
		pourcent_x = fmod(env->coord_mur.x, (float)env->coef) * 100 / env->coef;
	else
		pourcent_x = fmod(env->coord_mur.y, env->coef) * 100 / env->coef;
	if (y > (env->h_regard - (h_percue / 2)))
		pourcent_y = (y - (env->h_regard - (h_percue / 2.))) * 100. / h_percue;
	else
		pourcent_y = y * 100. / h_percue;
	i = 4 * env->img_x + y * env->m[0].s_l;
	j = 4 * (int)(text->width * pourcent_x / 100)
		+ (int)(text->height * pourcent_y / 100) * text->s_l;
	env->m[0].img_str[i] = luminosite((int)text->img_str[j], env->lum);
	env->m[0].img_str[i + 1] = luminosite(text->img_str[j + 1], env->lum);
	env->m[0].img_str[i + 2] = luminosite(text->img_str[j + 2], env->lum);
	env->m[0].img_str[i + 3] = (char)0;
	if (env->wall_nb >= 4 && env->wall_nb <= 6)
	{
		env->img_y = y;
		print_tab(env, pourcent_y, pourcent_x, &env->sp[5]); // sp[5] == tableau
	}
	if (env->wall_nb == 7 && env->dist < env->coef - 1)
		do_door(env);
}
