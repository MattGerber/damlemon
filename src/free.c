/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:08:09 by ben               #+#    #+#             */
/*   Updated: 2020/05/14 14:57:08 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

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
		if (heart->buff)
			free(heart->buff);
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