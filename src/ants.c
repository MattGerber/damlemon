/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:49:16 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/06 15:39:18 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		arterylength(t_artery *artery)
{
	int	i;

	i = 0;
	while(artery)
	{
		i++;
		artery = artery->next;
	}
	return (i);
}

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

void	initants(t_heart *heart)
{
	int			*pathdifs;
	int			counter1;
	int			counter2;
	int			arterylen;

	reinitartery(heart);
	sortpaths(heart);
	pathdifs = initpathdifs(heart);
	counter1 = 0;
	counter2 = 0;
	arterylen = arterylength(*heart->artery);
	while (heart->artery[counter1])
	{
		counter2 += pathdifs[counter1] * (counter1 + 1);
		counter1++;
	}
	counter1 = 0;
	//counter1 = (counter2 < heart->ants) ?  : ;
	if (counter2 < heart->ants)
		while (heart->artery[counter1])
		{
			heart->artery[counter1]->ants = heart->artery[arterylen - 1]->veinlen - heart->artery[counter1]->veinlen;
			counter1++;
		}
	else
	{
		while (pathdifs[counter1])
		{
			counter2 = 0;
			if (heart->ants < (pathdifs[counter1] * (counter1 + 1)))
				break ;
			while (counter2 <= counter1)
				heart->artery[counter2++]->ants += pathdifs[counter1];
			heart->ants -= pathdifs[counter1] * (counter1 + 1);
			counter1++;
		}
	}
	counter2 = 0;
	while (counter2 < counter1)
	{
		heart->artery[counter2]->ants += heart->ants / counter1;
		counter2++;
	}
	heart->ants &= counter1;
	counter1 = 0;
	while (heart->ants)
	{
		heart->artery[counter1]->ants++;
		heart->ants++;
		counter1++;
	}
}

void	initantsold(t_heart *heart)
{
	t_artery	*artrunner;
	t_artery	*shortpath;

	while (heart->ants)
	{
		shortpath = *heart->artery;
		artrunner = shortpath->next;
		while (artrunner)
		{
			if (artrunner->veinlen < shortpath->veinlen)
				shortpath = artrunner;
			artrunner = artrunner->next;
		}
		shortpath->ants++;
		heart->ants--;
	}
}

void	putants(t_heart *heart)
{
	t_traffic	*ant;
	t_traffic	*tmp;

	ant = heart->traffic;
	while (ant)
	{
		ant->veinnode = ant->veinnode->next;
		ft_putchar('L');
		ft_putnbr(ant->id);
		ft_putchar('-');
		ft_putstr(ant->veinnode->node->name);
		if (ant->next)
			ft_putstr(" ");
		if (ant->veinnode->node->end)
		{
			tmp = ant;
			// (tmp->parent) ? tmp->parent = tmp->next ? tmp->next->parent = tmp->parent;
			if (tmp->parent)
				tmp->parent = tmp->next;
			else
				heart->traffic = tmp->next;
			if (tmp->next)
				tmp->next->parent = tmp->parent;
			ant = tmp->next;
			free(tmp);
		}
		else
			ant = ant->next;
	}
	ft_putendl("");
}

int		addant(t_traffic **traffic, int	id, t_vein	*veinnode)
{
	t_traffic *curnode;
	t_traffic *newnode;

	curnode = *traffic;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = malloc(sizeof(t_traffic))))
		return (0);
	newnode->id = id;
	newnode->veinnode = veinnode;
	newnode->next = NULL;
	newnode->parent = (curnode) ? curnode : NULL;
	if (curnode)
		curnode->next = newnode;
	else
		*traffic = newnode;
	return (1);
}

void	qants(t_heart *heart)
{
	int		id;
	t_artery *artery;

	id = 1;
	heart->ants = 1;
	while (heart->ants)
	{
		artery = *heart->artery;
		heart->ants = 0;
		while (artery)
		{
			if (artery->ants)
			{
				if (!addant(&heart->traffic, id++, artery->vein))
					erexit(heart, 2);
				artery->ants--;
				heart->ants = 1;
			}
			artery = artery->next;
		}
		putants(heart);
	}
	while (heart->traffic)
		putants(heart);
}