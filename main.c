/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:10:04 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/08 11:14:35 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int main(int argc, char** argv)
{
	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		ft_fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		return -1;
	}

	/* Création de la fenêtre */
	SDL_Window* pWindow = NULL;
	pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED,
	640,
	480,
	SDL_WINDOW_SHOWN);

	if( pWindow )
	{
		SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
		SDL_DestroyWindow(pWindow);
	}
	else
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	SDL_Quit();
	return 0;
}
