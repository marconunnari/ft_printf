NAME=libftprintf.a

CFLAGS=-Wall -Wextra -Werror

OBJSDIR = objs
SRCSDIR = srcs
HEADERSDIR = includes
LIBFTHEADERSDIR=libft/includes
INCLUDES=-I$(HEADERSDIR) -I$(LIBFTHEADERSDIR)
LIBFT=libft/libft.a
LIBFTOBJSDIR=$(OBJSDIR)/libft

SRCS= ft_printf.c \
	init_placeholder.c \
	free_placeholder.c \
	create_placeholder.c \
	process_placeholder.c \
	print_functions.c \

OBJS := $(SRCS:%.c=$(OBJSDIR)/%.o)
LIBFTOBJS=$(LIBFTOBJSDIR)/*.o

all: $(NAME)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(LIBFTOBJSDIR): $(OBJSDIR)
	mkdir -p $(LIBFTOBJSDIR)

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFTOBJS): $(LIBFTOBJSDIR)
	rm -f $(LIBFTOBJS)
	make -C libft
	cp $(LIBFT) $(LIBFTOBJSDIR)/libft.a
	cd $(LIBFTOBJSDIR) && ar -x libft.a

$(NAME): $(OBJSDIR) $(OBJS) $(LIBFTOBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFTOBJS)

clean:
	rm -rf $(OBJSDIR)
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all
