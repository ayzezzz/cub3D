NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
MINIFLAGS = #-L./lib/minilibx_linux -L/usr/lib -lXext -lX11 -lm -lz -lbsd -I/usr/include
RM = rm -rf
SRCS = cub3d.c
MLX = ./lib/minilibx_linux/libmlx.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./lib/libft/libft.a
PINK = \033[0;35m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	@make -C ./lib/libft -s
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINIFLAGS)
	@echo "$(PINK)<< THE GAME IS READY! <3 >>$(NC)"

$(MLX):
	@make -C ./lib/minilibx_linux

clean:
	@make clean -C ./lib/libft -s 
	@make clean -C ./lib/minilibx_linux
	$(RM) $(OBJS)
	@echo "$(PINK)<< OBJECT FILES ARE REMOVED! <3 >>$(NC)"

fclean: clean
	@make fclean -C ./lib/libft -s 
	$(RM) $(NAME)
	@echo "$(PINK)<< THE GAME IS REMOVED! <3 >>$(NC)"

re: fclean all

.PHONY: all clean fclean re
