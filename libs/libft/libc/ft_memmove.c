/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:42:21 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 21:58:02 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	i = 0;
	if (dest == src)
		return (dest);
	if (dest < src)
		while (n-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (n-- > 0)
			d[n] = s[n];
	return (dest);
}
