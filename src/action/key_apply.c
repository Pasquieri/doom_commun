/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:41:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/26 19:05:34 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int			key_press(int key, t_env *env)
{
	env->key[key] = 1;
	if (env->key[40] && !env->menu) // pour afficher le gun // touche k
	{
		if (env->inv.gun == 0)
			env->inv.gun = 1;
		else
			env->inv.gun = 0;
		//	env->key[40] = 0; //pour ne pas boucler ds key_apply pas necessaire ici
	}                     // jusque la !
	if (env->key[37] && env->inv.gun == 1 && !env->menu) // pour tirer un coup de feu : key l
	{
		print_gun(env, 3);
		mlx_put_image_to_window(env->mlx,env->win,env->m[0].img, 0,0);
		mlx_put_image_to_window(env->mlx,env->win,env->m[1].img, 960,20);
		//	env->key[37] = 0;
	}

	int	i;
	if (env->key[12])
	{
		printf("nb grid : %d, win : %d, column : %d, banana : %d, monkey : %d, door : %d\n", env->nb_sp[0], env->nb_sp[1], env->nb_sp[2], env->nb_sp[3], env->nb_sp[4], env->nb_sp[5]);
		printf("door = env->spr[5] : nb : %d, val : %d\n",env->spr[5].nb, env->spr[5].val);
		i = -1;
		while (++i < env->spr[5].nb)
		{
			printf("coord %d : i = %d, j = %d\n",i, env->spr[5].coord[i].i,env->spr[5].coord[i].j);
		}

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
	if (env->key[53])
		exit(0);
	if (env->key[49])
	{
		if (env->key[49] && !env->menu)
		{
			open_menu(env);
			env->menu = 1;
			env->key[49] = 0;
			return (0);
		}
		else if (env->key[49] && env->menu && env->map_entree == -1)
			key_invalid_menu(env);
		else if (env->key[49] && env->menu && env->map_entree != -1)
			key_valid_menu(env);
		env->key[49] = 0; // pour ne pas boucler (affiche deaffiche le menu)
	}
	if ((env->key[125] || env->key[126]) && env->menu == 1)
		ft_arrow_menu(env);
	if (!env->menu)
		trig_press(env);
	return (0);
}
