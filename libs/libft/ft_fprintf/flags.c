/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:36:02 by mbrunel           #+#    #+#             */
/*   Updated: 2019/12/11 22:50:03 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*create(char *str, va_list ap, int i)
{
	char *tmp1;
	char *tmp2;
	char *integer;

	str[i] = '\0';
	if (!(integer = ft_itoa(va_arg(ap, int))))
		return (NULL);
	if (!(tmp1 = ft_strjoin(str, integer)))
		return (clear(str, integer, NULL, NULL));
	if (!(tmp2 = ft_strdup(str + i + 1)))
		return (clear(tmp1, integer, NULL, NULL));
	free(str);
	if (!(str = ft_strjoin(tmp1, tmp2)))
		return (clear(tmp1, tmp2, integer, NULL));
	return (clear(integer, tmp1, tmp2, str));
}

static char		*assvals(const char *src, int len, va_list ap)
{
	int		i;
	int		count;
	char	*str;

	i = -1;
	count = 0;
	if (!(str = ft_substr(src, 1, len)))
		return (NULL);
	while (str[++i] && count <= 2)
		if (str[i] == '*')
		{
			if (!(str = create(str, ap, i)))
				return (NULL);
			count++;
			i = -1;
		}
	return (count < 3 ? str : clear(NULL, str, NULL, NULL));
}

t_param			*srch_flags(const char *src, int len, va_list ap)
{
	char		*str;
	t_param		*p;
	int			i;
	char		*(*flags[3])(char *str, t_param *p);

	if (!(p = malloc(sizeof(t_param))))
		return (NULL);
	if (!(str = (char*)assvals(src, len, ap)))
		return (clear(p, NULL, NULL, NULL));
	i = -1;
	setflags(flags);
	while (++i < 3)
		if (!(str = (*flags[i])(str, p)))
			return (clear(str, p, NULL, NULL));
	return (*str ? clear(str, p, NULL, NULL) :\
	clear(str, NULL, NULL, (t_param*)p));
}
