# @author   cvidon@42
# @brief    Simple Makefile for C lib tester.

NAME		= liebeft
LIBFT		= ..

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I . -I $(LIBFT)/include
LDFLAGS		=      -L $(LIBFT)
LDLIBS		=      -l ft
SRCS		= liebeft.c
OBJS		:= $(SRCS:%.c=%.o)

VALGRIND	= valgrind -q --leak-check=yes --show-leak-kinds=all
MAKE		= make -C
RULE		= all
MUTE		= 1>/dev/null 2>/dev/null
CLS			= \r\033[K
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(CLS)>>> SUCCESS <<<"

%.o: %.c
	@echo -n "Building $(NAME)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(MAKE) $(LIBFT) $(RULE) $(MUTE)

clean:
	@$(MAKE) $(LIBFT) clean $(MUTE)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) $(LIBFT) fclean $(MUTE)
	@$(RM) $(NAME)

re: fclean all

san_addr: CC 		:= gcc
san_addr: RULE 		:= san_addr
san_addr: CFLAGS 	:= $(CFLAGS) -g -fsanitize=address,undefined,signed-integer-overflow
san_addr: $(NAME)

scream: CFLAGS		:= $(CFLAGS) -Wconversion -Wsign-conversion -Wwrite-strings -Wcast-qual -Wcomma -pedantic -std=c89
scream: RULE 		:= scream
scream: $(NAME)

cry: CFLAGS			:= $(CFLAGS) -Weverything
cry: RULE			:= cry
cry: $(NAME)

run: re
	@$(VALGRIND) ./$(NAME) || true

.PHONY: all clean fclean re san_addr scream cry run
