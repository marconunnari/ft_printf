NAME=libftprintf.a

CFLAGS=-Wall -Wextra -Werror

OBJSDIR=objs
LIBFTOBJSDIR=$(OBJSDIR)/libft
SRCSDIR=srcs
LIBFTSRCSDIR=libft
HEADERSDIR=includes
LIBFTHEADERSDIR=libft/includes
INCLUDES=-I$(HEADERSDIR) -I$(LIBFTHEADERSDIR)

SRCS= ft_printf.c \

LIBFTSRCS= ft_strlen.c \

OBJS := $(SRCS:%.c=$(OBJSDIR)/%.o)
LIBFTOBJS := $(LIBFTSRCS:%.c=$(LIBFTOBJSDIR)/%.o)

all: $(NAME)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(LIBFTOBJSDIR): $(OBJSDIR)
	mkdir -p $(LIBFTOBJSDIR)

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFTOBJS): $(LIBFTOBJSDIR)/%.o: $(LIBFTSRCSDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJSDIR) $(OBJS) $(LIBFTOBJSDIR) $(LIBFTOBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFTOBJS)

clean:
	make clean -C libft
	rm -rf $(OBJSDIR)
	rm -f $(LIBFT)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
