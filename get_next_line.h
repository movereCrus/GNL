/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:30:37 by kirus             #+#    #+#             */
/*   Updated: 2021/12/28 00:38:10 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_fdbuf
{
	char	buf[BUFFER_SIZE];
	size_t	ind;
}	t_fdbuf;

typedef struct s_var
{
	char	*str;
	size_t	i;
}	t_var;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_n(char const *s1, char const *s2, size_t len);
char	*get_next_line(int fd);
#endif
