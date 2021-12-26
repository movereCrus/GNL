#include "get_next_line_bonus.h" // gcc -Wall -Wextra -Werror get_next_line.h get_next_line_utils.c get_next_line.c && ./a.out test3.txt test1.txt test4.txt | cat -e

char *ifeol(t_fdbuf *thrd, t_var v, int fd)
{
	char	*tmp;
	//printf("ifeol ind:%lu\n|", thrd->ind[fd]);
	if (!v.str)
	{
		v.str = "\0";
	}
	tmp = v.str;
	//printf("tmp1 ifeol:%s", tmp);
	v.str = ft_strjoin_n(v.str, &thrd->buf[fd][thrd->ind[fd]], v.i);
	//printf("tmp2 ifeol:%s", tmp);
	if (*tmp)
		free(tmp);
	if (thrd->buf[fd][v.i + 1])
		thrd->ind[fd] = v.i + 1;
	else
	{
		//printf("buf clearing\n");
		thrd->ind[fd] = 0;
		*(thrd->buf[fd]) = 0;
	}
	return (v.str);
}

ssize_t ifeof(t_fdbuf *thrd, t_var *v, int fd)
{
	ssize_t	readres;
	char	*tmp;

	//printf("ifeof ind:%lu\n|", thrd->ind[fd]);
	if (v->i)
	{
		if (!v->str)
		{
			v->str = "\0";
			//printf("str = \\0\n");
		}
		tmp = v->str;
		//printf("tmp1 ifeof:%s", tmp);
		v->str = ft_strjoin(v->str, &thrd->buf[fd][thrd->ind[fd]]);
		//printf("tmp2 ifeof:%s", tmp);
		if (*tmp)
			free(tmp);
	}
	*(thrd->buf[fd]) = 0;
	readres = read(fd, thrd->buf[fd], BUFFER_SIZE);
	thrd->buf[fd][readres] = '\0';
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
int main(int argc, char **argv)
{
	(void) argc;
	(void) **argv;
	int		fd[3];
	char	*str;

	fd[0] = open(argv[1], O_RDONLY); //gcc -Wall -Wextra -Werror get_next_line.c -g -fsanitize=address -o get_next_line && ./get_next_line test1.txt test4.txt test3.txt | cat -e
	//fd[1] = open(argv[2], O_RDONLY);
	//fd[2] = open(argv[3], O_RDONLY);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[1]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[1]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[2]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[2]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[1]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[2]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[0]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[2]);
	printf("Str:%s", str);
	free(str);
	str = get_next_line(fd[1]);
	printf("Str:%s", str);
	free(str);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}*/