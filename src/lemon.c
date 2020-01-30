/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/30 14:39:36 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	initheart(t_heart **heart)
{
	(*heart)->ants = 0;
	(*heart)->artery = NULL;
	(*heart)->input = NULL;
	(*heart)->inputchecks = NULL;
	(*heart)->network = NULL;
	(*heart)->queue = NULL;
	(*heart)->traffic = NULL;
	(*heart)->buff = NULL;
}



int	main(void)
{
	t_heart	*heart;

	heart = (t_heart*)malloc(sizeof(t_heart));
	initheart(&heart);
	while (get_next_line(0, &(heart->buff)))
		addinputnode(&(heart->input), heart->buff);
	// putinputlist(heart->input);
	ft_putendl(validateinput(&heart) ? "input OK!" : "bad validation");
	initroomnodes(&heart);
	// ft_putendl("suck my muthafuckin balls~~~~~~~~~~~~~~~~~~~~~~~");
	heart->network = *heart->inputchecks->start;
	cleaninput(&heart);
	// putinputlist(heart->input, 1);
	if(!bfs(&heart))
		erexit("no paths");
	// 	//here
	// beat(&heart);
	return (0);
}

//initvisited could be rewrote to be faster if needed