/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_valeur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:50:05 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 19:13:07 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		verif_valeur(char *str, t_env *env)
{
	int		valeur;

	valeur = ft_atoi(str);
	if (valeur == 0)
	{
		free(str);
		return (error_message(10, env));
	}
	if (valeur > 150)
	{
		free(str);
		return (error_message(9, env));
	}
	return (valeur);
}
