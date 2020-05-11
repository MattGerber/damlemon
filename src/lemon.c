/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/11 11:35:49 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	initheart(t_heart *heart)
{
	heart->ants = 0;
	heart->artery = malloc(sizeof(t_artery **));
	*heart->artery = NULL;
	heart->input = NULL;
	heart->inputchecks = NULL;
	heart->network = NULL;
	heart->queue = NULL;
	heart->traffic = NULL;
	heart->buff = NULL;
}

void    freeheart(t_heart *heart)
{
	if (heart)
	{
		if (heart->artery)
			freeartery(*heart->artery);
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

int	main(void)
{
	t_heart	*heart;

	heart = malloc(sizeof(t_heart));
	initheart(heart);
	while (get_next_line(0, &(heart->buff)))
		if (!addinputnode(&heart->input, heart->buff))
			erexit(heart, 2);
	if (!validateinput(heart))
		erexit(heart, 3);
	initroomnodes(heart);
	heart->network = *heart->inputchecks->start;
	putinputlist(heart->input, 0);
	if(!bfs(heart))
		erexit(heart, 1);
	reinitartery(heart);
	sortpaths(heart);
	initants(heart);
	qants(heart);
	freeheart(heart);
}