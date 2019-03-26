/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:13:17 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/21 21:30:41 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_power(long nb, int power)
{
	long long	res;

	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
