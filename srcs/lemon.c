/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:14:27 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/16 17:21:11 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int main(void)
{
	t_in	*input;
	t_room	*rooms;
	char	**buff;

	input = NULL;
	rooms = NULL;
	buff = malloc(0);
	while (get_next_line(0, buff) > 0)
		if (!nodeaddin(&input, *buff))
			erexit();
	if (!checkinput(input))
		erexit();
	initroomlist(&input, &rooms);
	putinput(input);
	putrooms(rooms);
	return (1);
}