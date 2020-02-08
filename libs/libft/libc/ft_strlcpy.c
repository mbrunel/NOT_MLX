/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 23:56:19 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/22 10:16:47 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t ld;
	size_t ls;
	size_t i;

	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	i = 0;
	if (size > ls)
		size = ls + 1;
	if (size == 0)
		return (ls);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[size - 1] = '\0';
	return (ls);
}
