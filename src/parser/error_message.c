/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:26:48 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/15 15:49:21 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	extra_20(int num)
{
	if (num == 10)
		ft_putstr("La musique indiquée est invalide");
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
	else if (num == 16)
		ft_putstr("Le nombre de ligne est invalide");
	else if (num == 17)
		ft_putstr("Texture(s) introuvable(s)");
}

static void	extra_10(int num)
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
	else if (num == 6)
		ft_putstr("La premiere ligne doit etre (player : (X,X);)");
	else if (num == 7)
		ft_putstr("Un des caracteres de la map est incompatible");
	else if (num == 8)
		ft_putstr("le nb de case n'est pas toujours de 40");
	else if (num == 9)
		ft_putstr("Le x et de y indique est trop elevee (doit etre == 40)");
}

int			error_message(int num, t_env *env)
{
	ft_putstr("Erreur : ");
	if (env->detail > 0)
	{
		extra_10(num);
		extra_20(num);
	}
	else if (env->detail == 0)
		ft_putstr("map invalide");
	ft_putchar('\n');
	return (-1);
}
