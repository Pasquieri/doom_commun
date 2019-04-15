/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:57:03 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/15 16:18:02 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int	red_cross(int key)
{
	(void)key;
	system("/usr/bin/killall afplay 2&>/dev/null >/dev/null");
	exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env		env;

	if (win_init(&env) == -1)
		return (red_cross(0));
	env.map_entree = -1;
	env.menu = 0;
	init_rgb(&env);
	if (pars_init(ac, av, &env) == 0)
		exec_calcul(&env, 0, 1);
	env.menu = 1;
	env.menu_select = 1;
	open_menu(&env);
//	system("/usr/bin/afplay -q 1 src/song/Elevator.mp3&");
	mlx_hook(env.win, 6, 1L << 13, motion_notify, &env);
	mlx_hook(env.win, 2, 0, key_press, &env);
	mlx_hook(env.win, 3, 0, key_release, &env);
	mlx_loop_hook(env.mlx, key_apply, &env);
	mlx_hook(env.win, 17, 3, red_cross, &env);
	mlx_loop(env.mlx);
	return (0);
}
