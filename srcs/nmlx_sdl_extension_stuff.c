/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_sdl_extension_stuff.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:03:45 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/14 02:07:05 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)
{
	(void)mlx_ptr;
	(void)win_ptr;
	(void)x;
	(void)y;
	(void)color;
	(void)string;
	return (0);
}

void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height)
{
	(void)mlx_ptr;
	(void)xpm_data;
	(void)width;
	(void)height;
	return (NULL);
}

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
{
	(void)mlx_ptr;
	(void)filename;
	(void)width;
	(void)height;
	return (NULL);
}

void    *mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height)
{
	(void)mlx_ptr;
	(void)file;
	(void)width;
	(void)height;
	return (NULL);
}
