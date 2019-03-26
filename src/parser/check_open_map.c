/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:25:06 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 18:25:13 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		check_open_map(char *map, int fd, t_env *env)
{
	char	c;

	if (!(fd = open(map, O_RDONLY)))
		return (error_message(2, env));
	if (fd == -1)
		return (error_message(2, env));
	if ((read(fd, &c, 1)) != 1 || c == 0)
	{
		close(fd);
		return (error_message(2, env));
	}
	close(fd);
	if (!(fd = open(map, O_RDONLY)))
		return (error_message(2, env));
	return (fd);
}
