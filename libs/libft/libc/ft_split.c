/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:07:38 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 20:11:31 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			*clean(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static void			ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int			count_str(const char *str, char c)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (i == 0)
		{
			while (str[i] == c)
				i++;
			if (i > 0)
				i--;
		}
		if ((i != 0 && str[i] == c) && !(str[i - 1] == c))
			k++;
		i++;
	}
	if ((k == 0 && !str[0]) || str[i - 1] == c)
		return (k + 1);
	return (k + 2);
}

char				**ft_split(char const *str, char c)
{
	int		var[4];
	char	**tab;

	var[3] = count_str(str, c);
	if (!var[3] || !(tab = malloc(sizeof(char*) * var[3])))
		return (NULL);
	ft_bzero(tab, sizeof(char*) * var[3]);
	var[2] = 0;
	var[0] = 0;
	while (str[var[2]] == c)
		var[2]++;
	while (var[0] < var[3] - 1)
	{
		var[1] = 0;
		while (!(str[var[2]] == c) && str[var[2]])
			if (var[2]++ + var[1]++ < -2147483648)
				var[2] = var[1];
		if (!(tab[var[0]] = malloc(sizeof(char) * (var[1] + 1))))
			return (clean(tab));
		ft_strncpy(tab[var[0]], str + var[2] - var[1], var[1]);
		while (str[var[2]] == c)
			var[2]++;
		var[0]++;
	}
	return (tab);
}
