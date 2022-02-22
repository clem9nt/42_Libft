# ========== [ Project files ]
#
# Adjust NAME and SRCS to your project.

NAME		= libft
TARGET 		= $(NAME).a

INC_DIR 	= include
INC			= $(INC_DIR)

SRC_DIR		= src
SRCS 		= $(SRC_DIR)/all/ft_atoi.c 					\
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
			  $(SRC_DIR)/all/ft_putnbr_fd.c				\
			  $(SRC_DIR)/linked_list/ft_lstnew.c 		\
			  $(SRC_DIR)/linked_list/ft_lstadd_front.c	\
			  $(SRC_DIR)/linked_list/ft_lstsize.c 		\
			  $(SRC_DIR)/linked_list/ft_lstlast.c 		\
			  $(SRC_DIR)/linked_list/ft_lstadd_back.c 	\
			  $(SRC_DIR)/linked_list/ft_lstdelone.c 	\
			  $(SRC_DIR)/linked_list/ft_lstclear.c		\
			  $(SRC_DIR)/linked_list/ft_lstiter.c 		\
			  $(SRC_DIR)/linked_list/ft_lstmap.c		\
			  $(SRC_DIR)/ft_printf/ft_printf.c 			\
			  $(SRC_DIR)/ft_printf/options1.c 			\
			  $(SRC_DIR)/ft_printf/options2.c 			\
			  $(SRC_DIR)/ft_printf/utils.c				\
			  $(SRC_DIR)/get_next_line/get_next_line.c	\
			  $(SRC_DIR)/extra/ft_min.c 				\
			  $(SRC_DIR)/extra/ft_max.c 				\
			  $(SRC_DIR)/extra/ft_abs.c

OBJ_DIR 	= obj
OBJS 		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ========== [ Compiler flags ]

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -Wconversion -Wsign-conversion
CPPFLAGS	= $(INC:%=-I%)

# ========== [ Misc ]

RM 			= rm -rf

# ========== [ Recipe ]

all: $(TARGET)

sanitizer: CFLAGS += -fsanitize=address,undefined,signed-integer-overflow
sanitizer: $(TARGET)

$(TARGET): $(OBJS)
	@ar rcs $(TARGET) $(OBJS)
	@$(ECHO)"$(G)created$(END) $(END)$(TARGET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p  $(@D) || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(ECHO)"$(G)created $(END)$@"

clean:
	@[ -d $(OBJ_DIR) ] \
		&& $(RM) $(OBJ_DIR) && $(ECHO)"$(R)removed$(END) $(OBJ_DIR)/\n" || true

fclean: clean
	@[ -f "$(TARGET)" ] && $(RM) $(TARGET) && $(ECHO)"$(R)removed$(END) $(TARGET)\n" || true

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) sources\n"
	@norminette -R CheckDefine $(INC_DIR) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) headers\n"

update:
	@git pull
	@$(ECHO)"$(G)updated$(END)\n"

re: fclean all

.PHONY: all clean fclean norm update re

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
