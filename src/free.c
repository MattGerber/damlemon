/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:08:09 by ben               #+#    #+#             */
/*   Updated: 2020/06/01 14:42:25 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

/*
** Customised free functions for each of the struct types used in the project.
*/

void    freetraffic(t_traffic *traffic)
{
    if (traffic)
    {
        if (traffic->next)
            freetraffic(traffic->next);
        free(traffic);
    }
}

void    freevein(t_vein *vein)
{
    if (vein)
    {
        if (vein->next)
            freevein(vein->next);
        free(vein);
    }
}

void	freeartery(t_artery *artery)
{
	if (artery)
	{
		if (artery->next)
			freeartery(artery->next);
		if (artery->vein)
			freevein(artery->vein);
		free(artery);
	}
}

void    freeheart(t_heart *heart)
{
	if (heart)
	{
		if (heart->artery)
        {
            if (*heart->artery)
                freeartery(*heart->artery);
            free(heart->artery);
        }
		if (heart->inputchecks)
			free(heart->inputchecks);
		freeinputlist(heart->input);
		freetraffic(heart->traffic);
		freeq(heart->queue);
		free(heart);
	}
}

void	freearr(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}