/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:10:54 by cpollito          #+#    #+#             */
/*   Updated: 2021/12/15 22:27:16 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_memmove_gnl(char *dst, char *src, size_t n);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_strjoin_gnl(const char *s1, char const *s2, int len);
int		ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen(const char *str);
#endif