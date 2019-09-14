/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:14:27 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/14 17:56:09 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int main(void)
{
	t_in	*input;
	t_room	*rooms;

	while ((get_next_line(0, nodeaddin(&input))) > 0)
	;
	if (!checkinput(input))
		erexit;
	initrooms(&input, &rooms);
	putinput(input);
	putrooms(rooms);
}