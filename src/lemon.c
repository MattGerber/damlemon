/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/02 21:03:33 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	initheart(t_heart *heart)
{
	heart->ants = 0;
	heart->artery = NULL;
	heart->input = NULL;
	heart->inputchecks = NULL;
	heart->network = NULL;
	heart->queue = NULL;
	heart->traffic = NULL;
	heart->buff = NULL;
}

void    freeheart(t_heart *heart)
{
    freeartery(heart->artery);
    free(heart->inputchecks);
    freeinputlist(heart->input);
    free(heart);
}

int	main(void)
{
	t_heart	*heart;

	heart = malloc(sizeof(t_heart));
	initheart(heart);
	while (get_next_line(0, &(heart->buff)))
		addinputnode(&heart->input, heart->buff);
	if (validateinput(heart))
	{
		initroomnodes(heart);
		heart->network = *heart->inputchecks->start;
		putinputlist(heart->input, 0);
		if(!bfs(heart))
			erexit("no paths");
		initants(heart);
		qants(heart, heart->artery, 1);
		while (heart->traffic)
			putants(heart);
	}
	freeheart(heart);
}