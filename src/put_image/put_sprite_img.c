/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:07:12 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 20:30:24 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	put_sprite_img(t_env *env, double h_percue, t_mlx *sp_t, double bep)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	p_x = env->d_begin * 100. / env->diff;
	if (env->img_y > (env->h_regard - bep))
		p_y = (env->img_y - (env->h_regard - bep)) * 100. / h_percue;
	else
		p_y = env->img_y * 100. / h_percue;
	i = 4 * env->img_x + env->img_y * env->m[0].s_l;
	j = 4 * (int)(sp_t->width * p_x / 100)
		+ (int)(sp_t->height * p_y / 100) * sp_t->s_l;
	if (!sp_t->img_str[j + 3])
	{
		env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
		env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
		env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
		env->m[0].img_str[i + 3] = (char)0;
	}
}

void	put_sprite_grid(t_env *env, double h_p, t_mlx *sp_t, double bep)
{
	float	p_x;
	float	p_y;
	int		i;
	int		j;

	if (env->orientation == 0)
		p_x = fmod(env->coord_spr.x, (float)env->coef) * 100 / env->coef;
	else
		p_x = fmod(env->coord_spr.y, (float)env->coef) * 100 / env->coef;
	if (env->img_y > (env->h_regard - bep))
		p_y = (env->img_y - (env->h_regard - bep)) * 100. / h_p;
	else
		p_y = env->img_y * 100. / h_p;
	i = 4 * env->img_x + env->img_y * env->m[0].s_l;
	j = 4 * (int)(sp_t->width * p_x / 100)
		+ (int)(sp_t->height * p_y / 100) * sp_t->s_l;
	if (!sp_t->img_str[j + 3])
	{
		env->m[0].img_str[i] = luminosite((int)sp_t->img_str[j], env->lum);
		env->m[0].img_str[i + 1] = luminosite(sp_t->img_str[j + 1], env->lum);
		env->m[0].img_str[i + 2] = luminosite(sp_t->img_str[j + 2], env->lum);
		env->m[0].img_str[i + 3] = (char)0;
	}
}
