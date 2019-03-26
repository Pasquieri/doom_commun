# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:10:32 by cpalmier          #+#    #+#              #
#    Updated: 2019/02/26 16:51:56 by cpalmier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	  ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c\
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
	  ft_strlenre.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
	  ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
	  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
	  ft_toupper.c ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
	  ft_lstiter.c ft_lstmap.c ft_sqrt.c ft_power.c ft_print_table.c\
	  ft_strcapitalize.c ft_swap.c ft_lstadd_end.c get_next_line.c

HEADER = libft.h
OBJ = $(SRC:.c=.o)

COLOR = \033[1;35m
COLOR_OFF = \033[0m

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "${COLOR}Libft.a created${COLOR_OFF}"

%.o : %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@ -I $(HEADER)

clean :
	@rm -rf $(OBJ)
	@echo "${COLOR}Libft clean${COLOR_OFF}"

fclean :
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "${COLOR}Libft fclean${COLOR_OFF}"

re : fclean $(NAME)
