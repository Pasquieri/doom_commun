/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:48:19 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/28 16:58:48 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	int		init_player_value(int type, char *value, t_player *player)
{
	if (type == 0)
	{
		player->coord.x = ft_atoi(value);
		if (player->coord.x < 1 || player->coord.x > 39)
			return (-117);
	}
	else if (type == 1)
	{
		player->coord.y = ft_atoi(value);
		if (player->coord.y < 1 || player->coord.y > 39)
			return (-118);
	}
	else if (type == 2)
	{
		player->rotation = ft_atoi(value);
		if (player->rotation < 0 || player->rotation > 360)
			return (-119);
	}
	return (TRUE);
}

static	int		check_player_value_file(char *values, t_player *player)
{
	char	**tmp;
	int		i;
	char	*value;
	int		error;

	i = 0;
	if (!(tmp = ft_strsplit(values, ',')))
		return (-114);
	free(values);
	while (tmp[i] != NULL)
	{
		if (!(value = ft_strtrim(tmp[i])))
			return (err_free_dbl(tmp, ft_arr_len(tmp), -115));
		if (!str_is_digit(value))
			return (err_free_dbl(tmp, ft_arr_len(tmp), err_free(value, -116)));
		if ((error = init_player_value(i, value, player)) != TRUE)
			return (err_free_dbl(tmp, ft_arr_len(tmp), err_free(value, error)));
		free(value);
		i++;
	}
	free_double_tab(tmp);
	if (i != 3)
		return (-120);
	return (TRUE);
}

int				check_player_file(char *line, t_player *player)
{
	int		i;
	int		j;
	char	*values;
	int		error;

	i = ft_strlen("player(");
	j = 0;
	values = NULL;
	if (ft_strncmp(line, "player(", i) != 0)
		return (err_free(line, -111));
	if (line[ft_strlen(line) - 1] != ')')
		return (err_free(line, -112));
	if (!(values = (char *)malloc(sizeof(char) * ((ft_strlen(line) - i) + 1))))
		return (err_free(line, -113));
	while (line[i] != ')' && line[i] != '\0')
		values[j++] = line[i++];
	values[j] = '\0';
	free(line);
	if ((error = check_player_value_file(values, player)) != TRUE)
		return (error);
	return (TRUE);
}
