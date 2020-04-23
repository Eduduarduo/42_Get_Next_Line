#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define FD_SIZE 4096

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
//# include "../../LIBFT/libft.h"

int		get_next_line(const int fd, char **line);

//Todas as funções abaixo são da LIBFT + algumas adicionais
void	ft_memdel(void **ap);

void	ft_strdel(char **as);

char	*ft_strsub(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

char	*ft_strnew(size_t size);

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strcat(char *dst, const char *src);

#endif