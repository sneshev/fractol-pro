NAME = fractol
CC = cc 
CFLAGS = -g -Wall -Wextra -Werror

MLX = https://github.com/42paris/minilibx-linux.git
MLX_PATH = MLX42
LIBFT = https://github.com/sneshev/libft_42.git
LIBFT_PATH = libft

all:  libft MLX $(NAME)

MLX: 
	@[ -d "$(MLX_PATH)" ] || (git clone $(MLX) $(MLX_PATH) && cd $(MLX_PATH) && make)

libft:
	@[ -d "$(LIBFT_PATH)" ] || git clone $(LIBFT) $(LIBFT_PATH);
	@cd $(LIBFT_PATH) && make 

SRCS = $(wildcard src/*.c)
OBJS_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)
OBJS := $(OBJS:ft_printf/%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

LIBS = -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lXext -lX11

$(NAME): $(OBJS) libft MLX
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR) $(NAME)

fclean:
	rm -rf $(MLX_PATH) $(LIBFT_PATH) $(OBJS_DIR) $(NAME)

re: fclean all