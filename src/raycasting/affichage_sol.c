/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:28:54 by cjulliar          #+#    #+#             */
/*   Updated: 2019/03/26 10:28:57 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"
#include <stdio.h>


void	affichage_sol(double h_percue, int x, int y, t_env *env)
{

	double ac;
	double m;
	double n;
	double tmp;

	tmp = (env->h_regard) / ((y - env->h_regard) / env->d_ecran );
	while (y < W_HEIGHT)
	//while (tmp++ < 20)
	{
		printf("%d\n", y);
		
		ac = (env->h_regard) / ((y - env->h_regard) / (env->d_ecran * (env->dist / tmp)));
		if (env->angle > 0 && env-> angle <= 90)
		{
			n = sin((M_PI * env->angle) / 180) * ac;
			m = cos((M_PI * env->angle) / 180) * ac;
		}
		else if (env->angle > 90 && env-> angle <= 180)
		{
			n = sin((M_PI * env->angle) / 180) * ac;
			m = -1 * cos((M_PI * env->angle) / 180) * ac;
		}
		else if (env->angle > 180 && env-> angle <= 270)
		{
			n = -1 * sin((M_PI * env->angle) / 180) * ac;
			m = -1 * cos((M_PI * env->angle) / 180) * ac;
		}
		else
		{
			n = -1 * sin((M_PI * env->angle) / 180) * ac;
			m = cos((M_PI * env->angle) / 180) * ac;
		}
		int a;
		int b;
		a = env->perso_x / env->coef;
		b = env->perso_y / env->coef;
		printf("perso (%d,%d) : sol (%f, %f)\n", a, b, a-m, b-n);
		printf("tmp : %.1f  distance: %f - dist %f\n", tmp, ac, env->dist);
		printf("angle: %.1f m n (%.1f ; %.1f)\n\n", env->angle, m, n);
		y++;
	}
	x = 0;
	h_percue = 0;
/*	double	distEcran_plafond_mur;
	double	distEcran_sol_mur;
	double	lim_sol;
//	double		y;

	distEcran_plafond_mur  = env->h_regard - (h_percue / 2);
	distEcran_sol_mur = W_HEIGHT - h_percue - distEcran_plafond_mur;
	//printf("P + M + S: %.1f %.1f %.1f = %.1f \n", distEcran_plafond_mur, h_percue, distEcran_sol_mur, dist_plafond_mur + h_percue + dist_sol_mur);
	lim_sol = W_HEIGHT - distEcran_sol_mur ;

	printf("orientation: %.1f\n", env->angle);
	printf("d_camera - ecran: %.1f\n",env->d_ecran);
//	printf("d_ecran - mur: %.1f\n",env->distance);
	printf("h_ecran: %d\n",W_HEIGHT);
	printf("h_camera - sol: %d\n",env->h_regard);
	printf("h_mur_surEcran: %.1f\n", h_percue );
	double h_limsol_centreEcran;
	h_limsol_centreEcran = lim_sol - env->h_regard;
	printf("h_lim_sol: %.1f\n",lim_sol);
	printf("lim_sol: %.1f\n",env->lim_sol);


	put_pxl_img(env, x, lim_sol, 8);

	double d_cam_mur = ( env->h_regard * env->d_ecran ) /  h_limsol_centreEcran;
	printf("d_cam_mur: %f\n",d_cam_mur );
	double angle_limsol;
	angle_limsol = atan((lim_sol - env->h_regard) / env->d_ecran);
	printf("angle_limsol: %.1f : ( %.1f -  %d) /  %.1f) \n",angle_limsol, lim_sol, env->h_regard, env->d_ecran);

	double d_cam_ecran;
	d_cam_ecran = sqrt(pow(lim_sol - env->h_regard, 2) + pow(env->d_ecran, 2));
	printf("d_cam_ecran: %.1f\n", d_cam_ecran);

	double	rayons = 0;
	while (rayons)

	//valeur y sur ecran dur mur au sol
	while (lim_sol <= W_HEIGHT)
	{
		//put_pxl_img(env, x, lim_sol, 8);
		lim_sol++;
	}
	printf("\n");*/


}