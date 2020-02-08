/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:08:34 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/10 15:59:38 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		curse(int n, int fd)
{
	char u;

	if (n > 9 || n < -9)
	{
		u = n > 0 ? n % 10 + '0' : -n % 10 + '0';
		n /= 10;
		curse(n, fd);
	}
	else
		u = n > 0 ? n + '0' : -n + '0';
	write(fd, &u, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
			write(fd, "-", 1);
		curse(n, fd);
	}
}
