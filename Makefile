NAME =	so_long

INC =	include

SRCS =	main.c


MLX = /usr/local/lib/

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra 
FLAGS_MLX= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(FLAGS_MLX) -o $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(FLAGS_MLX) -o $(NAME)