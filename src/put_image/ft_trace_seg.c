/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_seg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:31 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/30 21:38:27 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static int	cas_1(t_env *env, t_coord coord1, t_coord coord2)
{
	int		dx;
	int		e;
	int		dy;

	e = fabs(coord2.x - coord1.x);
	dx = 2 * e;
	dy = 2 * fabs(coord2.y - coord1.y);
	while (coord1.x <= coord2.x)
	{
		put_pxl_img(env, coord1.x, coord1.y, 0);
		coord1.x++;
		e -= dy;
		while (e < 0)
		{
			if (coord1.y < coord2.y)
				coord1.y++;
			else if (coord1.y > coord2.y)
				coord1.y--;
			put_pxl_img(env, coord1.x, coord1.y, 0);
			e += dx;
		}
	}
	return (0);
}

static int	cas_2(t_env *env, t_coord coord1, t_coord coord2)
{
	int		dx;
	int		e;
	int		dy;

	e = fabs(coord2.x - coord1.x);
	dx = 2 * e;
	dy = 2 * fabs(coord2.y - coord1.y);
	while (coord1.x >= coord2.x)
	{
		put_pxl_img(env, coord1.x, coord1.y, 0);
		coord1.x--;
		e -= dy;
		while (e < 0)
		{
			if (coord1.y < coord2.y)
				coord1.y++;
			else if (coord1.y > coord2.y)
				coord1.y--;
			put_pxl_img(env, coord1.x, coord1.y, 0);
			e += dx;
		}
	}
	return (0);
}

static int	cas_3(t_env *env, t_coord coord1, t_coord coord2)
{
	if (coord1.y <= coord2.y)
	{
		while (coord1.y <= coord2.y)
		{
			put_pxl_img(env, coord1.x, coord1.y, 0);
			coord1.y++;
		}
	}
	else
	{
		while (coord1.y >= coord2.y)
		{
			put_pxl_img(env, coord1.x, coord1.y, 0);
			coord1.y--;
		}
	}
	return (0);
}

int			ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2)
{
	if (coord1.x > coord2.x)
		cas_2(env, coord1, coord2);
	else if (coord1.x < coord2.x)
		cas_1(env, coord1, coord2);
	else if (coord1.x == coord2.x)
		cas_3(env, coord1, coord2);
	return (0);
}
