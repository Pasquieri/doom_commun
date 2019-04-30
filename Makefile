NAME = doom-nukem

SRC = src/main.c\
	  \
	  src/initialize/init_sprite.c\
	  src/initialize/init_texture.c\
	  src/initialize/init_env.c\
	  src/initialize/win_init.c\
	  \
	  src/action/deplacements.c\
	  src/action/deplacements_extra.c\
	  src/action/key_apply.c\
	  src/action/rotation_regard.c\
	  src/action/motion_notify.c \
	  src/action/trig_press.c\
	  src/action/deal_door.c\
	  src/action/monkey.c\
	  src/action/jump_crouch.c\
	  src/action/check_card.c\
	  \
	  src/menu/menu_init.c\
	  src/menu/hub_init.c\
	  src/menu/ft_play_music.c\
	  src/menu/chaine_nb.c\
	  src/menu/hub.c\
	  src/menu/menu_open.c\
	  src/menu/menu_arrow.c\
	  src/menu/key_menu.c\
	  src/menu/free_sprite.c\
	  \
	  src/parser/error_message.c\
	  src/parser/wall_row.c\
	  src/parser/wall_line.c\
	  src/parser/fill_tab.c\
	  src/parser/malloc_tab.c\
	  src/parser/verif_valeur.c\
	  src/parser/recup_info_player.c\
	  src/parser/check_file.c\
	  src/parser/check_open_map.c\
	  src/parser/pars.c\
	  src/parser/fill_tab_extra.c\
	  \
      src/put_image/ft_trace_seg.c\
      src/put_image/put_pxl_img.c\
	  src/put_image/mini_map.c\
	  src/put_image/put_texture_img.c\
	  src/put_image/print_tab.c\
	  src/put_image/print_gun.c\
	  \
	  src/raycasting/ft_pthread.c\
	  src/raycasting/detec_first_inter.c\
	  src/raycasting/detection_mur.c\
	  src/raycasting/detection_mur_horizontal.c\
	  src/raycasting/detection_mur_vertical.c\
	  src/raycasting/affichage_mur.c\
	  src/raycasting/exec_calcul.c\
	  src/raycasting/affichage_sol.c\
	  src/raycasting/affichage_plafond.c\
	  \
	  src/sprites/affichage_sprite.c\
	  src/sprites/detec_shoot.c\
	  src/sprites/verif_shoot_ver.c\
	  src/sprites/verif_shoot_hor.c\
	  src/sprites/detection_mur_sp.c\
	  src/sprites/verif_mur_ver.c\
	  src/sprites/verif_mur_hor.c\
	  src/sprites/check_sprite.c\
	  src/sprites/print_sprite_object.c\
	  src/sprites/print_sprite_wall.c\
	  src/sprites/order_sprite.c\
	  src/sprites/calcul_spr.c


HEADER = -Ilibft -Iinclude

OBJ = $(SRC:.c=.o)

COLOR = \033[1;33m
COLOR_OFF = \033[0m

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C minilibx
	@gcc -Wall -Werror -Wextra -I minilibx/ minilibx/libmlx.a \
		-framework OpenGL -framework AppKit \
		$(HEADER) $(SRC) libft/libft.a
	@mv a.out $(NAME)
	@echo "${COLOR}all : Doom-nukem created √${COLOR_OFF}"

./%.o : src/%.c $(HEADER)
	@gcc -Wall -Werror -Wextra -I minilibx/ minilibx/libmlx.a\
		-framework OpenGL -framework AppKit \
		-c $< -o $@ -I $(HEADER) libft/libft.a

clean :
	make -C libft clean
	make -C minilibx clean
	@rm -rf $(OBJ)
	@echo "${COLOR}Doom-nukem clean √${COLOR_OFF}"

fclean : clean
	make -C libft fclean
	@rm -rf $(NAME)
	@echo "${COLOR}Doom-nukem fclean √${COLOR_OFF}"

re : fclean all
