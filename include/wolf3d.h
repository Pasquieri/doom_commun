/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:13:49 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/26 20:59:05 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>

# define FLOOR 0 // SOL OK
# define W_GRAY 1
# define W_WHITE 2 // WALL OK
# define W_BLUE 3
# define W_G_TAB 4
# define W_W_TAB 5 // TAB OK
# define W_B_TAB 6
# define DOOR 7 // OK : manque animation
# define BEGIN 8
# define END 9
# define GRID 10 // OK : revoir pour afficher les 4 cotes ou pas
# define WIN 11 // OK
# define COLUMN 12 //sprite sans mouvements
# define BANANA 13 // idem a ramasser : disparition & gain de vie
# define MONKEY 14 // sprite en mouvement : ennemis
# define DOOR_CLOSE 15 // animation a faire
# define SYRINGE 16 // 18
# define PLAFOND 21 // PLAFOND OK
# define SKY 22 // SKYBOX OK
# define NB_SP 9
# define W_HEIGHT 870
# define W_WIDTH 1200
# define SPEED 0.5

typedef struct	s_coord
{
	double	x;
	double	y;
	int		val;
}				t_coord;

typedef struct	s_cercle
{
	int		rayon;
	int		color;
	t_coord	coord;
}				t_cercle;

typedef struct	s_coef
{
	int		x;
	int		y;
}				t_coef;

typedef struct	s_fill
{
	char	*line;
	char	**tmp;
	int		nb_char;
	int		verif;
	int		i;
	int		j;
	int		nb_sol;
	int		k;
}				t_fill;

typedef struct	s_rgb
{
	int		b;
	int		g;
	int		r;
	int		a;
}				t_rgb;

typedef struct	s_color_menu
{
	int		black_color;
	int		red_color;
	int		play_color;
	int		exit_color;
	int		map1_color;
	int		map2_color;
	int		map3_color;
	int		map4_color;
}				t_color_menu;

typedef struct	s_mlx
{
	void	*img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		end;
	int		width;
	int		height;
}				t_mlx;

typedef struct	s_det
{
	_Bool	on;
	double	dist;
	t_coord	cd;
}				t_det;

/*typedef struct	s_test_sp
{
	double	alpha;
	double	beta;
	double	gamma;
	double	a1;
	double	a2;
}				t_test_sp;*/

/*typedef struct	s_cd
{
	t_coord	mid;
	t_coord	left_h;
	t_coord	left_b;
	t_coord	right_h;
	t_coord	right_b;
}				t_cd;*/

typedef struct	s_sprite
{
	int		i;
	int		j;
//	t_cd	c;
	t_coord	cd;

/****** SPRITES *******/
/*	int		det;
	int		f_win_x;
	t_coord	f_int;
	double	f_angle;
	t_coord	coin1;
	t_coord	coin2;
	t_test_sp	t;

	int		win_h_x;
	t_coord	cd_h;
	double	angle_h;
	int		win_v_x;
	t_coord	cd_v;
	double	angle_v;*/

	int		o_i;
	double	a_i;
	double	a1;
	double	a2;
	t_coord	cd_i;

	int		o_f; // pour la fin du sprite a afficher
	double	a_f;
	t_coord	cd_f;

	int		det;
	int		det_hor;
	int		win_x;
	int		win_h_x;
	int		win_v_x;
	t_coord	cd_h;
	t_coord	cd_v;

	t_det	detec[2];
	_Bool	check;

	_Bool	proximity;
	_Bool	open;
	_Bool	alive;
	//int	ordre; //affichage sprite dans l'ordre ?
}				t_sprite;

typedef struct	s_sp
{
	int			val;
	int			nb;
	t_sprite	*sprite;
}				t_sp;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_mlx	m[2];
	_Bool	key[604];

	//thread
	int		current_thread;
	int		angle_thread;

	//Hub
	void	*h_mlx;
	void	*story_mlx;
	t_mlx   hub_end;
	//void	*h_end_mlx;
	int		h_life;
	int		h_monkey;
	int		h_init;
	int		h_ammo;
	int		h_end;
	int		h_help;
	int		h_story;

	int		coef;
	int		x;
	int		y;
	int		**tab;
	int		d_regard;
	double	angle;
	double	perso_x;
	double	perso_y;
	int		perso_r;
	double	vitesse;
	int		musique;
	int		value;

	//menu
	int		detail;
	int		menu;
	int		menu_select;
	int		map_entree;
	t_mlx	menu_txt;

	int		nb_colonne;
	float	d_ecran;
	int		h_mur;
	int		coef_h_wall;
	int		cmp_wall;
	t_coord	coord_mur;
	int		wall_nb;
	double	dist;
	int		img_x;
	int		img_y;
	int		h_regard;
	float	lim;
	float	lim_sol;
	int		orientation;
	int		skybox;
	int		lum;
	int		lum_int;

	int 	time;
	double	jump;
	double	h_jump;
	int		jump_move;
	double	crouch;


	t_rgb	rgb[10];
	t_mlx	text[25];
	t_mlx	sp_t[NB_SP]; // textures des sprites
	t_sp	sp[NB_SP];
	t_coord	coord_spr;
	int		lim_gun[5]; // seringue ??
	_Bool	gun;
}				t_env;

