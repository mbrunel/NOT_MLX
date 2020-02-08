/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 05:30:18 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/31 17:49:02 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		endclean(void *ptr1, void *ptr2, int rt)
{
	free(ptr1);
	free(ptr2);
	return (rt);
}

void	checkzero(char *str, t_param *p)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '0'))
		i++;
	if (i < (int)ft_strlen(str))
		return ;
	if (p->att == '0')
		p->att = ' ';
	str[0] = ' ';
	str[1] = '\0';
	if (!p->arr)
		str[0] = '\0';
}

char	*add(char *str, int fix, char att, char c)
{
	char *tmp;
	char *new;

	if (c == 0)
		c = ' ';
	if (!(tmp = malloc(sizeof(char) * (fix + 1))))
		return (NULL);
	tmp[fix] = '\0';
	if (att == '-')
		ft_memset(tmp, ' ', fix);
	else if (att == '0')
		ft_memset(tmp, '0', fix);
	else
		ft_memset(tmp, c, fix);
	new = att == '-' ? ft_strjoin(str, tmp) : ft_strjoin(tmp, str);
	free(tmp);
	free(str);
	return (new ? new : NULL);
}

char	*del(char *str, int len)
{
	char *new;

	if (!(new = ft_substr(str, 0, len)))
		return (NULL);
	free(str);
	return (new);
}
