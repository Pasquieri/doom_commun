/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:41:37 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/05 14:31:45 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		pars_init(int argc, char **argv, t_env *env)
{
	int		fd;

	fd = -1;
	env->detail = 0;
	if (argc != 2)
	{
		if (argc == 3)
		{
			if (ft_atoi(argv[2]) > 0)
				env->detail = 1;
		}
		else
			return (error_message(1, env));
	}
	fd = check_open_map(argv[1], fd, env);
	if (fd == -1)
		return (-1);
	if (check_file(fd, env) == -1)
		return (-1);
	env->H_init = 0;
	env->map_entree = 0;
	return (0);
}

int		re_pars(char *str, t_env *env)
{
	int	fd;
	int	j;

//	env->map_entree = -1;
	fd = -1;
	env->detail = 0;
	fd = check_open_map(str, fd, env);
	if (fd == -1)
		return (-1);
	j = 0;
	while (j < env->y && env->map_entree == 0)
	{
	//	printf("free\n");
		free(env->tab[j]);
		j++;
	}
	if (env->map_entree == 0)
		free(env->tab);
	//printf("repars ok\n");
	if (check_file(fd, env) == -1)
		return (-1);
	env->H_init = 0;
	env->map_entree = 0;
	return (0);
}