/*action*/
void			mouse_move(t_env *env);
void			deplacements(t_env *env);
int				check_wall(double xa, double ya, t_env *env);
void			depla_horizontal(t_env *env, int key);
void			depla_vertical(t_env *env, int key);
int				key_press(int key, t_env *env);
int				key_release(int key, t_env *env);
int				key_apply(t_env *env);
int				motion_notify(int x, int y, t_env *env);
void			rotation_regard(t_env *env);
int				trig_press(t_env *env);
void			deal_door(t_env *env);
void			deal_tab(t_env *env);
void			deal_items(t_env *env, int k);
void			ft_monkey(t_env *env);
void			ft_crouch(t_env *env);
void			ft_jump(t_env *env);
/*initialize*/
void			init_rgb(t_env *env);
void			init_env(t_env *env);
void			init_sprite(t_env *env);
void			number_sprite(t_env *env);
void			init_tab_sprite(t_env *env);
int				init_texture(t_env *env);
int				win_init(t_env *env);
/*menu*/
char			*chaine_nb(char *str, int nb);
void			hub_init(t_env *env);
void			print_hub(t_env *env);
void			key_invalid_menu(t_env *env);
void			key_valid_menu(t_env *env);
void			arrow_menu(t_env *env);
void			open_menu(t_env *env);
void			free_sprite(t_env *env);
/*parser*/
int				check_file(int	fd, t_env *env);
int				check_open_map(char *map, int fd, t_env *env);
int				error_message(int num, t_env *env);
int				fill_tab(int fd, t_env *env);
int				verif_case(char c);
int				verif_nb_tab(char **str, t_env *env);
int				tablen(char **str);
int				compte_char(char *str, char c);
int				verif_char(char *str, t_env *env);
int				malloc_tab(t_env *env);
int				pars_init(int argc, char **argv, t_env *var_check);
int				re_pars(char *str, t_env *env);
int				recup_info_player(char *str, char c);
int				verif_valeur(char *str, t_env *env);
int				wall_line(char *str, t_env *env);
int				wall_row(char *str, int nb_char, t_env *env);
/*put_image*/
int				ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);
void			color_case(t_env *env);
void			quadrillage(t_env *env);
void			print_cercle(t_env *env);
void			print_gun(t_env *env, int k);
void			print_tab(t_env *env, float p_y, float p_x, t_mlx *sp);
void			put_pxl_img(t_env *env, int x, int y, int color);
void			put_texture_img(t_env *env, double h_per, int y, t_mlx *text,
					double bep);
char			luminosite(int text, int coef);
/*raycasting*/
void			ft_pthread(t_env *env);
void			*affichage_mur(void *env);
int				intersection_horizontal(t_env *env, t_coord *cd);
int				intersection_vertical(t_env *env, t_coord *cd);
double			detection_mur(t_env *env);
int				init_var_hor(t_env *env, double *ya, double *xa, t_coord *c1);
int				coef_hor(t_env *env, int *coef_x, int *coef_y);
int				verif_hor(t_env *env, t_coord *coord);
int				init_var_ver(t_env *env, double *ya, double *xa, t_coord *c2);
int				coef_ver(t_env *env, int *coef_x, int *coef_y);
int				verif_ver(t_env *env, t_coord *coord);
void			exec_calcul(t_env *env, int d_regard, int init);
void			clean_img(t_env *env);
void			affichage_sol(double y, double h_percue, t_env *env);
void			affichage_plafond(double y, double h_percue, t_env *env);
/*sprites*/
void			affichage_sprite(t_env *env);
void			detection_mur_sp(t_env *env);
int				verif_hor_sp(t_env *env, t_coord *coord);
int				verif_ver_sp(t_env *env, t_coord *coord);
void			check_sprite(int i, int j, t_env *env, int orie, t_coord cd);
void			print_sprite_object(t_env *env);
void			print_sprite_wall(t_env *env);
void			check_grid_win(t_env *env, t_coord cd, int o, int i, int j);
double			verif_angle(double angle);
t_coord			init_lim_coord(t_env *env, int k, int cmp, double theta);
double			init_lim_angle(t_env *env, t_coord cd);
/*song*/
int				recup_music(char *str);

#endif
