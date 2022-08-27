# @author   cvidon@42
# @brief    Makefile for C programs compiling with a library.

NAME		= liebeft
LIBFT		= ..

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -Wconversion

CPPFLAGS	= -I . -I $(LIBFT)/include
LDFLAGS		=      -L $(LIBFT)
LDLIBS		=      -l ft

SRCS		= liebeft.c
OBJS		:= $(SRCS:%.c=%.o)

RM			= rm -rf
MAKE		= make -C
MUTE		= 1>/dev/null 2>/dev/null

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "\r>>> SUCCESS <<<     "

%.o: %.c
	@echo -n "Building $(NAME)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(MAKE) $(LIBFT) $(MUTE)

clean:
	@$(MAKE) $(LIBFT) clean $(MUTE)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) $(LIBFT) fclean $(MUTE)
	@$(RM) $(NAME)

re: fclean all

update:
	@git pull
	@git submodule update --init

san_thread: CC := gcc
san_thread: CFLAGS := $(CFLAGS) -g -fsanitize=thread,undefined,signed-integer-overflow
san_thread: $(NAME)

malloc_test: $(OBJS)
	@clang -Wall -Wextra -Werror -g -fsanitize=undefined -rdynamic -o $@ $(OBJS) \
		-Lft_mallocator -lmallocator

.PHONY: all clean fclean re update malloc_test
