NAME=libftprintf.a
TEMPNAME=$(OBJSDIR)/$(NAME)

CFLAGS=-Wall -Wextra -Werror

OBJSDIR = objs
SRCSDIR = srcs
HEADERSDIR = includes
LIBFTHEADERSDIR=libft/includes
INCLUDES=-I$(HEADERSDIR) -I$(LIBFTHEADERSDIR)
LIBFT=libft/libft.a

SRCS= ft_printf.c

OBJS := $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

makelibft:
	make -C libft

$(NAME): $(OBJSDIR) $(OBJS) makelibft
	ar rcs $(TEMPNAME) $(OBJS)
	libtool -static -o $(NAME) $(TEMPNAME) $(LIBFT)

clean:
	rm -rf $(OBJSDIR)
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all
