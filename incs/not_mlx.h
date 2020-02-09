/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:11:50 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/09 11:10:57 by mbrunel          ###   ########.fr       */
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
# include "mlx.h"

typedef struct		s_nmlx
{
	void			*win;
}					t_nmlx;

void hop(void);
int open_tmp();

#endif
