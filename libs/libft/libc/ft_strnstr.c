/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:50:39 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/26 02:44:11 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*check(const char *big, const char *little)
{
	size_t i;

	if (little[0])
		return (NULL);
	i = ft_strlen(big);
	return ((char*)(big + i));
}

char				*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (check(big, little))
		return ((char*)big);
	while (big[i] && i < len)
	{
		if (big[i] == (little[0]))
		{
			while (big[i] && (i + j) < len && little[j] &&
			little[j] == big[i + j])
				j++;
			if (little[j] == '\0')
				return ((char*)(big + i));
			if (big[j + i] == '\0')
				return (NULL);
			if (i + j >= len)
				return (NULL);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
