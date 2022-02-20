# Sources
SRCS := src/all/ft_atoi.c \
	src/all/ft_bzero.c \
	src/all/ft_calloc.c \
	src/all/ft_isalnum.c \
	src/all/ft_isalpha.c \
	src/all/ft_isascii.c \
	src/all/ft_isdigit.c \
	src/all/ft_isprint.c \
	src/all/ft_memchr.c \
	src/all/ft_memcmp.c \
	src/all/ft_memcpy.c \
	src/all/ft_memmove.c \
	src/all/ft_memset.c \
	src/all/ft_strchr.c \
	src/all/ft_strlcat.c \
	src/all/ft_strlcpy.c \
	src/all/ft_strlen.c \
	src/all/ft_strncmp.c \
	src/all/ft_strnstr.c \
	src/all/ft_strrchr.c \
	src/all/ft_tolower.c \
	src/all/ft_toupper.c \
	src/all/ft_strdup.c \
	src/all/ft_substr.c \
	src/all/ft_strjoin.c \
	src/all/ft_strtrim.c \
	src/all/ft_split.c \
	src/all/ft_itoa.c \
	src/all/ft_strmapi.c \
	src/all/ft_striteri.c \
	src/all/ft_putchar_fd.c \
	src/all/ft_putstr_fd.c \
	src/all/ft_putendl_fd.c \
	src/all/ft_putnbr_fd.c \

SRCS :=	$(SRCS) \
	src/linked_list/ft_lstnew.c \
	src/linked_list/ft_lstadd_front.c \
	src/linked_list/ft_lstsize.c \
	src/linked_list/ft_lstlast.c \
	src/linked_list/ft_lstadd_back.c \
	src/linked_list/ft_lstdelone.c \
	src/linked_list/ft_lstclear.c \
	src/linked_list/ft_lstiter.c \
	src/linked_list/ft_lstmap.c \

SRCS :=	$(SRCS) \
	src/ft_printf/ft_printf.c \
	src/ft_printf/options1.c \
	src/ft_printf/options2.c \
	src/ft_printf/utils.c \

SRCS :=	$(SRCS) \
	src/get_next_line/get_next_line.c \

SRCS :=	$(SRCS) \
	src/extra/ft_min.c \
	src/extra/ft_max.c \
	src/extra/ft_abs.c \

# Headers
HEADERS = include/libft.h

# Compile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wconversion -Wsign-conversion
OBJS := $(SRCS:.c=.o)
NAME = libft.a

# Clean
RM = rm -f

# Message
R = tput setaf 1 && echo -n "\r\033[K"
G = tput setaf 2 && echo -n "\r\033[K"
B = tput setaf 4 && echo -n "\r\033[K"
K = tput setaf 0 && echo -n "\r\033[K"
Y = tput setaf 3 && echo -n "\r\033[K"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@tput setaf 1
	@$(G)"Created $(NAME)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@tput setaf 1
	@$(Y)"$@"
	@tput setaf 1

clean:
	@tput setaf 1
	@$(RM) $(OBJS)
	@$(B)"Removed objects\n"

fclean: clean
	@tput setaf 1
	@$(RM) $(NAME)
	@$(B)"Removed $(NAME)\n"

norminette:
	@tput setaf 1
	@norminette -R CheckForbiddenSourceHeader $(SRCS) | grep -v "OK" || true
	@norminette -R CheckDefine $(HEADERS) | grep -v "OK" || true
	@$(B)"Norm checked.\n"

update:
	@tput setaf 1
	@git pull
	@$(B)"Updated.\n"

re: fclean all

.PHONY: all clean fclean re
