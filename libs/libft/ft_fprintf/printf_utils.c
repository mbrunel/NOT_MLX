/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:29:24 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/31 18:00:17 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	setf(char *(**f)(va_list ap))
{
	(f[0]) = &cconv;
	(f[1]) = &sconv;
	(f[2]) = &noconv;
	(f[3]) = &pconv;
	(f[4]) = &diconv;
	(f[5]) = &diconv;
	(f[6]) = &uconv;
	(f[7]) = &xconv;
	(f[8]) = &grandxconv;
}

int		chr(const char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

void	*clear(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	free(ptr1);
	free(ptr2);
	free(ptr3);
	return (ptr4);
}

void	setflags(char *(**flags)(char *str, t_param *p))
{
	flags[0] = &att;
	flags[1] = &width;
	flags[2] = &aim;
}
