/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:48:26 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/10 03:44:26 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	ft_pthread(t_env *env)
{
	t_env		tab[10];
	pthread_t	t[10];
	int			i;


	// thread 1 //
	i = 0;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 0;
	tab[i].nb_colonne = W_WIDTH / 10;
	tab[i].angle_thread = 30;

	// thread 2 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = W_WIDTH / 10;
	tab[i].nb_colonne = 2 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 6;

	// thread 3 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 2 * W_WIDTH / 10;
	tab[i].nb_colonne = 3 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 2 * 6;

	// thread 4 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 3 * W_WIDTH / 10;
	tab[i].nb_colonne = 4 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 3 * 6;

	// thread 5 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 4 * W_WIDTH / 10;
	tab[i].nb_colonne =  5 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 4 * 6;

	// thread 6 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 5 * W_WIDTH / 10;
	tab[i].nb_colonne = 6 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 5 * 6;

	// thread 7 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 6 * W_WIDTH / 10;
	tab[i].nb_colonne = 7 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 6 * 6;

	// thread 8 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 7 * W_WIDTH / 10;
	tab[i].nb_colonne = 8 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 7 * 6;

	// thread 9 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 8 * W_WIDTH / 10;
	tab[i].nb_colonne = 9 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 8 * 6;

	// thread 10 //
	i++;
	tab[i] = *env;
	tab[i].current_thread = i;
	tab[i].img_x = 9 * W_WIDTH / 10;
	tab[i].nb_colonne = 10 * W_WIDTH / 10;
	tab[i].angle_thread = 30 - 9 * 6;

	pthread_create(&t[0], NULL, affichage_mur, &tab[0]);
	pthread_create(&t[1], NULL, affichage_mur, &tab[1]);
	pthread_create(&t[2], NULL, affichage_mur, &tab[2]);
	pthread_create(&t[3], NULL, affichage_mur, &tab[3]);
	pthread_create(&t[4], NULL, affichage_mur, &tab[4]);
	pthread_create(&t[5], NULL, affichage_mur, &tab[5]);
	pthread_create(&t[6], NULL, affichage_mur, &tab[6]);
	pthread_create(&t[7], NULL, affichage_mur, &tab[7]);
	pthread_create(&t[8], NULL, affichage_mur, &tab[8]);
	pthread_create(&t[9], NULL, affichage_mur, &tab[9]);
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	pthread_join(t[2], NULL);
	pthread_join(t[3], NULL);
	pthread_join(t[4], NULL);
	pthread_join(t[5], NULL);
	pthread_join(t[6], NULL);
	pthread_join(t[7], NULL);
	pthread_join(t[8], NULL);
	pthread_join(t[9], NULL);


//i = 0;
//	i++;
//	pthread_join(t[i], NULL);

}
