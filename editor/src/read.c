/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:38:06 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:33 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

int	read_player(int fd, t_player *player)
{
	int		ret;
	char	*line;
	int		error;

	line = NULL;
	ret = get_next_line(fd, &line);
	if (ret == -1 || !line)
		return (-110);
	if ((error = check_player_file(line, player)) != TRUE)
		return (error);
	return (TRUE);
}

int	read_music(int fd, int *music)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(fd, &line);
	if (ret == -1 || !line)
		return (-121);
	if (!str_is_digit(line))
		return (err_free(line, -122));
	*music = ft_atoi(line);
	if (*music <= 0 || *music > 7)
		return (err_free(line, -123));
	free(line);
	return (TRUE);
}

int	read_map(t_file *file, t_player player)
{
	int		ret;
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	line = NULL;
	if (!(tmp = ft_strnew(0)))
		return (-124);
	while ((ret = get_next_line(file->fd, &line)))
	{
		if (!(tmp = ft_strjoin_free(tmp, line, 2))
				|| !(tmp = ft_strjoin_free(tmp, "\n", 1)))
			return (-125);
		i++;
	}
	if (i != 40 || ret == -1 || ft_strlen(tmp) == 0)
		return (err_free(tmp, -126));
	if (!(file->file = ft_strsplit(tmp, '\n')))
		return (err_free(tmp, -127));
	free(tmp);
	if ((ret = check_map_file(file->file, player)) != TRUE)
		return (ret);
	return (TRUE);
}
