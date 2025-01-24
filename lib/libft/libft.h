/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:00:08 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 16:13:30 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "get_next_line.h"
# include "ft_printf.h"
# include "ft_strncmp.h"
# define SPACES_CHARS " \t\n\v\f\r"

int			ft_isalpha(int c);

int			ft_isdigit(int c);

int			ft_isnum_lim(char *str, long long max, long long min);

int			ft_isnum(char *str);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isprint(int c);

size_t		ft_strlen(const char *s);

void		*ft_memset(void *b, int c, size_t len);

void		ft_bzero(void *s, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

int			ft_toupper(int c);

int			ft_tolower(int c);

char		*ft_strtolower(char *c);

char		*ft_strchr(const char *s, int c);

char		*ft_strrchr(const char *s, int c);

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

char		*ft_strrstr(const char *haystack, const char *needle);

int			is_allowed_char(char c);

int			ft_atoi(const char *str);

double		ft_atod(char *str);

long		ft_atol(const char *str);

long long	ft_atoll(const char *str);

void		*ft_calloc(size_t count, size_t size);

char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strtrim(char const *s1, char const *set);

char		**ft_split_set(char const *s, char const *set);

char		**ft_split(char const *s, char c);

char		*ft_itoa(int n);

char		*safe_ft_ltoa(long n, void (*f)(char *), char *errmsg);

char		*ft_ltoa(long n);

char		*ft_ultoa(unsigned long n);

char		*ft_dtoa(double n, int precision);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		ft_putchar_fd(char c, int fd);

int			ft_putchar(int fd, const char *c, int *counter);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

void		free_matrix(char **space);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);

void		ft_lstadd_front(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstdelone(t_list *lst, void (*del)(void*));

void		ft_lstclear(t_list **lst, void (*del)(void*));

void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int			ft_putstr(int fd, char *str, int *count);

long		ft_putnbr(int fd, long n, int *count);

int			count_digits(long nbr);

int			count_ull_digits(unsigned long long nbr);

int			count_hex_digits(unsigned int nbr);

char		*ft_filename(char *path);

int			ft_stroccurrences(char *str, char c);

int			ft_stroccurrences_set(char *str, char *set);

int			ft_clamp(int value, int min, int max);

float		ft_fclamp(float value, float min, float max);

double		ft_clampd(double value, double min, double max);

double		ft_overflowd(double value, double min, double max);

long		ft_closest_multiple(long n, long x);

void		ft_matrix_sort(char **matrix);

void		ft_matrix_sort_lc(char **matrix);

long		get_positive_num(int n);

char		*safe_ft_strdup(const char *s1, void (*f)(int));

char		*safe_ft_strjoin(char const *s1, char const *s2,
				void (*f)(char *), char *errmsg);

char		*safe_ft_substr(char const *s, unsigned int start,
				size_t len, void (*f)(int));

char		*safe_ft_strtrim(char const *s1, char const *set, void (*f)(int));

char		**safe_ft_split_set(char const *s, char const *set, void (*f)(int));

char		**safe_ft_split(char const *s, char c, void (*f)(char *),
				char *err_msg);

char		*ft_override_val(char *old, char *new);

int			ft_index(char c, char *str);

void		ft_jump_spaces(char **str);

int			ft_matrix_len(char **matrix);

void		write_str(char *dst, char *src, int	*i);

void		push_char(char	**str, char c, void (*f)(char *), char *msg);

void		push_str(char **s1, char *s2, void (*f)(char *), char *msg);

#endif
