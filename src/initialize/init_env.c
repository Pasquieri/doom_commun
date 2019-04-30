/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:45 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 22:07:27 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	init_rgb(t_env *env)
{
	env->rgb[0] = (t_rgb){230, 230, 230, 0};
	env->rgb[1] = (t_rgb){88, 68, 21, 100};
	env->rgb[2] = (t_rgb){175, 175, 200, 100};
	env->rgb[3] = (t_rgb){159, 161, 255, 0};
	env->rgb[4] = (t_rgb){159, 0, 240, 0};
	env->rgb[5] = (t_rgb){66, 220, 244, 0};
	env->rgb[6] = (t_rgb){240, 130, 44, 0};
	env->rgb[7] = (t_rgb){93, 145, 190, 0};
	env->rgb[8] = (t_rgb){0, 0, 0, 100};
	env->rgb[9] = (t_rgb){0, 0, 0, 0};
}

void	number_sprite(t_env *env)
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
			if (env->tab[j][i] == DOOR)
				env->sp[5].nb++;
			else if (env->tab[j][i] >= 10 && env->tab[j][i] <= 16)
				env->sp[env->tab[j][i] - 10].nb++;
			else if (env->tab[j][i] >= 4 && env->tab[j][i] <= 6)
				env->sp[7].nb++;
		}
	}
}

void	init_env(t_env *env)
{
	int	i;

	i = -1;
	while (++i < 604)
		env->key[i] = 0;
	env->perso_x = (env->perso_x + 1) * env->coef - env->coef / 2;
	env->perso_y = (env->perso_y + 1) * env->coef - env->coef / 2;
	env->nb_colonne = 1200;
	env->d_ecran = (W_WIDTH / 2) / tan(30 * M_PI / 180);
	env->h_mur = env->coef;
	env->coef_h_wall = 1;
	env->h_regard = W_HEIGHT / 2;
	env->lim = env->x * env->coef - (env->coef / 2);
	env->lum_int = 125;
	env->vitesse = SPEED;
	env->jump = 0;
	env->h_jump = 0;
	env->jump_move = -1;
	env->crouch = 0;
	env->gun = 0;
	env->time = 1;
	number_sprite(env);
	init_tab_sprite(env);
}
