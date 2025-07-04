NAME 		:= so_long

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror

LIBFT_DIR	:=	./libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

MLX42_DIR	:=	./MLX42
MLX42		:=	$(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS	:=	-ldl -lglfw -pthread -lm

HEADERS		:= -I $(LIBFT_DIR) -I $(MLX42_DIR)/include/MLX42 -I./include

MAN_DIR 	:=	./source
MAN_FILES	:=	read_map.c		\
				check_map.c		\
				start_game.c	\
				init_image.c	\
				display_map.c	\
				hooks.c			\
				move_player.c	\
				utils.c			\
				free.c
MAN_SRC			:= main.c	$(addprefix	$(MAN_DIR)/,	$(MAN_FILES))

MAN_OBJ			:=	$(MAN_SRC:.c=.o)

all:	$(NAME)

$(MAN_OBJ): | $(MLX42)

$(NAME): $(MAN_OBJ) $(LIBFT) $(MLX42)
	$(CC) $(MAN_OBJ) $(LIBFT) $(MLX42) $(MLX42_FLAGS) -o $(NAME)

$(MLX42):	.cloned
.cloned:
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
	fi
	@cmake -B $(MLX42_DIR)/build -S $(MLX42_DIR) && cmake --build $(MLX42_DIR)/build -j4
	@touch	.cloned

%.o:	%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"


	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(MAN_OBJ)	.cloned
	@rm -rf $(MLX42_DIR)/build
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re