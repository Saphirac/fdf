NAME =	fdf

INC =	./includes

SRCS =	./srcs/main.c \
		./srcs/parse.c \
		./srcs/utils.c \
		./srcs/checks.c \
		./srcs/fdf_utils.c \
		./gnl/get_next_line_utils.c \
		./gnl/get_next_line.c \
		./srcs/print_map.c \
		./srcs/isometrics.c \
		./srcs/parse_2.c \
		./srcs/dda.c

MLX = /usr/local/lib/
LIBFT_PATH = ./Libft/
LIBFT = ${LIBFT_PATH}libft.a

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra 
FLAGS_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

.c.o:
	$(CC) $(CFLAGS) -I$(INC) -Imlx_linux -O3 -lm -c $< -o $@

$(NAME) : $(OBJS) ${LIBFT}
	$(CC) $(OBJS) $(FLAGS_MLX) ${LIBFT} -o $(NAME)

all: $(NAME)

${LIBFT}:
	make -C ${LIBFT_PATH}

clean :
	$(RM) $(OBJS)
	make -C ${LIBFT_PATH} clean

fclean : clean
	$(RM) $(NAME)
	make -C ${LIBFT_PATH} fclean

re : fclean all

.PHONY: all clean fclean re