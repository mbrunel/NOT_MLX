/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:21:28 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 19:32:52 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		car;

	i = 0;
	car = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n && str[i] != car && str[i])
		i++;
	if (str[i] == car && i != n)
		return ((void*)(str + i));
	return (NULL);
}
