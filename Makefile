NAME := so_long

CC := cc
CFLAGS := -Wall -Wextra -Werror
MLX42_FLAGS	:=	-ldl -lglfw -pthread -lm
HEADERS	:= -I	$(LIBFT_DIR) -I	$(MLX42_DIR)/include/MLX42

LIBFT_DIR	:=	./libft
LIBFT	:=	$(LIBFT_DIR)/libft.a

MLX42_DIR	:=	./MLX42
MLX42	:=	$(MLX42_DIR)/build/libmlx42.a

MAN_SRC	:=	main.c	\

MAN_OBJ	:=	$(MAN_SRC:.c=.o)

all:	clone $(NAME)

clone:
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi

%.o:	%.c
	@cc	$(CFLAGS)	-o	$@	-c	$<	$(HEADERS)	&&	printf "Compiling: $(notdir $<)\n"

$(NAME):	$(MAN_OBJ)
	@cmake	$(MLX42_DIR)	-B	$(MLX42_DIR)/build && make	-C	$(MLX42_DIR)/build	-j4
	@make	-C	$(LIBFT_DIR)
	cc	$(MAN_OBJ)	$(LIBFT)	$(MLX42)	$(MLX42_FLAGS)	-o	$(NAME)

clean:
	@rm -f $(MAN_OBJ)
	@rm	-rf	$(MLX42_DIR)/build
	@make	-C	$(LIBFT_DIR)	clean

fclean:	clean
	@rm	-f	$(NAME)
	@make	-c	$(LIBFT_DIR)	fclean

re:	fclean	all

.PHONY:	all	clean	fclean	re	clone