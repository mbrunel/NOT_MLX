/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 07:28:46 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/14 01:52:58 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

#define HEIGHT 600
#define WIDTH 600

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
	void			*img_ptr;
}                 data_t;

typedef struct	s_info
{
	int			bperpix;
	int			sizeline;
	int			endian;
}				t_info;

int	fail(int code)
{
	printf("fail number %d\n", code);
	return (EXIT_FAILURE);
}

int pressmouse(int i, int x, int y, void *data)
{
	data_t *s;

	(void)x;(void)y;(void)i;
	s = (data_t*)data;
	printf("PRESS\n");
	mlx_clear_window(s->mlx_ptr, s->mlx_win);
	return (0);
}

int releasemouse(int i, int x, int y, void *data)
{
	data_t *s;

	s = (data_t*)data;
	(void)x;(void)y;(void)i;
	printf("RELEASE\n");
	return (0);
}

int suckey(int i, void *data)
{
	data_t *s;

	s = (data_t*)data;
	printf("key : %d\n", i);
	return (0);
}

int frame_renderer(void *param)
{
	data_t *data;

	data = (data_t*)param;
	if (mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ptr, 0, 0) == -1)
		return (fail(5));
	return (0);
}

int main(void)
{
    data_t        data;
	int			*img;
	t_info		info;

	int y = -1;
	int x;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (fail(1));
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hop")) == NULL)
        return (fail(2));
	if (!(data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT)))
		return (fail(3));
	if (!(img = (int*)mlx_get_data_addr(data.img_ptr, &(info.bperpix), &(info.sizeline), &(info.endian))))
		return (fail(4));
	info.sizeline /= 4;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			img[y * WIDTH + x] =  x;
	}

	mlx_hook(data.mlx_win, 2, (1L<<0), &suckey, (void*)&data);
	mlx_hook(data.mlx_win, 4, (1L<<2), &pressmouse, (void*)&data);
	mlx_hook(data.mlx_win, 5, (1L<<3), &releasemouse, (void*)&data);
	mlx_loop_hook(data.mlx_ptr, &frame_renderer, &data);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
