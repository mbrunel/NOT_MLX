/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 20:19:12 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/31 18:02:28 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			hexcurse(size_t addr, int i, char *str)
{
	char *base;

	base = "0123456789abcdef";
	if (addr > 15)
	{
		hexcurse(addr / 16, i + 1, str);
		str[i] = base[addr % 16];
	}
	else
	{
		str[i] = base[addr];
		str[i + 1] = '\0';
	}
}

void			grandhexcurse(size_t addr, int i, char *str)
{
	char *base;

	base = "0123456789ABCDEF";
	if (addr > 15)
	{
		str[i] = base[addr % 16];
		grandhexcurse(addr / 16, i + 1, str);
	}
	else
	{
		str[i] = base[addr];
		str[i + 1] = '\0';
	}
}

void			deathcurse(size_t nb, int i, char *str)
{
	char *base;

	base = "0123456789";
	if (nb > 9)
	{
		deathcurse(nb / 10, i + 1, str);
		str[i] = base[nb % 10];
	}
	else
	{
		str[i] = base[nb];
		str[i + 1] = '\0';
	}
}

char			*revdup(const char *str)
{
	char	*new;
	int		i;

	i = ft_strlen(str);
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	new[i] = '\0';
	while (*str)
		new[--i] = *(str++);
	return (new);
}
