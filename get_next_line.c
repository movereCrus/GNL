#include "get_next_line.h" // gcc -Wall -Wextra -Werror get_next_line.h get_next_line_utils.c get_next_line.c && ./a.out test3.txt test1.txt test4.txt | cat -e

char *ifeol(t_fdbuf *thrd, t_var v, int fd)
{
	char	*tmp;
	//printf("ifeol\n");
	tmp = v.str;
	v.str = ft_strjoin(v.str, thrd->buf[fd], v.i);
	if (*tmp)
		free(tmp);
	if (thrd->buf[fd][v.i + 1])
		thrd->ind[fd] = v.i + 1;
	else
	{
		thrd->ind[fd] = 0;
		*(thrd->buf[fd]) = 0;
	}
	return (v.str);
}

ssize_t ifeof(t_fdbuf *thrd, t_var *v, int fd)
{
	ssize_t	readres;
	char	*tmp;

	//printf("ifeof\n");
	if (v->i)
	{
		if (!v->str)
			v->str = "\0";
		tmp = v->str;
		v->str = ft_strjoin(v->str, thrd->buf[fd], v->i);
		if (*tmp)
			free(tmp);
	}
	*(thrd->buf[fd]) = 0;
	readres = read(fd, thrd->buf[fd], BUFFER_SIZE);
	thrd->ind[fd] = 0;
	return (readres);
}

size_t	bytecalc(int fd, size_t i, t_fdbuf *thrd)
{
	i = thrd->ind[fd];
	while (thrd->buf[fd][i] != '\n' && thrd->buf[fd][i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static t_fdbuf	thrd;
	t_var			var;
	ssize_t			readres;

	var.str = NULL;
	while (fd >= 0 && fd <= OPEN_MAX)
	{
		var.i = bytecalc(fd, var.i, &thrd);
		if (thrd.buf[fd][var.i] == '\n')
		{
			var.str = ifeol(&thrd, var, fd);
			if (!var.str)
				return (NULL);
			fd = -1;
		}
		else
		{
			readres = ifeof(&thrd, &var, fd);
			if (readres <= 0)
				fd = -1;
		}
	}
	return(var.str);
}
/*
int main()
{
	int fd = 0;
	char *str = NULL;
	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	close(fd);
}*/
