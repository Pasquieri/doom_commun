/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:05:47 by cyfelbac          #+#    #+#             */
/*   Updated: 2018/02/07 13:10:56 by gchojnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int		check_endline(int ret, char *str)
{
	int i;

	i = 0;
	if (ret == 0)
		return (0);
	if (ret > 0)
	{
		while (i < ret)
		{
			if (str[i] == '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

static int		len_line(char *s, int *flag)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		*flag = 1;
	return (i);
}

static int		fill_line(char **s, char **line)
{
	char	*tmp;
	int		flag;

	flag = 0;
	tmp = *s;
	if (!(*line = ft_strsub(*s, 0, len_line(*s, &flag))))
		return (-1);
	if (flag == 1)
	{
		if (!(*s = ft_strdup(ft_strchr(*s, '\n') + 1)))
			return (-1);
	}
	else
		*s = NULL;
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	ret = -3;
	if (!s)
		if (!(s = ft_strnew(1)))
			return (-1);
	while (check_endline(ret, buff))
	{
		ret = read(fd, &buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = s;
		if (!(s = ft_strjoin(s, buff)))
			return (-1);
		free(tmp);
	}
	if (!ft_strlen(s))
		return (0);
	if (!(fill_line(&s, line)))
		return (-1);
	return (1);
}
