/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:27:56 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/01 15:37:57 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	error_message_extra(int num)
{
	if (num == 10)
		ft_putstr("Le nombre indique est egal a zero ou n'existe pas");
	else if (num == 11)
		ft_putstr("La map n'a pas de case vide");
	else if (num == 12)
		ft_putstr("La map n'est pas cadre par des murs");
	else if (num == 13)
		ft_putstr("La map est vide");
	else if (num == 14)
		ft_putstr("Les coordonnees du player ne sont pas valides");
	else if (num == 15)
		ft_putstr("Le joueur est place dans un mur");
	else if (num == 6)
		ft_putstr("La premiere ligne doit etre (player : (X,X);)");
	else if (num == 7)
		ft_putstr("Un des caracteres de la map est incompatible");
	else if (num == 8)
		ft_putstr("Nb de caracteres different par lignes");
	else if (num == 9)
		ft_putstr("Le x et de y indique est trop elevee (10000 max)");
}

int			error_message(int num, t_env *env)
{
	ft_putstr("Erreur : ");
	if (env->detail > 0)
	{
		if (num == 1)
			ft_putstr("Un parametre est attendu");
		else if (num == 2)
			ft_putstr("Ouverture de la map impossible");
		else if (num == 3)
			ft_putstr("Erreur de malloc");
		else if (num == 4)
			ft_putstr("Le nombre de colonnes (y) indique est incorrect");
		else if (num == 5)
			ft_putstr("Le nombre de lignes (x) indique est incorrect");
		error_message_extra(num);
	}
	else if (env->detail == 0)
		ft_putstr("map invalide");
	ft_putchar('\n');
	return (-1);
}
