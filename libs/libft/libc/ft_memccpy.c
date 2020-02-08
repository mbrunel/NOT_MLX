/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:35:07 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 22:21:41 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
		if (d[i - 1] == (unsigned char)c)
			break ;
	}
	if (i > 0 && d[i - 1] == (unsigned char)c)
		return (dest + i);
	return (NULL);
}
