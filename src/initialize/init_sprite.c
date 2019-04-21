/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:48:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/21 21:09:07 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	init_sprite_extra(t_env *env)
{
	env->sp_t[5].img = mlx_xpm_file_to_image(env->mlx,
		"textures/7-door.XPM", &env->sp_t[5].width,
		&env->sp_t[5].height);
	env->sp_t[6].img = mlx_xpm_file_to_image(env->mlx,
		"textures/gun.XPM", &env->sp_t[6].width, &env->sp_t[6].height);
	env->sp_t[7].img = mlx_xpm_file_to_image(env->mlx,
		"textures/4-5-6-van_gogh.XPM", &env->sp_t[7].width,
		&env->sp_t[7].height);
	env->sp_t[8].img = mlx_xpm_file_to_image(env->mlx,
		"textures/seringue.XPM", &env->sp_t[8].width, &env->sp_t[8].height);
}

void		init_sprite(t_env *env)
{
	env->sp_t[0].img = mlx_xpm_file_to_image(env->mlx,
		"textures/8-grid.XPM", &env->sp_t[0].width, &env->sp_t[0].height);
	env->sp_t[1].img = mlx_xpm_file_to_image(env->mlx,
		"textures/9-win4.xpm", &env->sp_t[1].width, &env->sp_t[1].height);
	env->sp_t[2].img = mlx_xpm_file_to_image(env->mlx,
		"textures/12-column.XPM", &env->sp_t[2].width, &env->sp_t[2].height);
//printf("w : %d, h : %d\n", env->sp_t[2].width, env->sp_t[2].height);
	env->sp_t[3].img = mlx_xpm_file_to_image(env->mlx,
		"textures/13-banana.XPM", &env->sp_t[3].width, &env->sp_t[3].height);
	env->sp_t[4].img = mlx_xpm_file_to_image(env->mlx,
		"textures/monkeymiddle.XPM", &env->sp_t[4].width, &env->sp_t[4].height);
	init_sprite_extra(env);
}

void		number_sprite(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < NB_SP)
		env->sp[i].nb = 0;
	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if (env->tab[j][i] == DOOR) // || == 15 ??
				env->sp[5].nb++;
			else if ((env->tab[j][i] >= 10 && env->tab[j][i] <= 15) || env->tab[j][i] == 18)
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
	if (sp->val == COLUMN || sp->val == BANANA || sp->val == MONKEY || sp->val == SYRINGE)
	{
		pos_x = i * coef + coef / 2;
		pos_y = j * coef + coef / 2;
		sp->sprite[*x].c.mid.x = pos_x;
		sp->sprite[*x].c.mid.y = pos_y;
		/***************** 18/04/19 *********************/
		pos_x = i * coef;
		pos_y = j * coef;
	//	sp->sprite[*x].t.mid.x = pos_x;
	//	sp->sprite[*x].t.mid.y = pos_y;
		sp->sprite[*x].c.left_h.x = pos_x;
		sp->sprite[*x].c.left_h.y = pos_y;
		sp->sprite[*x].c.right_h.x = pos_x + coef;
		sp->sprite[*x].c.right_h.y = pos_y;
		sp->sprite[*x].c.right_b.x = pos_x + coef;
		sp->sprite[*x].c.right_b.y = pos_y + coef;
		sp->sprite[*x].c.left_b.x = pos_x;
		sp->sprite[*x].c.left_b.y = pos_y + coef;
		/************************************************/
	}
	// 15 : open = 1 ??
	*x += 1;
}

void		init_tab_sprite(t_env *env)
{
	int	k;
	int	i;
	int	j;
	int	x;

	k = -1;
	while (++k < NB_SP)
	{
	//	if (k == 6)
	//		k += 2;
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
				if (env->tab[j][i] == env->sp[k].val ||
						(k == 5 && env->tab[j][i] == 15)) // 15 ??
					fill_info_sprite(&env->sp[k], &x, i, j);
			}
		}
	}
}
