/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:23:51 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/21 19:03:55 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ischar(char c, char const *charset)
{
	int i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*new;
	int				i;
	int				j;

	start = 0;
	end = 0;
	i = -1;
	if (!set || !s1)
		return (s1 ? ft_strdup(s1) : NULL);
	while (s1[++i] && ft_ischar(s1[i], set))
		start++;
	i = ft_strlen(s1);
	while (i && s1[--i] && ft_ischar(s1[i], set))
		end++;
	j = (ft_strlen(s1) - (start + end));
	if (!(new = (char *)malloc((sizeof(char) * j) + 1)))
		if (!(new = (char *)malloc(sizeof(char))))
			return (NULL);
	j = 0;
	while (s1[start] && start < (ft_strlen(s1) - end))
		new[j++] = s1[start++];
	new[j] = '\0';
	return (new);
}
