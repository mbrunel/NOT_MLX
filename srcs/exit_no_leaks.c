/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_no_leaks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:27:18 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/10 10:39:15 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int					exit_no_leaks(int i, void *mlx_ptr)
{
	t_nmlx	*s;

	s = (t_nmlx*)mlx_ptr;
	printf("It works boys\n");
	exit (i);
}
