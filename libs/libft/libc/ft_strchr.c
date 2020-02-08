/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:28:00 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/11 01:24:10 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	car;
	unsigned char	*new;
	char			*ret;

	i = 0;
	car = (unsigned char)c;
	new = (unsigned char*)s;
	while (new[i] && new[i] != car)
		i++;
	if (new[i] == car)
	{
		ret = (char*)new;
		return (ret + i);
	}
	return (NULL);
}
