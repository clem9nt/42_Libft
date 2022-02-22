# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvidon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 16:21:48 by cvidon            #+#    #+#              #
#    Updated: 2022/02/22 16:24:34 by cvidon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== [ Project files ]
#
# TODO add obj/ and find a way to copy the src dir tree into it.
#
# Adjust NAME and SRC to your project.

NAME		= libft
TARGET 		= $(NAME).a

INC_DIR 	= include
INC			= $(INC_DIR)

SRC_DIR		= src
SRC 		= $(SRC_DIR)/all/ft_atoi.c 					\
			  $(SRC_DIR)/all/ft_bzero.c 				\
			  $(SRC_DIR)/all/ft_calloc.c 				\
			  $(SRC_DIR)/all/ft_isalnum.c 				\
			  $(SRC_DIR)/all/ft_isalpha.c 				\
			  $(SRC_DIR)/all/ft_isascii.c 				\
			  $(SRC_DIR)/all/ft_isdigit.c 				\
			  $(SRC_DIR)/all/ft_isprint.c 				\
			  $(SRC_DIR)/all/ft_memchr.c 				\
			  $(SRC_DIR)/all/ft_memcmp.c 				\
			  $(SRC_DIR)/all/ft_memcpy.c 				\
			  $(SRC_DIR)/all/ft_memmove.c 				\
			  $(SRC_DIR)/all/ft_memset.c 				\
			  $(SRC_DIR)/all/ft_strchr.c 				\
			  $(SRC_DIR)/all/ft_strlcat.c 				\
			  $(SRC_DIR)/all/ft_strlcpy.c 				\
			  $(SRC_DIR)/all/ft_strlen.c 				\
			  $(SRC_DIR)/all/ft_strncmp.c 				\
			  $(SRC_DIR)/all/ft_strnstr.c 				\
			  $(SRC_DIR)/all/ft_strrchr.c 				\
			  $(SRC_DIR)/all/ft_tolower.c 				\
			  $(SRC_DIR)/all/ft_toupper.c 				\
			  $(SRC_DIR)/all/ft_strdup.c 				\
			  $(SRC_DIR)/all/ft_substr.c 				\
			  $(SRC_DIR)/all/ft_strjoin.c 				\
			  $(SRC_DIR)/all/ft_strtrim.c 				\
			  $(SRC_DIR)/all/ft_split.c 				\
			  $(SRC_DIR)/all/ft_itoa.c 					\
			  $(SRC_DIR)/all/ft_strmapi.c 				\
			  $(SRC_DIR)/all/ft_striteri.c 				\
			  $(SRC_DIR)/all/ft_putchar_fd.c 			\
			  $(SRC_DIR)/all/ft_putstr_fd.c 			\
			  $(SRC_DIR)/all/ft_putendl_fd.c			\
			  $(SRC_DIR)/all/ft_putnbr_fd.c
SRC		   += $(SRC_DIR)/linked_list/ft_lstnew.c 		\
			  $(SRC_DIR)/linked_list/ft_lstadd_front.c	\
			  $(SRC_DIR)/linked_list/ft_lstsize.c 		\
			  $(SRC_DIR)/linked_list/ft_lstlast.c 		\
			  $(SRC_DIR)/linked_list/ft_lstadd_back.c 	\
			  $(SRC_DIR)/linked_list/ft_lstdelone.c 	\
			  $(SRC_DIR)/linked_list/ft_lstclear.c 		\
			  $(SRC_DIR)/linked_list/ft_lstiter.c 		\
			  $(SRC_DIR)/linked_list/ft_lstmap.c
SRC		   += $(SRC_DIR)/ft_printf/ft_printf.c 			\
			  $(SRC_DIR)/ft_printf/options1.c 			\
			  $(SRC_DIR)/ft_printf/options2.c 			\
			  $(SRC_DIR)/ft_printf/utils.c
SRC		   += $(SRC_DIR)/get_next_line/get_next_line.c
SRC		   += $(SRC_DIR)/extra/ft_min.c 				\
			  $(SRC_DIR)/extra/ft_max.c 				\
			  $(SRC_DIR)/extra/ft_abs.c

OBJ 		= $(SRC:.c=.o)

# ========== [ Compiler flags ]

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -Wconversion -Wsign-conversion
CPPFLAGS	= $(INC:%=-I%)

# ========== [ Misc ]

RM 			= rm -f

# ========== [ Build ]

all: $(TARGET)

debug: TARGET := $(TARGET)-debug
debug: $(TARGET)

sanitizer: CFLAGS += -fsanitize=address,undefined,signed-integer-overflow
sanitizer: debug

$(TARGET): $(OBJ)
	@ar rcs $(TARGET) $(OBJ)
	@$(ECHO)"$(G)created$(END) $(END)$(TARGET)\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(ECHO)"$(W)$@$(END)"

clean:
	@test "$(shell ls $(SRC_DIR)/*/*.o 2>/dev/null | wc -w)" = "$(shell echo 0)" \
		|| { $(RM) $(OBJ); $(ECHO)"$(R)removed$(END) obj\n"; }

fclean: clean
	@[ -f "$(TARGET)" ] && $(RM) $(TARGET) && $(ECHO)"$(R)removed$(END) $(TARGET)\n" || true

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) sources\n"
	@norminette -R CheckDefine $(INC_DIR) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) headers\n"

update:
	@git pull
	@$(ECHO)"$(G)updated$(END)\n"

re: fclean all

.PHONY: all debug clean fclean norm update re

# ========== [ Stdout ]

R		= $(shell tput setaf 1)
G		= $(shell tput setaf 2)
Y		= $(shell tput setaf 3)
B		= $(shell tput setaf 4)
M		= $(shell tput setaf 5)
C		= $(shell tput setaf 6)
W		= $(shell tput setaf 7)
K		= $(shell tput setaf 8)
END		= $(shell tput sgr0)
ECHO  	= echo -n "\r\033[K$(NAME): "
