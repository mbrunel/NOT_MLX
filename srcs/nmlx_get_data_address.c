/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_get_data_address.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:01:58 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/10 10:37:50 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
{
	t_img *s_img;

	s_img = (t_img*)img_ptr;
	*bits_per_pixel = sizeof(Uint8) * 4;
	*size_line = *bits_per_pixel * s_img->width;
	*endian = 0;
	return (s_img->img);
}
