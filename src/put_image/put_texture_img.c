/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:49:23 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/26 19:10:40 by cpalmier         ###   ########.fr       */
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

static void	print_tab(t_env *env, float p_y, float p_x, t_mlx *sp)
{
	int		i;
	int		j;
	float	p_x_tab;
	float	p_y_tab;

	if (p_y < 33.3 || p_y > 66.6 || p_x < 29 || p_x > 71)
		return ;
	else
	{
		p_x_tab = (p_x - 29) * 100 / 42.0;
		p_y_tab = (p_y - 33.3) * 100 / 33.4;
		i = 4 * env->img_x + env->img_y * env->m[0].s_l;
		j = 4 * (int)(sp->width * p_x_tab / 100)
			+ (int)(sp->height * p_y_tab / 100) * sp->s_l;
		env->m[0].img_str[i] = luminosite((int)sp->img_str[j], env->lum);
		env->m[0].img_str[i + 1] = luminosite(sp->img_str[j + 1], env->lum);
		env->m[0].img_str[i + 2] = luminosite(sp->img_str[j + 2], env->lum);
		env->m[0].img_str[i + 3] = (char)0;
	}
}

void	deal_door(t_env *env)
{
	int	i;
	int	j;

	i = env->door.i;
	j = env->door.j;
	if (env->tab[j][i] == 7 && env->door.on)
	{
		env->tab[j][i] = 15;
		env->door.off = 1;
		env->door.on = 0;
	}
	else if (env->tab[j][i] == 15)
	{
		env->tab[j][i] = 7;
		env->door.off = 0;
	}
}

static void	do_door(t_env *env)
{
	int	i;
	int	j;


	i = (int)(env->coord_mur.x / env->coef);
	j = (int)(env->coord_mur.y / env->coef);
	env->door.i = i;
	env->door.j = j;
	if (env->tab[j][i + 1] == 7)
		env->door.i = i + 1;
	else if (env->tab[j][i - 1] == 7)
		env->door.i = i - 1;
	else if (env->tab[j + 1][i] == 7)
		env->door.j = j + 1;
	else if (env->tab[j - 1][i] == 7)
		env->door.j = j - 1;
	env->door.on = 1;
	env->door.off = 0;
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
