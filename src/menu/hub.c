/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:12:49 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/06 09:26:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/wolf3d.h"

static int		ft_size(int nb)
{
	int			i;

	i = 0;
	while (nb > 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int		size_int(int nb)
{
	int     size;

	size = 1;
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		size = size * 10;
	}
	return (size);
}

static char		*char_int(int nb)
{
	int			size;
	char		*tab;
	int			i;

	i = 0;
	size = size_int(nb);
	tab = NULL;
	tab = (char *)malloc(sizeof(char) * (ft_size(nb) + 1));
	if (tab == NULL)
		return ("");
	while (size)
	{
		tab[i] = ((nb / size) + '0');
		nb = nb % size;
		size = size / 10;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char		*chaine_nb(char *str, int nb)
{
	char	*res;
	char	*str2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = NULL;
	res = (char *)malloc(sizeof(char) * (ft_strlen(char_int(nb)) + ft_strlen(str) + 1));
	if (res == NULL)
		return ("");
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	str2 = char_int(nb);
	while (str2[j] != '\0')
	{
		res[i] = str2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

void			hub_init(t_env *env)
{
	env->H_mlx = mlx_new_image(env->mlx, 400, 75);
	env->H_end_mlx = mlx_new_image(env->mlx, (W_WIDTH - 400), (W_HEIGHT - 660));
	env->H_init = 1;
	env->H_life = 100;
//	env->H_monkey = 0;
	env->H_monkey = env->sp[4].nb; // nombre de singe
	env->H_ammo = 30;
	env->H_end = 0;
}

void			print_hub(t_env *env)
{
	if (env->H_init == 0)
		hub_init(env);
	//env->H_end = 1;
	//env->H_life = 0;
	if (env->H_end <= 0)
	{
		//mlx_put_image_to_window(env->mlx, env->win, env->H_mlx, 10, 10);
		mlx_string_put(env->mlx, env->win, 30, 740, 0x2B502B,
				chaine_nb("Life : ", env->H_life));
		mlx_string_put(env->mlx, env->win, 30, 780, 0x2B502B,
				chaine_nb("Monkeys : ", env->H_monkey));
		mlx_string_put(env->mlx, env->win, 30, 820, 0x2B502B,
				chaine_nb("Ammo : ", env->H_ammo));
	}
	else
	{
		mlx_put_image_to_window(env->mlx, env->win, env->H_end_mlx, 200, 400);
		if (env->H_life <= 0)
			mlx_string_put(env->mlx, env->win, 510, 450, 0xD51515,
					"Vous avez perdu :(");
		else
			mlx_string_put(env->mlx, env->win, 510, 450, 0x32901D,
					"Vous avez gagne :)");
		mlx_string_put(env->mlx, env->win, 400, 500, 0x1A79D3,
					"Appuyer sur [espace] pour revenir au menu");
		mlx_string_put(env->mlx, env->win, 410, 530, 0x1A79D3,
					"Appuyer sur [esc] pour quitter le jeu");

	}
}

// donc pour afficher le message de fin il faut que env->H_end = 1
// pour le message de victoire le perso doit finir avec de la vie
// pour le message de defaite le perso doit finir sans vie
