#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define OPEN_MAX 256
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct  s_fdbuf
{
        char    buf[OPEN_MAX+1][BUFFER_SIZE];
        size_t  ind[OPEN_MAX+1];
}       t_fdbuf;

typedef struct	s_var
{
	char	*str;
	size_t	i;
	size_t	m;
}	t_var;

void	ft_bzero(void *, size_t);
size_t	ft_strlen(const char *);
void	*ft_calloc(size_t, size_t);
char	*ft_realloc(char *, size_t);
char	*get_next_line(int);
#endif
