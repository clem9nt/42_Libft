# @author   cvidon@42
# @brief    Makefile for C library.

NAME		= libft.a
INC_DIR		= include
SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= dlst/ft_dlstadd_back.c \
			  dlst/ft_dlstadd_front.c \
			  dlst/ft_dlstclear.c \
			  dlst/ft_dlstdelfirst.c \
			  dlst/ft_dlstdelone.c \
			  dlst/ft_dlstiter.c \
			  dlst/ft_dlstlast.c \
			  dlst/ft_dlstmap.c \
			  dlst/ft_dlstnew.c \
			  dlst/ft_dlstsize.c \
			  lst/ft_lstadd_back.c \
			  lst/ft_lstadd_front.c \
			  lst/ft_lstclear.c \
			  lst/ft_lstdelfirst.c \
			  lst/ft_lstdelone.c \
			  lst/ft_lstiter.c \
			  lst/ft_lstlast.c \
			  lst/ft_lstmap.c \
			  lst/ft_lstnew.c \
			  lst/ft_lstsize.c \
			  is/ft_isalnum.c \
			  is/ft_isalpha.c \
			  is/ft_isascii.c \
			  is/ft_isdigit.c \
			  is/ft_isprint.c \
			  is/ft_isspace.c \
			  int/ft_abs.c \
			  int/ft_max.c \
			  int/ft_min.c \
			  int/ft_numlen.c \
			  mem/ft_bzero.c \
			  mem/ft_calloc.c \
			  mem/ft_memchr.c \
			  mem/ft_memcmp.c \
			  mem/ft_memcpy.c \
			  mem/ft_memmove.c \
			  mem/ft_memset.c \
			  io/ft_get_next_line.c \
			  io/ft_putchar_fd.c \
			  io/ft_putendl_fd.c \
			  io/ft_putnbr_fd.c \
			  io/ft_putstr_fd.c \
			  str/ft_split.c \
			  str/ft_strchr.c \
			  str/ft_strcmp.c \
			  str/ft_strdup.c \
			  str/ft_striteri.c \
			  str/ft_strjoin.c \
			  str/ft_strjoin_free.c \
			  str/ft_strjoin_free_s1.c \
			  str/ft_strjoin_free_s2.c \
			  str/ft_strlcat.c \
			  str/ft_strlcpy.c \
			  str/ft_strlen.c \
			  str/ft_strmapi.c \
			  str/ft_strncmp.c \
			  str/ft_strnstr.c \
			  str/ft_strrchr.c \
			  str/ft_strtrim.c \
			  str/ft_substr.c \
			  to/ft_atoi.c \
			  to/ft_atol.c \
			  to/ft_itoa.c \
			  to/ft_tolower.c \
			  to/ft_toupper.c \

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -c
CPPFLAGS	= -I include
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#------------------------------------------------#
#	SHELL CMDS									 #
#------------------------------------------------#

RM			= rm -rf

#------------------------------------------------#
#	RECIPES										 #
#------------------------------------------------#

.PHONY: all clean fclean re san_addr scream cry norm update

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@$(ECHO)"$(G)created$(END) $(END)$(NAME)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p  $(@D) || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@
	@$(ECHO)"$(G)created $(END)$@"

clean:
	@[ -d $(OBJ_DIR) ] \
		&& $(RM) $(OBJ_DIR) && $(ECHO)"$(R)removed$(END) $(OBJ_DIR)/\n" || true

fclean: clean
	@[ -f "$(NAME)" ] && $(RM) $(NAME) && $(ECHO)"$(R)removed$(END) $(NAME)\n" || true

re : fclean all

san_addr: CC		:= gcc
san_addr: CFLAGS	:= $(CFLAGS) -g -fsanitize=address,undefined,signed-integer-overflow
san_addr: $(NAME)

scream: CFLAGS		:= $(CFLAGS) -Wconversion -Wsign-conversion -Wwrite-strings -Wcast-qual -Wcomma -pedantic -std=c89
scream: $(NAME)

cry: CFLAGS			:= $(CFLAGS) -Weverything
cry: $(NAME)

norm:
	@norminette | grep -v "OK" || true
	@$(ECHO)"$(G)checked norm$(END)\n"

update:
	@git pull
	@git submodule update --init
	@$(ECHO)"$(G)updated$(END)\n"

#------------------------------------------------#
#	STDOUT										 #
#------------------------------------------------#

R		= $(shell tput setaf 1)
G		= $(shell tput setaf 2)
Y		= $(shell tput setaf 3)
B		= $(shell tput setaf 4)
M		= $(shell tput setaf 5)
C		= $(shell tput setaf 6)
W		= $(shell tput setaf 7)
K		= $(shell tput setaf 8)
END		= $(shell tput sgr0)
ECHO	= echo -n "\r\033[K$(NAME): "
