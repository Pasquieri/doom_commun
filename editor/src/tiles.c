/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:37:50 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/28 22:37:51 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

void	reset_tiles(t_tile **tiles)
{
	t_point	point;
	int		type;

	type = 0;
	point.y = 0;
	while (point.y < GRID_SIZE)
	{
		point.x = 0;
		while (point.x < GRID_SIZE)
		{
			type = init_type_tile(point.x, point.y);
			tiles[point.y][point.x].type = type;
			point.x++;
		}
		point.y++;
	}
}

int		file_to_tiles(char **file, t_tile **tiles)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while (i < GRID_SIZE)
	{
		j = 0;
		if (!(tmp = ft_strsplit(file[i], ' ')))
			return (FALSE);
		while (j < GRID_SIZE)
		{
			tiles[i][j].type = ft_atoi(tmp[j]);
			j++;
		}
		i++;
		free_double_tab(tmp);
	}
	return (TRUE);
}
