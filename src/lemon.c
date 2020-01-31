/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/31 15:59:10 by bwebb            ###   ########.fr       */
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

int	main(void)
{
	t_heart	*heart;

	heart = (t_heart*)malloc(sizeof(t_heart));
	initheart(heart);
	while (get_next_line(0, &(heart->buff)))
		addinputnode(&(heart->input), heart->buff);
	if (validateinput(&heart) ? "input OK!" : "bad validation")
	{
		initroomnodes(&heart);
		heart->network = *heart->inputchecks->start;
		putinputlist(heart->input, 0);
		cleaninput(&heart);
		if(!bfs(heart))
			erexit("no paths");
		beat(&heart);
	}
}