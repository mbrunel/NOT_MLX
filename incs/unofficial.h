/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unofficial.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:53:24 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/12 17:24:38 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNOFFICIAL_H
# define UNOFFICIAL_H

void				nmlx_smart_hook_on(void *mlx_ptr);
void				nmlx_smart_hook_off(void *mlx_ptr);
void				nmlx_loop_stop(void *mlx_ptr);
void				nmlx_quit(void *mlx_ptr);

#endif
