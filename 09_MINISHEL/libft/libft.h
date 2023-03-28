/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:42:40 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/18 19:23:02 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <assert.h>
# include <ctype.h>
# include <stdbool.h>
# include <stdint.h>
# include <assert.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <bsd/string.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_gnl
{
	char		*buf;
	char		*line;
	int			r_read;
}	t_gnl;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int find_char);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ********** ft_printf ********** */
void	ft_putcharprintf(int c, unsigned int *count);
void	ft_putstrprintf(char *c, unsigned int *count);
void	ft_putnbrprintf(int nb, unsigned int *count);
void	ft_putunbrprintf(unsigned int nb, unsigned int *count);
void	ft_puthex(unsigned int nb, unsigned int *count);
void	ft_puthexmaj(unsigned int nb, unsigned int *count);
void	ft_putmem(void *nb, unsigned int *count);
int		ft_strlenprintf(char *c);
void	ft_flags(const char format, va_list args, unsigned int *count);
int		ft_printf(const char *format, ...);

/* ********** get_next_line ********** */
int		ft_findnl(char *stash);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
char	*ft_strdup_gnl(char *s);
char	*get_next_line(int fd, int boolean);

/* ***** new functions ***** */
void	ft_swap(int *a, int *b);
int		ft_freetab(char **tab, int boolean);
long	ft_atol(const char *nptr);
int		ft_checkargs(int ac, char **av);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);

#endif
