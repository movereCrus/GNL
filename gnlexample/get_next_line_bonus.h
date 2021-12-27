/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:10:54 by cpollito          #+#    #+#             */
/*   Updated: 2021/12/15 22:30:11 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 1
# define OPEN_MAX 256

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_memmove_gnl(char *dst, char *src, size_t n);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_strjoin_gnl(const char *s1, char const *s2, int len);
int		ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen(const char *str);
#endif