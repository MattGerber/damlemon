/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:48:51 by ben               #+#    #+#             */
/*   Updated: 2020/06/01 15:02:25 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

/*
** Reinitiliases the artery pointer in heart so that each pointer in the doubled pointed artery link list is stored in an array.
*/

void	reinitartery(t_heart *heart)
{
	t_artery	*temp;
	int			counter;

	temp = *heart->artery;
	free(heart->artery);
	heart->artery = NULL;
	if (!(heart->artery = malloc(sizeof(t_artery *) * (arterylength(temp) + 1))))
	{
		freeartery(temp);
		erexit(heart, 2);
	}
	counter = 0;
	while(temp)
	{
		heart->artery[counter] = temp;
		counter++;
		temp = temp->next;
	}
	heart->artery[counter] = temp;
}

/*
** Stores the move difference between each adjacent path in an array.
** This is used to calculate the optimal ant allocation.
*/

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
	int			counter;

	pathdifs = initpathdifs(heart);
	counter1 = 0;
	counter = 0;
	while (pathdifs[counter1])
		{
			counter = 0;
			if (heart->ants < (pathdifs[counter1] * (counter1 + 1)))
				return (counter1);
			while (counter <= counter1)
				heart->artery[counter++]->ants += pathdifs[counter1];
			heart->ants -= pathdifs[counter1] * (counter1 + 1);
			counter1++;
		}
	return (counter1);
}

/*
** Calls the various functions needed to allocate ants to paths.
** Returns the number of ants (satpath) needed to saturate the map with ants if each path was as long as the longest path.
** In other words, counts how many ants could move through each shorter path before with the same move count as moving them through the longest path.
*/

int		initants(t_heart *heart)
{
	int			satpath;
	int			counter;
	int			arterylen;

	satpath = 0;
	counter = 0;
	arterylen = arterylength(*heart->artery);

	while (heart->artery[satpath])
		counter += heart->artery[arterylen - 1]->veinlen - heart->artery[satpath++]->veinlen;

	satpath = (counter < heart->ants) ? arterylen : slowassign(heart);
	if (counter && (satpath == arterylen))
	{
		heart->ants -= counter;
		counter = arterylen - 1;
		while (counter && counter--)
			heart->artery[counter]->ants = heart->artery[arterylen - 1]->veinlen - heart->artery[counter]->veinlen;
	}

	while (counter < satpath)
		heart->artery[counter++]->ants += heart->ants / satpath;
	counter = heart->ants % satpath;

	while (counter--)
		heart->artery[counter]->ants++;

	return (satpath);
}