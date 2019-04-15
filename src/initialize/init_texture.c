/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2011/03/01 20:15:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/15 19:57:30 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int	verif_sprt(t_env *env, int i, int k)
{
	if (i < NB_SP)
	{
		if (env->sp_t[i].img == NULL)
			return (verif_sprt(env, ++i, ++k));
		else if (env->sp_t[i].img_str == NULL && env->sp_t[i].img != NULL)
		{
			env->sp_t[i].img_str = mlx_get_data_addr(env->sp_t[i].img, &env->sp_t[i].bpp, &env->sp_t[i].s_l, &env->sp_t[i].end);
			return (verif_sprt(env, ++i, k));
		}
		else
			return (verif_sprt(env, ++i, k));
	}
	return (k);
}

static int	verif_text(t_env *env, int i, int k)
{
	if (i < 25)
	{
		if (env->text[i].img == NULL)
			return (verif_text(env, ++i, ++k));
		else if (env->text[i].img_str == NULL && env->text[i].img != NULL)
		{
			env->text[i].img_str = mlx_get_data_addr(env->text[i].img, &env->text[i].bpp, &env->text[i].s_l, &env->text[i].end);
			return (verif_text(env, ++i, k));
		}
		else
			return (verif_text(env, ++i, k));
	}
	return (k);
}

static void	init_texture_wall(t_env *env)
{
	env->text[1].img = mlx_xpm_file_to_image(env->mlx,
			"textures/1-mur_gray-200px.XPM", &env->text[1].width,
			&env->text[1].height);
	//env->text[1].img_str = mlx_get_data_addr(env->text[1].img,
	//		&env->text[1].bpp, &env->text[1].s_l, &env->text[1].end);
	env->text[2].img = mlx_xpm_file_to_image(env->mlx,
			"textures/2-wall_white-200px.XPM", &env->text[2].width,
			&env->text[2].height);
	//env->text[2].img_str = mlx_get_data_addr(env->text[2].img,
	//		&env->text[2].bpp, &env->text[2].s_l, &env->text[2].end);
	env->text[3].img = mlx_xpm_file_to_image(env->mlx,
			"textures/3-wall_bleu-200px.XPM", &env->text[3].width,
			&env->text[3].height);
	//env->text[3].img_str = mlx_get_data_addr(env->text[3].img,
	//		&env->text[3].bpp, &env->text[3].s_l, &env->text[3].end);
	env->text[4].img = mlx_xpm_file_to_image(env->mlx,
			"textures/1-mur_gray-200px.XPM", &env->text[4].width, &env->text[4].height);
	//env->text[4].img_str = mlx_get_data_addr(env->text[4].img,
	//		&env->text[4].bpp, &env->text[4].s_l, &env->text[4].end);
	env->text[5].img = mlx_xpm_file_to_image(env->mlx,
			"textures/2-wall_white-200px.XPM", &env->text[5].width, &env->text[5].height);
	//env->text[5].img_str = mlx_get_data_addr(env->text[5].img,
	//		&env->text[5].bpp, &env->text[5].s_l, &env->text[5].end);
}

int		init_texture(t_env *env)
{
	int		v_text;
	int		v_sprt;

	env->text[0].img = mlx_xpm_file_to_image(env->mlx,
			"textures/0-floor_labo-200px.XPM", &env->text[0].width,
			&env->text[0].height);
	//env->text[0].img_str = mlx_get_data_addr(env->text[0].img,
	//		&env->text[0].bpp, &env->text[0].s_l, &env->text[0].end);
	init_texture_wall(env);
	env->text[6].img = mlx_xpm_file_to_image(env->mlx,
			"textures/3-wall_bleu-200px.XPM", &env->text[6].width, &env->text[6].height);
	//env->text[6].img_str = mlx_get_data_addr(env->text[6].img,
	//		&env->text[6].bpp, &env->text[6].s_l, &env->text[6].end);
	env->text[7].img = mlx_xpm_file_to_image(env->mlx,
			"textures/7-door.XPM", &env->text[7].width, &env->text[7].height);
	//env->text[7].img_str = mlx_get_data_addr(env->text[7].img,
	//		&env->text[7].bpp, &env->text[7].s_l, &env->text[7].end);
	env->text[8].img = mlx_xpm_file_to_image(env->mlx,
			"textures/door2.XPM", &env->text[8].width, &env->text[8].height);
	//env->text[8].img_str = mlx_get_data_addr(env->text[8].img,
	//		&env->text[8].bpp, &env->text[8].s_l, &env->text[8].end);
	env->text[21].img = mlx_xpm_file_to_image(env->mlx,
			"textures/21-plafond_white.XPM",
			&env->text[21].width, &env->text[21].height);
	//env->text[21].img_str = mlx_get_data_addr(env->text[21].img,
	//		&env->text[21].bpp, &env->text[21].s_l, &env->text[21].end);
	env->text[22].img = mlx_xpm_file_to_image(env->mlx,
			"textures/space.XPM", &env->text[22].width, &env->text[22].height);
	//env->text[22].img_str = mlx_get_data_addr(env->text[22].img,
	//		&env->text[22].bpp, &env->text[22].s_l, &env->text[22].end);
	env->text[24].img = mlx_xpm_file_to_image(env->mlx,
			"textures/space2.XPM", &env->text[24].width, &env->text[24].height);
	//env->text[24].img_str = mlx_get_data_addr(env->text[24].img,
	//		&env->text[24].bpp, &env->text[24].s_l, &env->text[24].end);
	env->text[23].img = mlx_xpm_file_to_image(env->mlx,
			"textures/savant_face.xpm", // mettre tete perso
			&env->text[23].width, &env->text[23].height);
	//env->text[23].img_str = mlx_get_data_addr(env->text[23].img,
	//		&env->text[23].bpp, &env->text[23].s_l, &env->text[23].end);

	init_sprite(env);

	v_text = verif_text(env, 0, 0); //nb de text pas get_data
	v_sprt = verif_sprt(env, 0, 0); //nb de spri pas get_data

	if (v_text != 11 || v_sprt != 0)
		return (-1);
	return (0);
}
