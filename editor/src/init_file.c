/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:46:03 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:52:58 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

int	init_file(char *ar_file, t_editor *editor)
{
	int error;

	error = 0;
	if ((editor->file.fd_write = open(ar_file, O_WRONLY)) <= 0)
		return (-100);
	if ((editor->file.fd = open(ar_file, O_RDONLY)) <= 0)
		return (-101);
	if ((error = read_player(editor->file.fd, &editor->player)) != TRUE)
		return (error);
	if ((error = read_music(editor->file.fd, &editor->music)) != TRUE)
		return (error);
	if ((error = read_map(&editor->file, editor->player)) != TRUE)
		return (error);
	return (TRUE);
}
