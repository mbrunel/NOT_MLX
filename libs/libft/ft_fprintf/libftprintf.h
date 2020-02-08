/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 07:49:31 by mbrunel           #+#    #+#             */
/*   Updated: 2019/12/19 00:06:25 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libc/libft.h"
# include "stdarg.h"

typedef struct		s_incs
{
	int				i;
	int				j;
	int				tot;
}					t_incs;
typedef struct		s_param
{
	int				att;
	int				arr;
	int				aim;
}					t_param;

int					ft_fprintf(int fd, const char *str, ...);
int					matrix(const char *str, va_list ap, t_incs *sizes, int fd);
t_param				*srch_flags(const char *src, int len, va_list ap);
int					printpercent(char *str, t_param *p, int len, int fd);
int					print_str(char *new, t_param *p, int len, int fd);
int					print_dig(char *new, t_param *p, int len, int fd);
char				*add(char *str, int fix, char att, char c);
char				*del(char *str, int size);
void				checkzero(char *str, t_param *p);
int					endclean(void *ptr1, void *ptr2, int rt);
char				*att(char *str, t_param *p);
char				*width(char *str, t_param *p);
char				*aim(char *str, t_param *p);
void				*clear(void *ptr1, void *ptr2, void *ptr3, void *ptr4);
void				setflags(char *(**flag)(char *str, t_param *p));
int					chr(const char *str, char c);
void				setf(char *(**f)(va_list ap));
char				*cconv(va_list ap);
char				*sconv(va_list ap);
char				*diconv(va_list ap);
char				*uconv(va_list ap);
char				*pconv(va_list ap);
char				*xconv(va_list ap);
char				*grandxconv(va_list ap);
char				*noconv(va_list ap);
void				hexcurse(size_t addr, int i, char *str);
void				grandhexcurse(size_t addr, int i, char *str);
void				deathcurse(size_t nb, int i, char *str);
char				*revdup(const char *str);

#endif
