NAME =	fdf

INC =	./includes

SRCS =	./srcs/main.c

MLX = /usr/local/lib/
LIBFT_PATH = ./Libft/
LIBFT = ${LIBFT_PATH}libft.a

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra 
FLAGS_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.c.o:
	$(CC) $(CFLAGS) -I$(INC) -Imlx_linux -O3 -c $< -o $@

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