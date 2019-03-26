/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_valeur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:57:35 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/26 18:17:37 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		verif_valeur(char *str, t_env *env)
{
	int		valeur;

	valeur = ft_atoi(str);
	env->musique = valeur;
	return (valeur);
}
