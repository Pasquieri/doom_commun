/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:45 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/28 20:59:16 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	init_rgb(t_env *env)
{
	env->rgb[0] = (t_rgb){230, 230, 230, 0}; // blanc
	env->rgb[1] = (t_rgb){88, 68, 21, 100}; // bleu/vert
	env->rgb[2] = (t_rgb){175, 175, 200, 100}; // gris porte
	env->rgb[3] = (t_rgb){159, 161, 255, 0}; // rose
	env->rgb[4] = (t_rgb){159, 0, 240, 0}; // rouge
	env->rgb[5] = (t_rgb){66, 220, 244, 0}; // vert
	env->rgb[6] = (t_rgb){240, 130, 44, 0}; // bleu
	env->rgb[7] = (t_rgb){93, 145, 190, 0}; // marron
	env->rgb[8] = (t_rgb){0, 0, 0, 100}; // noir transparent
	env->rgb[9] = (t_rgb){0, 0, 0, 0}; // noir
}


void	init_env(t_env *env)
{
	env->perso_x = (env->perso_x + 1) * env->coef - env->coef / 2;
	env->perso_y = (env->perso_y + 1) * env->coef - env->coef / 2;
	env->nb_colonne = 1200;
	env->d_ecran = (W_WIDTH / 2) / tan(30 * M_PI / 180);
	env->h_mur = env->coef;
	env->coef_h_wall = 1;
	env->h_regard = W_HEIGHT / 2;
	env->lim = env->x * env->coef - (env->coef / 2);
	env->lum_int = 125;
	env->vitesse = 0.8;
	env->jump = 0;
	env->h_jump = 0;
	env->jump_move = -1;
	env->crouch = 0;
	env->gun = 0;
	env->time = 1;
	number_sprite(env);
	init_tab_sprite(env);
}
