HEADERS := ft_printf.h

NAME = libftprintf.a


SRCS := ft_printf.c \
		det_type.c \
		print_c.c \
		print_s.c \
		print_p.c \
		print_d_i.c \
		print_u.c \
		print_x_X.c \

OBJS := $(SRCS:.c=.o);

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 