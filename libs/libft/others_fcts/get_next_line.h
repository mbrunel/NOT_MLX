/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:04:39 by mbrunel           #+#    #+#             */
/*   Updated: 2019/12/14 13:47:54 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int					get_next_line(int fd, char **line);
char				*ft_strjoi(char *s1, char const *s2);
void				ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *str);
int					check(const char *buff);
int					clean(char **buf, int rt);
void				ft_bzero(void *s, size_t n);

#endif
