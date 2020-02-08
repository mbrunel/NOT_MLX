/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:30:33 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 19:48:25 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*curse(int n, char *str, int i)
{
	char u;

	if (n > 9 || n < -9)
	{
		u = n > 0 ? n % 10 + '0' : -n % 10 + '0';
		n /= 10;
		curse(n, str, i - 1);
	}
	else
		u = n > 0 ? n + '0' : -n + '0';
	str[i] = u;
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		cp;
	int		len;

	cp = n;
	len = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		len++;
	while (cp > 9 || cp < -9)
	{
		cp /= 10;
		len++;
	}
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	return (curse(n, str, len - 1));
}
