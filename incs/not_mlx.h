/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:11:50 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/13 15:05:07 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOT_MLX_H
# define NOT_MLX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "libft.h"
# include "SDL2/SDL.h"
# include "X.h"
# include "mlx.h"
# include "unofficial.h"

#define EXIT -1

#define DELAY 50
#define INTERVAL

typedef struct		s_event
{
	int				(*funct_ptr)();
	void			*param;
	char			m;
	int				event;
	char			to_do;
	int				x;
	int				y;
	struct s_event	*next;
}					t_event;

typedef struct		s_win
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	t_event			*event;
	struct s_win	*next;
}					t_win;

typedef struct		s_img
{
	int				width;
	int				height;
	char			*img;
	SDL_Texture		*tex;
	struct s_img	*next;
}					t_img;

typedef struct		s_loop
{
	int				(*funct_ptr)();
	void			*param;
	struct s_loop	*next;
}					t_loop;

typedef struct		s_nmlx
{
	t_win			*win;
	t_img			*img;
	t_loop			*loop;
	char			smart_hook;
	char			key_repeat;
	char			loop_stop;
}					t_nmlx;

int					sig_kill(int i, void *mlx_ptr);
void				sdl_to_x(int *i, int *x_event, SDL_Event *sdl_event);

#endif
