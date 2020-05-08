/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:48:51 by ben               #+#    #+#             */
/*   Updated: 2020/05/08 11:26:54 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	sortpaths(t_heart *heart)
{
	int			counter;
	int			sorted;
	t_artery	*tmp;

	sorted = 0;
	while(!sorted)
	{
		counter = 0;
		sorted = 1;
		while(heart->artery[counter] && heart->artery[counter + 1])
		{
			if (heart->artery[counter] > heart->artery[counter + 1])
			{
				tmp = heart->artery[counter];
				heart->artery[counter] = heart->artery[counter + 1];
				heart->artery[counter + 1] = tmp;
				if (counter - 1 >= 0)
					heart->artery[counter - 1]->next = heart->artery[counter];
				heart->artery[counter + 1]->next = heart->artery[counter]->next;
				heart->artery[counter]->next = heart->artery[counter + 1];
				sorted = 0;
			}
			counter++;
		}
	}
}

void	reinitartery(t_heart *heart)
{
	t_artery	*temp;
	int			counter;
	int			artlen;

	temp = *heart->artery;
	artlen = arterylength(temp) + 1;
	free(heart->artery);
	if (!(heart->artery = malloc(sizeof(t_artery *) * artlen)))
		erexit(heart, 2);
	counter = 0;
	while(temp)
	{
		heart->artery[counter] = temp;
		counter++;
		temp = temp->next;
	}
	heart->artery[counter] = temp;
}

int		*initpathdifs(t_heart *heart)
{
	int		*pathdifs;
	int		counter;

	counter = 0;
	if (!(pathdifs = malloc(sizeof(int) * arterylength(*heart->artery))))
		erexit(heart, 2);
	while(heart->artery[counter + 1])
	{
		pathdifs[counter] = heart->artery[counter + 1]->veinlen - heart->artery[counter]->veinlen;
		counter++;
	}
	pathdifs[counter] = 0;
	return (pathdifs);
}

int		slowassign(t_heart *heart)
{
	int			*pathdifs;
	int			counter1;
	int			counter2;

	pathdifs = initpathdifs(heart);
	counter1 = 0;
	counter2 = 0;
	while (pathdifs[counter1])
		{
			counter2 = 0;
			if (heart->ants < (pathdifs[counter1] * (counter1 + 1)))
				return (counter1);
			while (counter2 <= counter1)
				heart->artery[counter2++]->ants += pathdifs[counter1];
			heart->ants -= pathdifs[counter1] * (counter1 + 1);
			counter1++;
		}
	return (counter1);
}

void	initants(t_heart *heart)
{
	int			counter1;
	int			counter2;
	int			arterylen;

	counter1 = 0;
	counter2 = 0;
	arterylen = arterylength(*heart->artery);
	while (heart->artery[counter1])
		counter2 += heart->artery[arterylen - 1]->veinlen - heart->artery[counter1++]->veinlen;
	counter1 = 0;
	if ((counter2) && (counter2 < heart->ants))
		while (heart->artery[counter1])
		{
			heart->artery[counter1]->ants = heart->artery[arterylen - 1]->veinlen - heart->artery[counter1]->veinlen;
			heart->ants -= heart->artery[counter1]->ants;
			counter1++;
		}
	else
		counter1 = (counter2) ? slowassign(heart) : 1;
	counter2 = 0;
	while (counter2 < counter1)
		heart->artery[counter2++]->ants += heart->ants / counter1;
	heart->ants %= counter1;
	counter1 = 0;
	while (counter1 < heart->ants)
		heart->artery[counter1++]->ants++;
}