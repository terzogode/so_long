# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 11:07:37 by gcollet           #+#    #+#              #
#    Updated: 2025/04/14 22:02:55 by mbrighi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= so_long

SRCS 	= srcs/so_long.c srcs/checker.c srcs/matrix_maker_free.c srcs/errors.c \
			srcs/utils.c srcs/check_map.c srcs/letsgoski.c srcs/initialize.c \
			srcs/check_coll.c

HEADER	= -Iincludes

MLX_DIR = ./minilibx-linux
MLX     = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

LIBFT   = ./libft
LIBFT_LIB = -L$(LIBFT) -lft

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g -v


all: 		${PROG}

${PROG}:	${SRCS}
					@make -C $(LIBFT)
					@make -C $(MLX_DIR)
					@$(CC) ${SRCS} ${CFLAGS} ${HEADER} $(LIBFT_LIB) $(MLX) -o ${PROG}
					$(MAKE) yolo

clean:
					@make clean -C $(LIBFT)
					@make clean -C $(MLX_DIR) 


fclean: clean
					@make fclean -C $(LIBFT) 
					@rm -f $(PROG)

re:			fclean all

yolo:
	@clear
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠠'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠶⡣⠑⠁'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢤⣮⠙⠓⠈⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⢊⡵⠋⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⢴⡯⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠛⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⢀⣤⣶⣿⣿⣷⣦⡀⠀⠀⠀⢀⣠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⣰⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⢶⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⢀⠔⢔⠊⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⢻⣿⣿⣿⣿⣿⡟⠉⢙⢟⢵⢿⠗⢨⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠙⣿⠛⠙⢏⣑⠖⡱⣮⠄⠁⢀⡾⢀⡇⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠘⠓⠒⢉⡵⣊⡴⣃⣠⠄⠉⣠⠞⢡⡟⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⢀⠖⢠⢔⣡⠞⠋⠀⠐⠶⡖⣀⡀⠘⠩⠴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠃⢺⡿⠋⠁⠀⠀⠀⠀⠀⠈⠁⠴⢄⠐⠧⣠⣞⡻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡾⠟⠈⣿⡿⠃⠺⠷⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⠏⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⣠⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢷⣄⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠐⢿⡋⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⣛⡃⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⣩⣥⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣯⠆⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠈⢻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⡇⠀⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⢀⠀⣤⢲⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⡶⡶⣰⠤⠀⠀⠀⠀'
	@echo	'⠀⠀⠀⠀⠀⠀⠀⠛⠉⠁⠁⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠉⠒⠁⠁⠀⠀⠀'

.PHONY: all clean fclean re re_bonus


