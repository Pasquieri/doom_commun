/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:45 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/26 18:59:49 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void		init_rgb(t_env *env)
{
	env->rgb[0] = (t_rgb){230, 230, 230, 0}; // blanc
	env->rgb[1] = (t_rgb){113, 170, 10, 100}; // vert
	env->rgb[2] = (t_rgb){175, 175, 200, 100}; // gris porte
	env->rgb[3] = (t_rgb){159, 161, 255, 0}; // rose
	env->rgb[5] = (t_rgb){130, 227, 130, 0}; // vert
	env->rgb[6] = (t_rgb){240, 130, 44, 0}; // bleu
	env->rgb[7] = (t_rgb){93, 145, 190, 0}; // marron
}

/*	env->nb_grid = 0;    #10
	env->nb_win = 0;     #11
	env->nb_column = 0;  #12
	env->nb_banana = 0;  #13
	env->nb_monkey = 0;  #14
	env->nb_door = 0;    #7   */

static void	number_sprite(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 5)
		env->nb_sp[i] = 0;
	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if (env->tab[j][i] == 7)
				env->nb_sp[5]++;
			else if (env->tab[j][i] >= 10 && env->tab[j][i] <= 14)
				env->nb_sp[env->tab[j][i] - 10]++;
		}
	}
}

static void	init_tab_sprite(t_env *env)
{
	int	i;
	int	j;
	int	x;

	env->spr[5].nb = env->nb_sp[5];
	env->spr[5].val = 7;
	x = 0;
	if (env->spr[5].nb != 0)
		if (!(env->spr[5].coord = (t_index *)malloc(sizeof(t_index) * (env->spr[5].nb))))
			return ;
	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if (env->tab[j][i] == env->spr[5].val && x < env->spr[5].nb)
			{
				env->spr[5].coord[x].j = j;
				env->spr[5].coord[x].i = i;
				x++;
			}
		}
	}
}

/*static void	init_tab_sprite(t_env *env)
  {
  int	k;
  int	i;
  int	j;
  int	x;

  k = -1;
  while (k <= 5)
  {
  env->spr[k].nb = env->nb_sp[k];
  env->spr[k].val = k + 10;
  if (k == 5)
  env->spr[k].val = 7;
  x = 0;
  if (!(env->spr[k].coord = (t_index *)malloc(sizeof(t_index) * (env->spr[k].nb + 1))))
  return ;
  j = -1;
  while (++j < env->y)
  {
  i = -1;
  while (++i < env->x)
  {
  if (env->tab[j][i] == env->spr[k].val)
  {
  env->spr[k].coord[x].i = i;
  env->spr[k].coord[x].j = j;
  x++;
  }
  }
  }
  }
  }*/

void	init_env(t_env *env)
{
	/*	env->d_regard = 0;
		env->d_regard = env->d_regard % 360;
		if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;*/
	env->perso_x = (env->perso_x + 1) * env->coef - env->coef / 2;
	env->perso_y = (env->perso_y + 1) * env->coef - env->coef / 2;
	env->nb_colonne = 1200; //
	env->d_ecran = (env->nb_colonne / 2) / tan(30 * M_PI / 180);
	env->h_mur = env->coef;
	env->h_regard = 870 / 2;
	env->lim = env->x * env->coef - (env->coef / 2);
	env->lum_int = 220;
	env->vitesse = 0.5;
	number_sprite(env);
	init_tab_sprite(env);
}
