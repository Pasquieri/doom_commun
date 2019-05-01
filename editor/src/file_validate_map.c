/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:44:19 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:52:30 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	int		check_player_on_map(t_player player, int y, int x)
{
	if (player.coord.x != x || player.coord.y != y)
		return (FALSE);
	return (TRUE);
}

static	int		check_value(int value)
{
	if ((value < 0 || value > 14) && value != 16)
		return (FALSE);
	return (TRUE);
}

int				check_border(int value, int y, int x)
{
	if ((x == 0 || x == 39) && value != 1)
		return (FALSE);
	if ((y == 0 || y == 39) && value != 1)
		return (FALSE);
	return (TRUE);
}

static	int		check_map_line_file(char **map_file_line, int index_line,
	t_player player, int *begin)
{
	int i;
	int value;
	int error;

	error = 0;
	value = 0;
	i = 0;
	while (map_file_line[i] != NULL)
	{
		if (!str_is_digit(map_file_line[i]))
			return (-129);
		value = ft_atoi(map_file_line[i]);
		if (!check_value(value) || !check_border(value, index_line, i))
			return (-130);
		if (value == 8)
		{
			if (!(check_player_on_map(player, index_line, i)))
				return (-131);
			*begin = *begin + 1;
		}
		i++;
	}
	if (i != 40)
		return (-132);
	return (TRUE);
}

int				check_map_file(char **map_file, t_player player)
{
	int		i;
	char	**tmp;
	int		begin;
	int		error;

	begin = 0;
	i = 0;
	while (map_file[i] != NULL)
	{
		if (!(tmp = ft_strsplit(map_file[i], ' ')))
			return (err_free_dbl(map_file, ft_arr_len(map_file), -128));
		if ((error = check_map_line_file(tmp, i, player, &begin)) != TRUE)
		{
			return (err_free_dbl(map_file, ft_arr_len(map_file),
			err_free_dbl(tmp, ft_arr_len(tmp), error)));
		}
		free_double_tab(tmp);
		i++;
	}
	if (begin > 1)
		return (err_free_dbl(map_file, ft_arr_len(map_file), -133));
	if (i != 40)
		return (err_free_dbl(map_file, ft_arr_len(map_file), -134));
	return (TRUE);
}
