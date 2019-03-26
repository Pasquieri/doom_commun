/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/03/26 18:07:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	affichage_sol(double h_percue, t_env *env)
{
	double lim;
	lim = (env->h_regard - (h_percue / 2));
	//printf("lim sol:%f", lim)
}
