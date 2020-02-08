/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:31:20 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/12 00:29:13 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int					i;
	int					j;
	unsigned char		car;
	unsigned char		*new;
	char				*ret;

	car = (unsigned char)c;
	new = (unsigned char*)s;
	ret = (char*)s;
	i = 0;
	j = -1;
	while (new[i])
	{
		if (new[i] == car)
			j = i;
		i++;
	}
	if (c == '\0')
		return (ret + i);
	if (j != -1)
		return (ret + j);
	return (NULL);
}
