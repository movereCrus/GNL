#include "get_next_line_bonus.h" // gcc -Wall -Wextra -Werror get_next_line.h get_next_line_utils.c get_next_line.c && ./a.out test3.txt test1.txt test4.txt | cat -e

char	*ft_buftosrc(char *dest, char *src, char *bgn)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = BUFFER_SIZE;
	if (dest == src)
		return (dest);
	while (dest[i])
		i++;
	b = b - (src - bgn);
	while (b != 0)
	{
		dest[i] = *src;
		i++;
		if (*src == '\n' || *(src + 1) == '\0')
			break;
		src++;
		b--;
	}
	dest[i] = '\0';
	return (dest);
}

char *ifeol(t_fdbuf *thrd, t_var v, int fd)
{
	if (!v.str)
		v.str = (char *)ft_calloc(v.i + 2, sizeof(char));
	else if (v.m < ft_strlen(v.str) + v.i + 2)
		v.str = ft_realloc(v.str, v.m * 2);
	if (!v.str)
		return (NULL);
	v.str = ft_buftosrc(v.str, &thrd->buf[fd][thrd->ind[fd]], &thrd->buf[fd][0]);
	if (thrd->buf[fd][v.i + 1])
		thrd->ind[fd] = v.i + 1;
	else
	{
		thrd->ind[fd] = 0;
		ft_bzero(thrd->buf[fd], BUFFER_SIZE);
		//read(fd, thrd->buf[fd], BUFFER_SIZE);
	}
	//printf("ifeol buf[0]:%c\n", thrd->buf[fd][0]);
	return (v.str);
}

ssize_t ifeof(t_fdbuf *thrd, t_var *v, int fd)
{
	ssize_t	readres;

	if (v->i)
	{
		if (!v->str)
		{
			v->m = BUFFER_SIZE + 1;
			v->str = (char *)ft_calloc(v->m, sizeof(char));
		}
		else if (v->m < ft_strlen(v->str) + v->i + 1)
		{
			v->m = v->m * 2;
			v->str = ft_realloc(v->str, v->m);
		}
		if (!v->str)
			return (0);
		v->str = ft_buftosrc(v->str, &thrd->buf[fd][thrd->ind[fd]], &thrd->buf[fd][0]);
	}
	ft_bzero(thrd->buf[fd], BUFFER_SIZE);
	readres = read(fd, thrd->buf[fd], BUFFER_SIZE);
	//printf("ifeof buf[0]:%c readres:%ld i:%lu\n", thrd->buf[fd][0], readres, v->i);
	thrd->ind[fd] = 0;
	return (readres);
}

size_t	bytecalc(int fd, size_t i, t_fdbuf *thrd)
{
	i = thrd->ind[fd];
	while (thrd->buf[fd][i] != '\n' && thrd->buf[fd][i])
		i++;
	/*if (!thrd->buf[fd][i])
		i = 0;*/
	return (i);
}

char	*get_next_line(int fd)
{
	static t_fdbuf	thrd;
	t_var			var;
	ssize_t			readres;

	var.str = NULL;
	var.m = 0;
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

	fd[0] = open("42_with_nl", O_RDONLY); //gcc -Wall -Wextra -Werror get_next_line.c -g -fsanitize=address -o get_next_line && ./get_next_line test1.txt test4.txt test3.txt | cat -e
	//fd[1] = open(argv[2], O_RDONLY);
	//fd[2] = open(argv[3], O_RDONLY);
	//str = get_next_line(20);
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
	free(str);*/
	/*while (1)
	{
		str = get_next_line(fd);
		printf("Str:%s", str);
		free(str);
		if (!str)
			break;
	}
	close(fd);*/
	//close(fd[0]);
	/*close(fd[1]);
	close(fd[2]);*/
//}
