/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:34:00 by mbrunel           #+#    #+#             */
/*   Updated: 2019/12/11 22:48:03 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*att(char *str, t_param *p)
{
	char	*new;
	int		i;

	i = 0;
	p->att = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			p->att = '-';
		else if (p->att == 0)
			p->att = '0';
		i++;
	}
	if (!(new = ft_strdup(str + i)))
		return ((char*)clear(str, NULL, NULL, NULL));
	return ((char*)clear(str, NULL, NULL, new));
}

char				*width(char *str, t_param *p)
{
	char	*new;
	int		i;

	i = 0;
	p->arr = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' || str[i] == '\0')
	{
		p->arr = ft_atoi(str);
		if (!(new = ft_strdup(str + i)))
			return ((char*)clear(str, NULL, NULL, NULL));
		return ((char*)clear(str, NULL, NULL, new));
	}
	return ((char*)clear(str, NULL, NULL, NULL));
}

char				*aim(char *str, t_param *p)
{
	char	*new;
	int		i;

	i = 0;
	p->aim = -1;
	if (*str == '.')
	{
		i++;
		p->aim = ft_atoi(str + i);
		if (str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] != '\0')
			return ((char*)clear(str, NULL, NULL, NULL));
		if (!(new = ft_strdup("")))
			return ((char*)clear(str, NULL, NULL, NULL));
		return ((char*)clear(str, NULL, NULL, new));
	}
	else if (str[i] == '\0')
		return (str);
	return ((char*)clear(str, NULL, NULL, NULL));
}
