/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_smart_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:33:11 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/12 15:40:53 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void	nmlx_smart_hook_on(void *mlx_ptr)
{
	((t_nmlx*)mlx_ptr)->smart_hook = 1;
}

void	nmlx_smart_hook_off(void *mlx_ptr)
{
	((t_nmlx*)mlx_ptr)->smart_hook = 0;
}
