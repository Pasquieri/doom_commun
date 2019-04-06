/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:41:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/06 09:44:42 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int			key_press(int key, t_env *env)
{
	env->key[key] = 1;
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
	if (env->key[18] && !env->menu)
	{
		if (!env->skybox)
			env->skybox = 1;
		else
			env->skybox = 0;
	}
	if (env->key[12])
	{
		printf("nb grid : %d, win : %d, column : %d, banana : %d, monkey : %d, door : %d\n", env->sp[0].nb, env->sp[1].nb, env->sp[2].nb, env->sp[3].nb, env->sp[4].nb, env->sp[5].nb);
/*		int i;
		int	k;

		i = -1;
		while (++i <= 5)
		{
			k = -1;
			printf("type sprite : %d\n", i);
			while (++k < env->sp[i].nb)
			{
				if (env->sp[i].sprite[k].detec_hor == 1)
					printf("horizontal : %d\n", i+10);
				else
					printf("NULL horizontal\n");
				if (env->sp[i].sprite[k].detec_ver == 1)
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


	if ((env->key[14] && env->door.on) || (env->door.off && env->key[14]))
	{
		deal_door(env);
		exec_calcul(env, env->d_regard, 0);
		printf("door_on : %d, door_off : %d\n",env->door.on, env->door.off);
	}
	return (0);
}

int			key_release(int key, t_env *env)
{
	env->key[key] = 0;
	if (key == 257 && !env->menu)
		env->vitesse = 0.5;
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
	if ((env->key[125] || env->key[126]) && env->menu == 1)
		ft_arrow_menu(env);
	if (!env->menu)
		trig_press(env);
	return (0);
}
