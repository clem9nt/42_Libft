/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:50:48 by cvidon            #+#    #+#             */
/*   Updated: 2022/05/16 11:34:04 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
 ** =========[ Includes ]==========
 */

# include <unistd.h>
# include <stdlib.h>

# include <stdarg.h>
# include <limits.h>

# include <stdio.h>

/*
 ** =========[ Defines ]===========
 */

/*
 ** [ GET NEXT LINE ]
 **
 ** TODO get_next_line.h
 */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

/*
 ** =========[ Structures ]========
 */

/*
 ** [ DOUBLE LINKED LIST ]
 */

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

/*
 ** [ LINKED LIST ]
 */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
 ** =========[ Prototypes ]========
 */

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strchr(char const *s, int c);
char	*ft_strdup(char const *s1);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free_s1(char *s1, char const *s2);
char	*ft_strjoin_free_s2(char const *s1, char *s2);
char	*ft_strjoin_free(char *s1, char *s2);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);
char	*ft_strrchr(char const *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(char const *str);
long	ft_atol(char const *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strcmp(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, char const *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t	ft_strlen(char const *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/*
 ** [ DOUBLE LINKED LIST ]
 */

int		ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *));
t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstclear(t_dlist **lst, void (*del)(void *));
void	ft_dlstdelfirst(t_dlist **lst, void (*del)(void *));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void	ft_dlstiter(t_dlist *lst, void (*f)(void *));

/*
 ** [ LINKED LIST ]
 */

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelfirst(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
 ** [ FT_PRINTF ]
 */

/* utils.c */
void	ft_putnbr_base(long nb, int baselen, char *base, int *ret);
void	ft_putnbr_base_ptr(unsigned long nb, int baselen, char *base, int *ret);
/* options1.c */
int		ft_pct(va_list args);
int		ft_chr(va_list args);
int		ft_str(va_list args);
int		ft_nbr(va_list args);
/* options2.c */
int		ft_uns(va_list args);
int		ft_hx1(va_list args);
int		ft_hx2(va_list args);
int		ft_ptr(va_list args);
/* ft_printf.c */
int		ft_printf(char const *fmt, ...);

/*
 ** [ GET_NEXT_LINE ]
 **
 ** TODO ft_strjoin_free_s1, ft_strjoin_free_s2 and ft_strjoin_free
 ** use -> _s1 instead _gnl
 */

char	*get_next_line(int fd);

/*
 ** [ EXTRA ]
 */

int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int nb);

#endif
