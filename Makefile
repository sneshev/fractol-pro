NAME = fractol
CC = cc 
CFLAGS = -g -Wall -Wextra -Werror

MINILIBX = https://github.com/42paris/minilibx-linux.git
MLIBX_PATH = minilibx
LIBFT = https://github.com/sneshev/libft_42.git
LIBFT_PATH = libft

all:  libft mlibx $(NAME)

mlibx: 
	@[ -d "$(MLIBX_PATH)" ] || (git clone $(MINILIBX) $(MLIBX_PATH) && cd $(MLIBX_PATH) && make)

libft:
	@[ -d "$(LIBFT_PATH)" ] || git clone $(LIBFT) $(LIBFT_PATH);
	@cd $(LIBFT_PATH) && make 

SRCS = $(wildcard src/*.c) $(wildcard ft_printf/*.c)
OBJS_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)
OBJS := $(OBJS:ft_printf/%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJS_DIR)/%.o: ft_printf/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

LIBS = -L$(LIBFT_PATH) -lft -L$(MLIBX_PATH) -lmlx -lXext -lX11

$(NAME): $(OBJS) libft mlibx
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR) $(NAME)

fclean:
	rm -rf $(MLIBX_PATH) $(LIBFT_PATH) $(OBJS_DIR) $(NAME)

re: fclean all