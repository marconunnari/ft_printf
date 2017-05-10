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
	ft_width.c \
	ft_numprec.c \
	ft_conv_s.c \
	ft_conv_ws.c \
	ft_conv_d.c \
	ft_conv_c.c \
	ft_conv_wc.c \
	ft_conv_pc.c \
	ft_conv_uox.c \
	ft_wchar.c \

LIBFTSRCS= ft_strlen.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strequ.c \
	ft_strcmp.c \
	ft_strchr.c \
	ft_strstr.c \
	ft_strrev.c \
	ft_strdup.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_memmove.c \
	ft_strcont.c \
	ft_strappend.c \
	ft_strprepend.c \
	ft_strremove.c \
	ft_isdigit.c \
	ft_imaxtoa.c \
	ft_imaxtoa_sign.c \
	ft_uimaxtoa_base.c \
	ft_islower.c \
	ft_isupper.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strtoupper.c \
	ft_strjoin.c \
	ft_strmerge.c \
	ft_strsub.c \
	ft_strncpy.c \
	ft_strcat.c \

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
