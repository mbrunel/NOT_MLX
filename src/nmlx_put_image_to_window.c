/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_put_image_to_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:34:10 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/14 02:08:52 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
{
	t_img		*img;
	t_win		*win;

	img = (t_img*)img_ptr;
	win = (t_win*)win_ptr;
	(void)x;(void)y;(void)mlx_ptr;
	if (SDL_UpdateTexture(img->tex, NULL, img->img, img->width * sizeof (Uint32)) == -1)
		return (-1);
	if (SDL_RenderCopy(win->render,img->tex, NULL, NULL) == -1)
		return (-1);
	SDL_RenderPresent(win->render);
	return (0);
}

unsigned int	mlx_get_color_value(void *mlx_ptr, int color)
{
	(void)mlx_ptr;
	(void)color;
	return (0);
}

int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	(void)mlx_ptr;
	(void)win_ptr;
	(void)x;
	(void)y;
	(void)color;
	return (0);
}
