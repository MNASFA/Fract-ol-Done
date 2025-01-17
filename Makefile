CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLX = minilibx/libmlx_Linux.a
NAME = fractol
SRCS = src/fractal.c src/main.c src/hooks.c src/render.c src/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -lXext -lX11 -lm $(MLX) -o $(NAME)

$(MLX):
	$(MAKE) -C minilibx

%.o : %.c fractol.h minilibx/mlx.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C minilibx clean

re : fclean all