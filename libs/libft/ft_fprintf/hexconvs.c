/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexconvs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 05:22:14 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/31 16:43:29 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*xconv(va_list ap)
{
	unsigned int	nb;
	char			str[100];
	char			*new;

	nb = va_arg(ap, unsigned int);
	hexcurse(nb, 0, str);
	if (!(new = revdup(str)))
		return (NULL);
	return (new);
}

char				*grandxconv(va_list ap)
{
	unsigned int	nb;
	char			str[100];
	char			*new;

	nb = va_arg(ap, unsigned int);
	grandhexcurse(nb, 0, str);
	if (!(new = revdup(str)))
		return (NULL);
	return (new);
}

char				*pconv(va_list ap)
{
	size_t			nb;
	char			str[100];
	char			*new;
	char			*tmp;

	nb = (size_t)(va_arg(ap, void*));
	hexcurse(nb, 0, str);
	if (!(tmp = ft_strjoin(str, "x0")))
		return (NULL);
	new = revdup(tmp);
	free(tmp);
	return (new ? new : NULL);
}
