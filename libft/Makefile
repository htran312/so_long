NAME := libft.a

CC := cc
CFLAGS := -g -Wall -Wextra -Werror

FT_PRINTF_DIR := ./ft_printf

GNL_DIR	:=	./get_next_line

LIBFT_SRC := 	ft_putnbr_fd.c	\
			ft_putendl_fd.c	\
			ft_putstr_fd.c	\
			ft_putchar_fd.c	\
			ft_striteri.c	\
			ft_strmapi.c	\
			ft_itoa.c	\
			ft_split.c	\
			ft_strtrim.c	\
			ft_strjoin.c	\
			ft_substr.c	\
			ft_strdup.c	\
			ft_calloc.c	\
			ft_atoi.c	\
			ft_bzero.c	\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_memchr.c	\
			ft_memcmp.c	\
			ft_memcpy.c	\
			ft_memmove.c	\
			ft_memset.c	\
			ft_strchr.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_tolower.c	\
			ft_toupper.c

FT_PRINTF_SRC	:=	$(FT_PRINTF_DIR)/ft_putchar.c	\
						$(FT_PRINTF_DIR)/ft_putstr.c	\
						$(FT_PRINTF_DIR)/ft_putaddress.c	\
						$(FT_PRINTF_DIR)/ft_putnbr.c	\
						$(FT_PRINTF_DIR)/ft_putunbr.c	\
						$(FT_PRINTF_DIR)/ft_putxnbr_uppercase.c	\
						$(FT_PRINTF_DIR)/ft_printf.c

GNL_SRC	:=	$(GNL_DIR)/get_next_line.c	\
			$(GNL_DIR)/get_next_line_utils.c

LIBFT_OBJ	:=	$(LIBFT_SRC:.c=.o)
FT_PRINTF_OBJ	:=	$(FT_PRINTF_SRC:.c=.o)
GNL_OBJ	:=	$(GNL_SRC:.c=.o)


all: $(NAME)

$(NAME):	$(LIBFT_OBJ) $(FT_PRINTF_OBJ)	$(GNL_OBJ)
	ar	rcs	$(NAME)	$(LIBFT_OBJ) $(FT_PRINTF_OBJ)	$(GNL_OBJ)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm	-f	$(LIBFT_OBJ) $(FT_PRINTF_OBJ)	$(GNL_OBJ)

fclean:	clean
	@rm	-f	$(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
