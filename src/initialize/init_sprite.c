/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:48:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/08 13:42:11 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	init_sprite_extra(t_env *env)
{
	env->sp_t[5].img = mlx_xpm_file_to_image(env->mlx,
		"textures/4-5-6-van_gogh.XPM", &env->sp_t[5].width,
		&env->sp_t[5].height);
	env->sp_t[5].img_str = mlx_get_data_addr(env->sp_t[5].img,
		&env->sp_t[5].bpp, &env->sp_t[5].s_l, &env->sp_t[5].end);
	env->sp_t[6].img = mlx_xpm_file_to_image(env->mlx,
		"textures/gun.XPM", &env->sp_t[6].width, &env->sp_t[6].height);
	env->sp_t[6].img_str = mlx_get_data_addr(env->sp_t[6].img,
		&env->sp_t[6].bpp, &env->sp_t[6].s_l, &env->sp_t[6].end);
}

void		init_sprite(t_env *env)
{
	env->sp_t[0].img = mlx_xpm_file_to_image(env->mlx,
		"textures/8-grid.XPM", &env->sp_t[0].width, &env->sp_t[0].height);
	env->sp_t[0].img_str = mlx_get_data_addr(env->sp_t[0].img,
		&env->sp_t[0].bpp, &env->sp_t[0].s_l, &env->sp_t[0].end);
	env->sp_t[1].img = mlx_xpm_file_to_image(env->mlx,
		"textures/9-window.XPM", &env->sp_t[1].width, &env->sp_t[1].height);
	env->sp_t[1].img_str = mlx_get_data_addr(env->sp_t[1].img,
		&env->sp_t[1].bpp, &env->sp_t[1].s_l, &env->sp_t[1].end);
	env->sp_t[2].img = mlx_xpm_file_to_image(env->mlx,
		"textures/12-column_edit.XPM", &env->sp_t[2].width, &env->sp_t[2].height);
	env->sp_t[2].img_str = mlx_get_data_addr(env->sp_t[2].img,
		&env->sp_t[2].bpp, &env->sp_t[2].s_l, &env->sp_t[2].end);
//printf("w : %d, h : %d\n", env->sp_t[2].width, env->sp_t[2].height);
	env->sp_t[3].img = mlx_xpm_file_to_image(env->mlx,
		"textures/13-banana.XPM", &env->sp_t[3].width, &env->sp_t[3].height);
	env->sp_t[3].img_str = mlx_get_data_addr(env->sp_t[3].img,
		&env->sp_t[3].bpp, &env->sp_t[3].s_l, &env->sp_t[3].end);
	env->sp_t[4].img = mlx_xpm_file_to_image(env->mlx,
		"textures/14-monkey.XPM", &env->sp_t[4].width, &env->sp_t[4].height);
	env->sp_t[4].img_str = mlx_get_data_addr(env->sp_t[4].img,
		&env->sp_t[4].bpp, &env->sp_t[4].s_l, &env->sp_t[4].end);
	init_sprite_extra(env);
}

void		number_sprite(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 5)
		env->sp[i].nb = 0;
	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if (env->tab[j][i] == 7)
				env->sp[5].nb++;
			else if (env->tab[j][i] >= 10 && env->tab[j][i] <= 14)
				env->sp[env->tab[j][i] - 10].nb++;
		}
	}
}

static void	fill_info_sprite(t_sp *sp, int *x, int i, int j)
{
	double	pos_x;
	double	pos_y;
	double	coef;

	coef = 5.;
	sp->sprite[*x].i = i;
	sp->sprite[*x].j = j;
	if (sp->val == COLUMN || sp->val == BANANA || sp->val == MONKEY)
	{
		pos_x = i * coef + coef / 2;
		pos_y = j * coef + coef / 2;
		sp->sprite[*x].cd.x = pos_x;
		sp->sprite[*x].cd.y = pos_y;
	}
	*x += 1;
}

void		init_tab_sprite(t_env *env)
{
	int	k;
	int	i;
	int	j;
	int	x;

	k = -1;
	while (++k <= 5)
	{
		env->sp[k].val = k + 10;
		k == 5 ? env->sp[k].val = 7 : env->sp[k].val;
		x = 0;
		if (!(env->sp[k].sprite = (t_sprite *)malloc(sizeof(t_sprite)
						* (env->sp[k].nb + 1))))
			return ;
		j = -1;
		while (++j < env->y)
		{
			i = -1;
			while (++i < env->x)
			{
				if (env->tab[j][i] == env->sp[k].val)
					fill_info_sprite(&env->sp[k], &x, i, j);
			}
		}
	}
}
