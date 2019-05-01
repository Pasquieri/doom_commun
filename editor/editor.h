/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:53:26 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/05/01 20:05:08 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "../libft/libft.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** GRID SIZE PX
*/
# define GRID_SQUARE 1000

/*
** TILE SQUARE PX
*/
# define TILE 25

/*
** GRID SQUARE
*/
# define GRID_SIZE 40

/*
** WINDOW DIMENSION
*/
# define HEIGHT 1024
# define WIDTH 1300

/*
** STYLE
*/
# define PADDING 12

/*
** BOOLEAN
*/
# define TRUE 1
# define FALSE 0

/*
** TEXTURE index
*/
# define FLOOR 0
# define W_GRAY 1
# define W_WHITE 2
# define W_BLUE 3
# define W_G_TAB 4
# define W_W_TAB 5
# define W_B_TAB 6
# define DOOR 7
# define BEGIN 8
# define END 9
# define GRID 10
# define WIN 11
# define COLUMN 12
# define BANANA 13
# define MONKEY 14
# define SYRINGE 15

/*
** Images collection position y
*/
# define FLOOR_POSITION 524
# define WALL_POSITION FLOOR_POSITION + TILE + PADDING
# define WALL_PICTURE_POSITION WALL_POSITION + TILE + PADDING
# define DOOR_POSITION WALL_PICTURE_POSITION + TILE + PADDING
# define BEGIN_END_POSITION DOOR_POSITION + TILE + PADDING
# define TRANSPARENT_POSITION BEGIN_END_POSITION + TILE + PADDING
# define COLUMN_POSITION TRANSPARENT_POSITION + TILE + PADDING
# define BANANA_POSITION COLUMN_POSITION + TILE + PADDING
# define MONKEY_POSITION BANANA_POSITION + TILE + PADDING
# define SYRINGE_POSITION MONKEY_POSITION + TILE + PADDING

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_data_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_data_mlx;

typedef struct		s_img
{
	int				bpp;
	int				sizeline;
	int				endlian;
	int				*data;
	void			*mlx_image;
}					t_img;

typedef struct		s_tile
{
	int				type;
	t_point			coord;
}					t_tile;

typedef struct		s_collection
{
	int				selected;
	int				type;
	t_point			coord;
	t_img			*texture;
}					t_collection;

typedef struct		s_file
{
	int				fd;
	int				fd_write;
	char			*filename;
	char			**file;
}					t_file;

typedef struct		s_player
{
	t_point			coord;
	int				rotation;
}					t_player;

typedef struct		s_editor
{
	int				music;
	t_file			file;
	t_player		player;
	t_collection	*collection;
	t_tile			**tiles;
	t_data_mlx		data;
	int				loop;
	int				button;
}					t_editor;

/*
** on_error.c
*/
int					err_free(char *to_free, int error);
int					err_free_dbl(char **tab, int size, int error);

/*
** map_to_file.c
*/
int					print_tiles(t_editor *editor);

/*
** cmd.c
*/
void				print_cmd(t_data_mlx data);
void				print_music(t_data_mlx data, int music);

/*
** notification.c
*/
void				print_notif(t_data_mlx data, int error_type);
void				clean_notification(t_data_mlx data);

/*
** validate_file.c
*/
int					check_map_file(char **map_file, t_player player);
int					check_border(int value, int y, int x);
/*
** file.c
*/
int					init_file(char *ar_file, t_editor *editor);

/*
** file_validate_player.c
*/
int					check_player_file(char *line, t_player *player);

/*
** file_validate_map.c
*/
int					check_map_file(char **map_file, t_player player);

/*
** read.c
*/
int					read_player(int fd, t_player *player);
int					read_music(int fd, int *music);
int					read_map(t_file *file, t_player player);

/*
** helpers.c
*/
char				*ft_strjoin_free(char *s1, char *s2, int to_free);
int					str_is_digit(char *str);
int					ft_arr_len(char **array);
void				free_double_tab(char **tab);

/*
** tiles.c
*/
void				reset_tiles(t_tile **tiles);
int					file_to_tiles(char **file, t_tile **tiles);

/*
** init.c
*/
int					init(int argc, char **argv, t_editor *editor);
int					init_window(t_data_mlx *data);
int					init_image(t_img *img, int width, int height,
t_data_mlx data);

/*
** init_tiles.c
*/
t_tile				**init_tiles(void);
int					init_type_tile(int x, int y);
t_tile				**free_tiles(t_tile **tiles, int size);
/*
** init_collection.c
*/
t_collection		*init_collection(t_data_mlx data);

/*
** init_coord_collection.c
*/
t_point				init_coord_collection(int tex);
t_collection		*free_collection(int size, t_collection *collection,
t_data_mlx data);
/*
** init_xpm_image.c
*/
void				*init_xpm(int tex, t_data_mlx data, t_point *xpm_size);

/*
** init_grid.c
*/
int					init_grid(t_data_mlx data, t_tile **tiles);
int					grid_collection(t_data_mlx data, t_tile **tiles,
t_collection *collection);

/*
** put_pixel.c
*/
void				put_pixel_to_img(t_img *img, int width,
t_point point, int color);

/*
** mouse_event.c
*/
int					on_mouse_event(int x, int y, t_editor *editor);
int					click_press(int button, int x, int y, t_editor *editor);
int					click_release(int button, int x, int y, t_editor *editor);

/*
** keyboard_event.c
*/
int					on_key_event(int keycode, t_editor *editor);

/*
** collection_selection.c
*/
void				handle_selection(t_editor *editor, t_point coord);
int					get_type_selected(t_collection *collection);

/*
** event_on_grid.c
*/
void				add_selected_on_grid(t_point coord, t_editor *editor,
t_point coord_tile);
void				remove_on_grid(t_point coord, t_editor *editor,
t_point coord_tile);

/*
** validate_event_on_grid.c
*/
int					validate_compatibility(int type_collection, int type_tile,
t_tile **tiles);

/*
** rotation.c
*/
int					calc_rotation(t_tile **tiles, t_point player_position);

/*
** validate_end_map.c
*/
int					valid_map(t_editor *editor);

/*
** end.c
*/
int					end(t_editor *editor);

/*
** error.c
*/
int					error(int error_code, t_editor *editor);

#endif
