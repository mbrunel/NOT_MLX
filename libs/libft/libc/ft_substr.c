/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:50:55 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 19:47:02 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	beg;
	size_t	i;

	beg = (size_t)start;
	i = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (ft_strlen(s) < beg)
	{
		str[0] = '\0';
		return (str);
	}
	while (s[i + beg] && i < len)
	{
		str[i] = s[i + beg];
		i++;
	}
	str[i] = '\0';
	return (str);
}
