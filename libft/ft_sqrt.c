/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:10:47 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/21 21:12:32 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double nb)
{
	double racine;

	racine = 1;
	while (racine * racine < nb)
		racine++;
	if (racine * racine == nb)
		return (racine);
	else
		return (0);
}
