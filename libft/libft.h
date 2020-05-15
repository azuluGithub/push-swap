#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

# define BUFF_SIZE 42

void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcat(char *s1, const char *s2);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dst, const char *src);
void		ft_bzero(void *s, int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int n);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putstr(char const *str);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);
char		**ft_strsplit(char const *s, char c);
void		*ft_memalloc(size_t x);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			ft_strlen(const char *s);
char		*ft_strnew(size_t size);
int			get_next_line(int const fd, char **line);

#endif