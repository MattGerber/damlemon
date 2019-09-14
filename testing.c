/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:27:28 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/14 17:56:25 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	putinput(t_in *listin)
{
	printf("Input:\n\n");
	while (listin)
	{
		printf("%s\n", listin->line);
		listin = listin->line;
	}
}

void	putrooms(t_room *rooms)
{
	int	i;
	int j;

	i = 0;
	while (rooms)
	{
		i++;
		printf("Rooms: \n\nlist number: %i\nname: %s\nx cord: %i\ny cord: %i\nants: %i\nstart: %i\nend: %i\n", i, rooms->rname, rooms->xcord, rooms->xcord, rooms->bant, rooms->bstart, rooms->bend);
		if (rooms->links)
		{
			printf("links: \n");
			j = 0;
			while (rooms->links[i])
				printf("%s", rooms->links[i++]->rname);
		}
		rooms = rooms->next;
	}
	printf("\n\n\n\n");
}