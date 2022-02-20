# Sources
SRCS :=	src/ft_atoi.c \
	src/ft_bzero.c \
	src/ft_calloc.c \
	src/ft_isalnum.c \
	src/ft_isalpha.c \
	src/ft_isascii.c \
	src/ft_isdigit.c \
	src/ft_isprint.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_memset.c \
	src/ft_strchr.c \
	src/ft_strlcat.c \
	src/ft_strlcpy.c \
	src/ft_strlen.c \
	src/ft_strncmp.c \
	src/ft_strnstr.c \
	src/ft_strrchr.c \
	src/ft_tolower.c \
	src/ft_toupper.c \
	src/ft_strdup.c \
	src/ft_substr.c \
	src/ft_strjoin.c \
	src/ft_strtrim.c \
	src/ft_split.c \
	src/ft_itoa.c \
	src/ft_strmapi.c \
	src/ft_striteri.c \
	src/ft_putchar_fd.c \
	src/ft_putstr_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c \

# Linked list
SRCS :=	$(SRCS) \
	src/ft_lstnew.c \
	src/ft_lstadd_front.c \
	src/ft_lstsize.c \
	src/ft_lstlast.c \
	src/ft_lstadd_back.c \
	src/ft_lstdelone.c \
	src/ft_lstclear.c \
	src/ft_lstiter.c \
	src/ft_lstmap.c \

# Extra
SRCS :=	$(SRCS) \
	src/ft_min.c \
	src/ft_max.c \
	src/ft_abs.c \

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
	@$(Y)"Created $(NAME)\n"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(Y)"Linking $@"

clean:
	@$(RM) $(OBJS)
	@$(G)"Removed objects\n"

fclean: clean
	@$(RM) $(NAME)
	@$(G)"Removed $(NAME)\n"

norminette:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) | grep -v "OK" || true
	@$(G)"Checked sources norm.\n"
	@norminette -R CheckDefine $(HEADERS) | grep -v "OK" || true
	@$(G)"Checked headers norm.\n"

update:
	@git pull
	@$(G)"Up to date.\n"

re: fclean all

.PHONY: all clean fclean re
