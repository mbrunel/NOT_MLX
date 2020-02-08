/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 01:07:17 by mbrunel           #+#    #+#             */
/*   Updated: 2019/12/19 00:01:28 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			replace(char *str)
{
	int		i;
	int		j;
	char	swat;

	j = -1;
	while (str[++j])
		if (str[j] == '-')
			break ;
	if (!str[j])
		return ;
	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	if (ft_isdigit(str[i]))
	{
		if (str[i] != '0')
			i--;
		swat = str[i];
		str[i] = '-';
		str[j] = swat;
	}
}

int					printpercent(char *str, t_param *p, int len, int fd)
{
	int boo;

	boo = 0;
	if (!ft_strlen(str))
		boo = 1;
	if (p->arr > 1)
		if (!(str = add(str, p->arr - 1, p->att, p->att)))
			return (endclean(str, p, -1));
	write(fd, str, len = ft_strlen(str) + boo);
	return (endclean(str, p, len));
}

int					print_str(char *str, t_param *p, int len, int fd)
{
	int boo;

	boo = 0;
	if (!(len = ft_strlen(str)))
	{
		p->arr--;
		boo = 1;
	}
	if (p->aim > -1)
		len = len > p->aim ? p->aim : len;
	if (len != (int)ft_strlen(str))
		if (!(str = del(str, len)))
			return (endclean(str, p, -1));
	len = p->arr - len;
	if (len > 0)
		if (!(str = add(str, len, p->att, ' ')))
			return (endclean(str, p, -1));
	write(fd, str, len = ft_strlen(str));
	if (boo && p->arr >= 0)
	{
		len++;
		write(fd, " ", 1);
	}
	return (endclean(str, p, len));
}

int					print_dig(char *str, t_param *p, int len, int fd)
{
	int i;

	i = 0;
	if (p->aim >= 0 && p->att == '0')
		p->att = 0;
	if (p->aim == 0)
		checkzero(str, p);
	if (str[0] == '-')
		p->aim++;
	if (!(len = ft_strlen(str)))
		p->arr--;
	len = p->aim - len;
	if (len > 0)
		if (!(str = add(str, len, '0', '0')))
			return (endclean(str, p, -1));
	len = p->arr - ft_strlen(str);
	if (len > 0)
		if (!(str = add(str, len, p->att, p->att)))
			return (endclean(str, p, -1));
	replace(str);
	write(fd, str, len = ft_strlen(str));
	return (endclean(str, p, len));
}
