/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/31 16:18:26 by rbolton          ###   ########.fr       */
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
	if(!bfs(heart))//do we print map if there are no paths
		erexit(heart, 1);
	reinitartery(heart);
	qants(heart, initants(heart));
	freeheart(heart);
}