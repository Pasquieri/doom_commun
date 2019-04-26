/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:41:46 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/25 16:04:40 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int			key_press(int key, t_env *env) // il faut reduire la vitesse de deplacement pendant le saut
{
	env->key[key] = 1;
	if (env->key[4] == 1)
		env->h_help = env->h_help == 0 ? 1 : 0;
	if (env->key[53])
	{
		system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
		exit(0);
	}
	if (env->key[16] && !env->menu)
		env->h_story = 0;
	if (env->key[37] && env->gun == 1 && !env->menu) // coup de feu : key l
	{
		print_gun(env, 3);
		mlx_put_image_to_window(env->mlx,env->win,env->m[0].img, 0,0);
		mlx_put_image_to_window(env->mlx,env->win,env->m[1].img, 960,20);
	}
	if (env->key[29] && !env->menu)
		env->lum_int = 370;
	if (env->key[25] && !env->menu)
		env->lum_int = 25;
	if (env->key[257] && !env->menu)
		env->vitesse = SPEED * 2;
	if (env->key[14] && !env->menu)
		deal_door(env);
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
	if (env->key[49] && !env->menu  && env->jump == 0)
	{
	//	if (env->jump >= 0)
		if (env->key[13])
		{
			env->vitesse = env->vitesse / 3;
			env->jump_move = 13;
		}
		else if (env->key[1])
		{
			env->vitesse = env->vitesse / 6;
			env->jump_move = 1;
		}
		else if (env->key[0])
		{
			env->vitesse = env->vitesse / 6;
			env->jump_move = 0;
		}
		else if (env->key[2])
		{
			env->vitesse = env->vitesse / 6;
			env->jump_move = 2;
		}
		else
			env->vitesse = 0;
		env->jump = 1;
	}
	if (env->key[8] && !env->menu)
	{
		if (env->key[13])
			env->jump_move = 13;
		else if (env->key[1])
			env->jump_move = 1;
		else if (env->key[0])
			env->jump_move = 0;
		else if (env->key[2])
			env->jump_move = 2;
		if (env->crouch == 1)
			env->crouch = 0;
		else
			env->crouch = 1;
	}
	if (env->key[12]) //wtf ????
	{
		;
	}
	return (0);
}

int			key_release(int key, t_env *env)
{
	env->key[key] = 0;
	if (key == 257 && !env->menu)
		env->vitesse = SPEED;
	if (key == 8 && !env->menu)
	{
		env->h_jump = 0;
		env->vitesse = SPEED;
	}
	if (key == 36 || key == 76)
	{
		if ((key == 36 || key == 76) && !env->menu)
		{
			open_menu(env);
			env->menu = 1;
			return (0);
		}
		else if ((key == 36 || key == 76) && env->menu && env->map_entree == -1)
			key_invalid_menu(env);
		else if ((key == 36 || key == 76) && env->menu && env->map_entree != -1)
			key_valid_menu(env);
	}
	if ((key == 18 || key == 19) && !env->menu)
	{
		if (env->skybox != 22 && key == 18)
			env->skybox = 22;
		else if (env->skybox != 24 && key == 19)
			env->skybox = 24;
		else
			env->skybox = 0;
	}
	if (key == 40 && !env->menu) // pour afficher le gun : key k
	{
		if (env->gun == 0)
			env->gun = 1;
		else
			env->gun = 0;
	}
	return (0);
}

static void	ft_arrow_menu(t_env *env)
{
	arrow_menu(env);
	env->key[125] = 0;
	env->key[126] = 0;
}

void	ft_jump(t_env *env)
{
	int jump_height = 100;

	if (env->jump > 0) // si saut en mode "monter"
	{
		if (env->jump >= 1) // on monte le saut de 1
		{
			env->jump = 0;
			if (env->h_jump + jump_height < 15 * jump_height) // si monter est possible
			{
				if (env->jump_move != -1)
				{
					if (env->jump_move == 1 || env->jump_move == 13)
						depla_vertical(env, env->jump_move);
					else if (env->jump_move == 0 || env->jump_move == 2)
						depla_horizontal(env, env->jump_move);
				}
				env->h_jump += jump_height;
				//env->h_regard += jump_height; // alors on monte
			}
			else
				env->jump = -2; // alors on dessend
		}
		env->jump = env->jump + 1;
	}
	if (env->jump < 0) // si saut en mode "dessendre"
	{
		if (env->jump <= -1) // on descend le saut de 1
		{
			env->jump = 0;
			if (env->h_jump - jump_height > 0) // si descendre est possible
			{
				if (env->jump_move != -1)
				{
					if (env->jump_move == 1 || env->jump_move == 13)
						depla_vertical(env, env->jump_move);
					else if (env->jump_move == 0 || env->jump_move == 2)
						depla_horizontal(env, env->jump_move);
				}
				env->h_jump -= jump_height;
				//env->h_regard -= jump_height; // alors on descend
			}
			else // si on peut pas dessendre
			{
				env->jump = 1;
				env->h_jump = 0;
				env->vitesse = SPEED;
				env->jump_move = -1;
				//env->h_regard = W_HEIGHT / 2; // on reinitialise
			}
		}
		env->jump = env->jump - 1;
	}
}

void	ft_crouch(t_env *env)
{
	int h_crouch_height = 100;
	env->vitesse = SPEED / 3;
	if (env->crouch >= 1) // si saut en mode "monter"
	{
		if (env->crouch >= 1) // on monte le saut de 1
		{
			printf("h_jump: %.1f\n",env->h_jump);
			printf("crouch: %.1f\n",env->crouch);
			if (env->h_jump - h_crouch_height > (env->d_ecran * env->h_mur) / -2)  // si monter est possible
			{
			/*	if (env->jump_move != -1)
				{
					if (env->jump_move == 1 || env->jump_move == 13)
						depla_vertical(env, env->jump_move);
					else if (env->jump_move == 0 || env->jump_move == 2)
						depla_horizontal(env, env->jump_move);
				}*/
				env->h_jump -= h_crouch_height;
				//env->h_regard += jump_height; // alors on monte
			}
			else
				env->crouch = 0; // alors on dessend
		}
		env->crouch = env->crouch + 1;
	}
	if (env->crouch <= 0) // si saut en mode "dessendre"
	{
		if (env->crouch <= 0) // on descend le saut de 1
		{

			if (env->h_jump + h_crouch_height < 0)// si descendre est possible
			{/*
				if (env->jump_move != -1)
				{
					if (env->jump_move == 1 || env->jump_move == 13)
						depla_vertical(env, env->jump_move);
					else if (env->jump_move == 0 || env->jump_move == 2)
						depla_horizontal(env, env->jump_move);
				}*/
				env->h_jump += h_crouch_height;
				//env->h_regard -= jump_height; // alors on descend
			}
			else // si on peut pas dessendre
			{
				env->crouch = -1;
				env->h_jump = 0;
				env->vitesse = SPEED;
				env->jump_move = -1;
				env->vitesse = SPEED;
				//env->h_regard = W_HEIGHT / 2; // on reinitialise
			}
		}
		env->crouch = env->crouch - 1;
	}
}

int			key_apply(t_env *env)
{
	if (env->jump != 0)
		ft_jump(env);
	else if (env->crouch == 0 || env->crouch == 1)
		ft_crouch(env);
	ft_monkey(env);
	env->time += 1;
	if (env->time > 10000)
		env->time = 1;
	if ((env->key[125] || env->key[126]) && env->menu == 1)
		ft_arrow_menu(env);
	if (!env->menu)
		trig_press(env);
	return (0);
}

