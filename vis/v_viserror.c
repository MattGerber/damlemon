#include "../includes/visualiser.h"

/*
** Frees visualiser and pointers
*/

void	vis_free(t_vis **vis)
{
	int i;

	i = 0;
	if (vis && *vis)
	{
		SDL_DestroyTexture((*vis)->room);
		SDL_DestroyTexture((*vis)->bg);
		while((*vis)->ant[i])
			SDL_DestroyTexture((*vis)->ant[i++]);
		free((*vis)->ant);
		i = 0;
		while((*vis)->mirror[i])
			SDL_DestroyTexture((*vis)->mirror[i++]);
		SDL_DestroyRenderer((*vis)->rend);
		SDL_DestroyWindow((*vis)->window);
		SDL_Quit();
		free(*vis);
		(*vis) = NULL;
	}
}

/*
** Exits program and prints proper error message
*/

void	vis_error_free(t_vis *vis, const char *error)
{
	if (vis)
		vis_free(&vis);
	ft_putstr_fd((char*)error, 2);
	exit(1);
}

/*
** Frees ants linked list
*/

void	free_ants(t_ant *ants)
{
	if (ants)
    {
        if (ants->next)
            free_ants(ants->next);
        free(ants);
    }
}