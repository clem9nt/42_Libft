# @file     Makefile
# @brief    Makefile for C library.
# @author   clemedon (Clément Vidon)

NAME		:= libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags
#
# SRC_DIR   source directory
# BUILD_DIR object directory
# SRCS      source files
# OBJS      object files
# DEPS      dependency files

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -c
CPPFLAGS	:= -MMD -MP -I include

SRC_DIR		:= src
BUILD_DIR	:= obj
SRCS		:= \
	dlst/ft_dlstadd_back.c \
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
	to/ft_toupper.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        cleaning command
# CLS       clear the current line
# ECHO      print command and message prefix
# R         set output foreground to red
# G         set output foreground to green
# Y         set output foreground to yellow
# END       reset output foreground color

RM			:= rm -rf
CLS			:= \r\033[K
ECHO		:= echo -n "$(CLS)$(NAME): "
R			:= $(shell tput setaf 1)
G			:= $(shell tput setaf 2)
Y			:= $(shell tput setaf 3)
END			:= $(shell tput sgr0)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       build all targets
# $(NAME)   build $(NAME) target
# clean     remove objects
# fclean    remove objects and binary
# re        remove objects and binary and rebuild all

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@$(ECHO)"$(G)created$(END) $(END)$(NAME)\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p  $(@D) || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@
	@$(ECHO)"$(G)created $(END)$@"

clean:
	@[ -d $(BUILD_DIR) ] \
		&& $(RM) $(BUILD_DIR) \
		&& $(ECHO)"$(R)removed$(END) $(BUILD_DIR)/\n" || true

fclean: clean
	@[ -f "$(NAME)" ] \
		&& $(RM) $(NAME) \
		&& $(ECHO)"$(R)removed$(END) $(NAME)\n" || true

re : fclean all

#------------------------------------------------#
#   CUSTOM RECIPES                               #
#------------------------------------------------#
# sana          memory corruption debugging
# ansi          ANSI Std89 compliance
# every         explore new warnings
# update        update the repository
# norm          42 C coding style compliance
# info          standard build output
# include       include dependency files

.PHONY: sana ansi every update norm info

sana: CC		:= gcc
sana: CFLAGS	+= -g -fsanitize=address,undefined,signed-integer-overflow
sana: $(NAME)

ansi: CFLAGS	+= -W -Wcast-qual -Wcomma -Wconversion -Wsign-conversion -Wwrite-strings -pedantic -std=c89
ansi: $(NAME)

every: CFLAGS	+= -Weverything
every: $(NAME)

update:
	@git pull
	@git submodule update --init
	@$(ECHO)"$(G)updated$(END)\n"

norm:
	@norminette | grep -v "OK" || true
	@$(ECHO)"$(G)checked norm$(END)\n"

info: fclean
	@make --dry-run | grep -v "echo.*\".*\"\|\[.*\]"

-include $(DEPS)
