/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_do_key_repeat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:17:26 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/12 16:32:41 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_do_key_autorepeatoff(void *mlx_ptr)
{
	((t_nmlx*)(mlx_ptr))->key_repeat = 0;
	return (0);
}

int	mlx_do_key_autorepeaton(void *mlx_ptr)
{
	((t_nmlx*)(mlx_ptr))->key_repeat = 1;
	return (0);
}
