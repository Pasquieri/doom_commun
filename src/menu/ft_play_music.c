/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_music.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:09:15 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:41:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	ft_play_music(int i, char c)
{
	system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
	if (i == 1)
		system("/usr/bin/afplay -q 1 src/song/musique1.mp3&");
	else if (i == 2)
		system("/usr/bin/afplay -q 1 src/song/musique2.mp3&");
	else if (i == 3)
		system("/usr/bin/afplay -q 1 src/song/musique3.mp3&");
	else if (i == 4)
		system("/usr/bin/afplay -q 1 src/song/musique4.mp3&");
	else if (i == 5)
		system("/usr/bin/afplay -q 1 src/song/musique5.mp3&");
	else if (i == 6)
		system("/usr/bin/afplay -q 1 src/song/musique6.mp3&");
	else if (i == 7)
		system("/usr/bin/afplay -q 1 src/song/musique7.mp3&");
	else if (c == 's')
		system("/usr/bin/afplay -q 1 src/song/story.mp3&");
}
