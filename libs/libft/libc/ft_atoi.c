/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 06:09:14 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 23:25:21 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		goinfre(int k, const char *str, int i)
{
	int	cpk;
	int	chi;
	int	nbr;

	nbr = 0;
	i = i - k;
	while (k > 0)
	{
		cpk = k;
		chi = str[i] - '0';
		while ((cpk - 1) > 0)
		{
			chi *= 10;
			cpk--;
		}
		nbr += chi;
		k--;
		i++;
	}
	return (nbr);
}

static long int		nbfinder(int i, const char *str)
{
	long int	nbrel;
	int			k;

	k = 0;
	nbrel = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		k++;
		i++;
	}
	nbrel = goinfre(k, str, i);
	return (nbrel);
}

static long int		curse(int i, const char *str, int j, long int sol)
{
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	if ('0' <= str[i] && str[i] <= '9')
	{
		j = -1 * (j % 2);
		sol = nbfinder(i, str);
	}
	if (j == 0)
		j = 1;
	return (j * sol);
}

int					ft_atoi(const char *str)
{
	int			i;
	int			j;
	long int	sol;
	long int	fin;

	j = 0;
	i = 0;
	sol = 0;
	fin = curse(i, str, j, sol);
	return (fin);
}
