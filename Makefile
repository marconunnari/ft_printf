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
	ft_puts.c \
	ft_doprint.c \
	ft_doconv.c \
	ft_createph.c \
	ft_getph.c \
	ft_conv_s.c \
	ft_conv_d.c \

LIBFTSRCS= ft_strlen.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strrev.c \
	ft_strdup.c \
	ft_memcpy.c \
	ft_strcont.c \
	ft_strappend.c \
	ft_isdigit.c \
	ft_imaxtoa.c \

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
