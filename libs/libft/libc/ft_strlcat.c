/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 07:26:30 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/22 10:16:48 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t ld;
	size_t ls;

	ls = ft_strlen(src);
	i = 0;
	if ((ld = ft_strlen(dest)) >= size)
		return (size + ls);
	if (size > ld + ls)
	{
		while (src[i])
		{
			dest[ld + i] = src[i];
			i++;
		}
		dest[ld + ls] = '\0';
		return (ld + ls);
	}
	while (size > ld + i + 1)
	{
		dest[ld + i] = src[i];
		i++;
	}
	dest[size - 1] = '\0';
	return (ld + ls);
}
