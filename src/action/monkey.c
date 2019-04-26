/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:49:20 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/25 15:49:22 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	attack(t_env *env, int i)
{
	/*printf("M:%.1f - %.1f\n", env->sp[4].sprite[i].cd.x, env->sp[4].sprite[i].cd.y);
	printf("J:%.1f - %.1f\n", env->perso_x, env->perso_y);
	printf("CM:(%.1f;%.1f)\n", env->sp[4].sprite[i].cd.x / env->coef, env->sp[4].sprite[i].cd.y / env->coef);
	*/if (env->sp[4].sprite[i].cd.x / env->coef != env->perso_x / env->coef && env->sp[4].sprite[i].cd.y / env->coef != env->perso_y / env->coef)
	{
		//env->tab[(int)(env->sp[4].sprite[i].cd.y / env->coef)][(int)(env->sp[4].sprite[i].cd.x / env->coef)] = 0;
		if (env->sp[4].sprite[i].cd.x / env->coef > env->perso_x / env->coef)// && 
		//	env->[env->sp[4].sprite[i].cd.x+1 / env->coef][env->sp[4].sprite[i].cd.y / env->coef])
			env->sp[4].sprite[i].cd.x -= 1;
		else
			env->sp[4].sprite[i].cd.x += 1;
		if (env->sp[4].sprite[i].cd.y / env->coef > env->perso_y / env->coef)
			env->sp[4].sprite[i].cd.y -= 1;
		else
			env->sp[4].sprite[i].cd.y += 1;
		env->tab[(int)(env->sp[4].sprite[i].cd.y / env->coef)][(int)(env->sp[4].sprite[i].cd.x / env->coef)] = 14;
	}
}

// pause sur banane

void	ft_monkey(t_env *env)
{
	int k = env->sp[4].nb;
	int i = 0;
	while (i < k)
	{
		if (env->sp[4].sprite[i].det == 1 && env->time % 10 == 0)
			attack(env, i);
		i++;
	}
}