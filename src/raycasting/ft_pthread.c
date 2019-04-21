/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:48:26 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/21 19:43:58 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	ft_pthread(t_env *env)
{
	t_env		tab[10];
	pthread_t	t[10];
	int			i;

	i = 0;
	while (i < 10)
	{
		tab[i] = *env;
		tab[i].current_thread = i;
		tab[i].img_x = i * W_WIDTH / 10;
		tab[i].nb_colonne = (i + 1) * W_WIDTH / 10;
		tab[i].angle_thread = 30 - i * 6;
		i++;
	}
	i = -1;
	while (++i < 10)
		pthread_create(&t[i], NULL, affichage_mur, &tab[i]);
	i = -1;
	while (++i < 10)
		pthread_join(t[i], NULL);
}
