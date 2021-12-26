#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 1
# define OPEN_MAX 256
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
typedef struct  s_fdbuf
{
        char    buf[OPEN_MAX+1][BUFFER_SIZE];
        size_t  ind[OPEN_MAX+1];
}       t_fdbuf;

typedef struct	s_var
{
	char	*str;
	size_t	i;
}	t_var;

size_t	ft_strlen(const char *);
char	*ft_strjoin(char const *, char const *, size_t);
char	*get_next_line(int);
#endif
