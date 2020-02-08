/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconvs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:39:47 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/31 17:23:59 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*cconv(va_list ap)
{
	char	str[2];
	char	*new;

	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return ((new = ft_strdup(str)) ? new : NULL);
}

char		*sconv(va_list ap)
{
	char *str;
	char *new;

	if (!(str = va_arg(ap, char*)))
		return (ft_strdup("(null)"));
	return (new = ft_strdup(str));
}

char		*noconv(va_list ap)
{
	char *str;

	(void)ap;
	return ((str = ft_strdup("%")) ? str : NULL);
}
