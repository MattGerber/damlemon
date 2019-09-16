/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:27:28 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/16 17:42:59 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	putinput(t_in *listin)
{
	printf("Input:\n\n");
	while (listin)
	{
		printf("%s\n", listin->line);
		listin = listin->next;
	}
	printf("\n\n");
}

void	putrooms(t_room *rooms)
{
	int	i;
	int j;

	i = 0;
	printf("Rooms: \n\n");
	while (rooms)
	{
		i++;
		printf("list number: %i\nname: %s\nx cord: %i\ny cord: %i\nants: %i\nstart: %i\nend: %i\n\n", i, rooms->rname, rooms->xcord, rooms->xcord, rooms->bant, rooms->bstart, rooms->bend);
		if (rooms->links)
		{
			printf("links: \n");
			j = 0;
			while (rooms->links[i])
				printf("%s", rooms->links[i++]->rname);
		}
		rooms = rooms->next;
	}
}