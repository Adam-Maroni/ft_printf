/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:58:55 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/23 10:48:53 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, int n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, void *src, int n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, void *src, size_t n);
void				*ft_memchr(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_memcmp(void *s1, void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_atoi(char *nptr);
int					ft_lstsize(t_list *lst);
int					ft_putchar_ret(char c);
int					ft_isspace(int c);
int					ft_issign(char c);
int					ft_putstr_ret(const char *string);
char				*ft_strchr(char *s, int c);
char				*ft_strrchr(char *s, int c);
char				*ft_strnstr(const char *big,
		const char *little, size_t len);
char				*ft_strdup(char *s);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s1, char *set);
char				**ft_split(char *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
char				*ft_uitoa(unsigned int n);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f) (void *),
		void (*del)(void *));
unsigned long		ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
size_t				ft_strlcat(char *dst, char *src, size_t size);
#endif
