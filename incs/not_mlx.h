/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:11:50 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/11 15:26:56 by mbrunel          ###   ########.fr       */
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

#define EXIT -1

typedef struct		s_event
{
	int				(*funct_ptr)(int i, void *);
	void			*param;
	int				event;
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

typedef struct		s_nmlx
{
	t_win			*win;
	t_img			*img;
}					t_nmlx;

int					exit_no_leaks(int i, void*);
void				sdl_to_x(int *i, int *x_event, SDL_Event *sdl_event);

#endif
