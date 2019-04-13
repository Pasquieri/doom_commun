/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:41:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/11 16:28:59 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int			key_press(int key, t_env *env)
{
	env->key[key] = 1;
	if (env->key[4] == 1)
		env->h_help = env->h_help == 0 ? 1 : 0;
	if (env->key[53])
	{
		system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
		exit(0);
	}
	if (env->key[49])
	{
		if (env->key[49] && !env->menu)
		{
			open_menu(env);
			env->menu = 1;
			return (0);
		}
		else if (env->key[49] && env->menu && env->map_entree == -1)
			key_invalid_menu(env);
		else if (env->key[49] && env->menu && env->map_entree != -1)
			key_valid_menu(env);
	}
	if (env->key[40] && !env->menu) // pour afficher le gun : key k
	{
		if (env->inv.gun == 0)
			env->inv.gun = 1;
		else
			env->inv.gun = 0;
	}
	if (env->key[37] && env->inv.gun == 1 && !env->menu) // coup de feu : key l
	{
		print_gun(env, 3);
		mlx_put_image_to_window(env->mlx,env->win,env->m[0].img, 0,0);
		mlx_put_image_to_window(env->mlx,env->win,env->m[1].img, 960,20);
	}
	if (env->key[29])
		env->lum_int = 255;
	if (env->key[257] && !env->menu)
		env->vitesse = 2;
	if (env->key[14] && !env->menu)
		deal_door(env);
	if ((env->key[18] || env->key[19]) && !env->menu)
	{
		if (env->skybox != 22 && env->key[18])
			env->skybox = 22;
		else if (env->skybox != 24 && env->key[19])
			env->skybox = 24;
		else
			env->skybox = 0;
	}
	if (env->key[83] || env->key[84] || env->key[85] || env->key[86])
	{
		if (env->key[83])
			env->coef_h_wall = 1;
		else if (env->key[84])
			env->coef_h_wall = 3;
		else if (env->key[85])
			env->coef_h_wall = 5;
		else if (env->key[86])
			env->coef_h_wall = 7;
	}
	if (env->key[8] && !env->menu)
		env->jump = 1;
	if (env->key[12])
	{
		printf("nb grid : %d, win : %d, column : %d, banana : %d, monkey : %d, door : %d\n", env->sp[0].nb, env->sp[1].nb, env->sp[2].nb, env->sp[3].nb, env->sp[4].nb, env->sp[5].nb);
	/*	int i;
		int	k;

		i = -1;
		while (++i <= 5)
		{
			k = -1;
			printf("type sprite : %d\n", i);
			while (++k < env->sp[i].nb)
			{
				if (env->sp[i].sprite[k].detec[0].on == 1)
					printf("horizontal : %d\n", i+10);
				else
					printf("NULL horizontal\n");
				if (env->sp[i].sprite[k].detec[1].on == 1)
					printf("vertical : %d\n", i+10);
				else
					printf("NULL vertical\n");
				printf("\n");
			}
			printf("\n");
		}*/

/*** pour chaque sprite : affiche leur pos etc ***/

/*		int	i;
		printf("\ngrid = nb : %d, val : %d\n",env->sp[0].nb, env->sp[0].val);
		i = -1;
		while (++i < env->sp[0].nb)
			printf("sprite %d : i = %d, j = %d\n",i, env->sp[0].sprite[i].i,env->sp[0].sprite[i].j);

		printf("\nwin = nb : %d, val : %d\n",env->sp[1].nb, env->sp[1].val);
		i = -1;
		while (++i < env->sp[1].nb)
			printf("sprite %d : i = %d, j = %d\n",i, env->sp[1].sprite[i].i,env->sp[1].sprite[i].j);

		printf("\ncolumn = nb : %d, val : %d\n",env->sp[2].nb, env->sp[2].val);
		i = -1;
		while (++i < env->sp[2].nb)
			printf("sprite %d : i = %d, j = %d\n",i, env->sp[2].sprite[i].i,env->sp[2].sprite[i].j);

		printf("\nbanana = nb : %d, val : %d\n",env->sp[3].nb, env->sp[3].val);
		i = -1;
		while (++i < env->sp[3].nb)
			printf("sprite %d : i = %d, j = %d\n",i, env->sp[3].sprite[i].i,env->sp[3].sprite[i].j);

		printf("\nmonkey = nb : %d, val : %d\n",env->sp[4].nb, env->sp[4].val);
		i = -1;
		while (++i < env->sp[4].nb)
			printf("sprite %d : i = %d, j = %d\n",i, env->sp[4].sprite[i].i,env->sp[4].sprite[i].j);

		printf("\ndoor = nb : %d, val : %d\n",env->sp[5].nb, env->sp[5].val);
		i = -1;
		while (++i < env->sp[5].nb)
			printf("sprite %d : i = %d, j = %d\n",i, env->sp[5].sprite[i].i,env->sp[5].sprite[i].j);*/
	}
	return (0);
}

int			key_release(int key, t_env *env)
{
	env->key[key] = 0;
	if (key == 257 && !env->menu)
		env->vitesse = 0.8;
	return (0);
}

static void	ft_arrow_menu(t_env *env)
{
	arrow_menu(env);
	env->key[125] = 0;
	env->key[126] = 0;
}

int			key_apply(t_env *env)
{
	int jump_height = 100;
	if (env->jump != 0) // si touche saut
	{
		if (env->jump > 0) // si saut en mode "monter"
		{
			if (env->jump > 1) // on monte le saut de 1
			{
				env->jump = 0;
				if (env->h_jump + jump_height < 8 * jump_height) // si monter est possible
				{
					env->h_jump += jump_height;
					env->h_jump2 += jump_height - 10;
					//env->h_regard += jump_height; // alors on monte
				}
				else
					env->jump = -2; // alors on dessend
			}
			env->jump = env->jump + 1;
		}
		if (env->jump < 0) // si saut en mode "dessendre"
		{
			if (env->jump < 2) // on descend le saut de 1
			{
				env->jump = 0;
				if (env->h_jump - jump_height > 0) // si descendre est possible
				{
					env->h_jump -= jump_height;
					env->h_jump2 -= jump_height - 5;
					//env->h_regard -= jump_height; // alors on descend
				}
				else // si on peut pas dessendre
				{
					env->jump = 1;
					env->h_jump = 0;
					env->h_jump2 = 0;
					//env->h_regard = W_HEIGHT / 2; // on reinitialise
				}
			}
			env->jump = env->jump - 1;
		}
	}
	
	if ((env->key[125] || env->key[126]) && env->menu == 1)
		ft_arrow_menu(env);
	if (!env->menu)
		trig_press(env);
	return (0);
}

