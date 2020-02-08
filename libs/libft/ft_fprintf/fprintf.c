/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 09:13:12 by mbrunel           #+#    #+#             */
/*   Updated: 2019/12/18 23:59:30 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_fprintf(int fd, const char *str, ...)
{
	va_list		ap;
	t_incs		sizes[1];

	va_start(ap, str);
	sizes->i = 0;
	sizes->tot = 0;
	while (str[sizes->i])
	{
		if (str[sizes->i] != '%')
		{
			write(fd, str + sizes->i, 1);
			sizes->tot++;
		}
		else
		{
			if ((matrix(str, ap, sizes, fd)) == -1)
				return (-1);
		}
		sizes->i++;
	}
	va_end(ap);
	return (sizes->tot);
}
