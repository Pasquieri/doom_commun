.PHONY: all clean fclean re

NAME = editor
SRC = 	src/map_to_file.c\
		src/on_error.c\
		src/helpers.c\
		src/main.c\
		src/init.c\
		src/init_file.c\
		src/read.c\
		src/file_validate_player.c\
		src/file_validate_map.c\
		src/init_tiles.c\
		src/init_grid.c\
		src/init_collection.c\
		src/init_coord_collection.c\
		src/init_xpm_image.c\
		src/collection_selection.c\
		src/tiles.c\
		src/cmd.c\
		src/notification.c\
		src/mouse_event.c\
		src/keyboard_event.c\
		src/event_on_grid.c\
		src/validate_event_on_grid.c\
		src/put_pixel_image.c\
		src/error.c\
		src/validate_end_map.c\
		src/rotation.c\
		src/end.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
CC = gcc
LIB	=	-L ../libft/ -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -l ft
HEADERS = includes/ -I/usr/local/include
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
NC		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ../libft
	@$(CC) $(FLAGS) -I $(HEADERS) $(LIB) $(OBJ) -o $(NAME)
	@echo "[$(YELLOW)✓$(NC)] Executable $(NAME) compiled"

%.o: %.c editor.h
	@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@
	@echo "[$(GREEN)✓$(NC)] Object $@ compiled"

clean:
	@rm -f $(OBJ)
	@make clean -C ../libft/
	@echo "[$(RED)-$(NC)] Objects from $(NAME) cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ../libft/
	@echo "[$(RED)-$(NC)] Executable $(NAME) cleaned"

re: fclean all
