/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:52:54 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:53:17 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

static	int	print_usage(void)
{
	ft_putendl("usage: ./editor [file] || ./editor > emtpy_file");
	return (1);
}

int			main(int argc, char **argv)
{
	t_editor editor;

	editor.music = 1;
	editor.button = FALSE;
	editor.loop = FALSE;
	editor.file = (t_file){0, 0, NULL, NULL};
	editor.player = (t_player){(t_point){0, 0}, 0};
	if (argc != 2 && argc != 1)
		return (print_usage());
	if (!(init(argc, argv, &editor)))
		return (0);
	editor.file.filename = argv[1];
	print_cmd(editor.data);
	print_music(editor.data, editor.music);
	mlx_hook(editor.data.mlx_win, 17, 0, end, &editor);
	mlx_hook(editor.data.mlx_win, 4, (1L << 2), click_press, &editor);
	mlx_hook(editor.data.mlx_win, 5, (1L << 3), click_release, &editor);
	mlx_hook(editor.data.mlx_win, 6, (1L << 6), on_mouse_event, &editor);
	mlx_key_hook(editor.data.mlx_win, on_key_event, &editor);
	mlx_loop(editor.data.mlx_ptr);
	return (EXIT_SUCCESS);
}
