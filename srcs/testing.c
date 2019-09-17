/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:27:28 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 16:39:27 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	putallthethings(t_cluster *cluster)
{
	putinput(cluster->input);
	putrooms(cluster->rooms);
	putlinks(cluster->links);
}

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

	i = 0;
	printf("Rooms: \n\n");
	while (rooms)
	{
		i++;
		printf("list number: %i\nname: %s\nx cord: %i\ny cord: %i\nants: %i\nstart: %i\nend: %i\n\n", i, rooms->rname, rooms->xcord, rooms->xcord, rooms->bant, rooms->bstart, rooms->bend);
		rooms = rooms->next;
	}
	printf("\n");
}

void	putlinks(t_links *linkslist)
{
	printf("Links:\n\n");
	while (linkslist)
	{
		printf("From:\t%s\nTo:\t%s\n\n", linkslist->from->rname, linkslist->to->rname);
		linkslist = linkslist->next;
	}
	printf("\n");
}