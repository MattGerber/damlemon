/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:01:47 by bwebb             #+#    #+#             */
/*   Updated: 2020/04/30 14:26:37 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addcleannode(t_input **inputList, t_network *node)
{
	t_input *curnode;
	t_input *newnode;

	curnode = *inputList;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = malloc(sizeof(t_input))))
		return (0);
	newnode->line = NULL;
	newnode->roomnode = node;
	newnode->next = NULL;
	if (*inputList)
		curnode->next = newnode;
	else
		*inputList = newnode;
	return (1);
}

// void	fetchstartend(t_heart *heart)
// {
// 	t_input	*temp;
// 	int		i;

// 	i = 0;
// 	temp = heart->input;
// 	while (i < 2)
// 	{
// 		if (temp->roomnode->start)
// 		{
// 			heart->inputchecks->start = temp->roomnode;
// 			i++;
// 		}
// 		if (temp->roomnode->end)
// 		{
// 			heart->inputchecks->end = temp->roomnode;
// 			i++;
// 		}
// 		temp = temp->next;
// 	}
// }

void	cleaninput(t_heart *heart)
{
	t_input	*temp;
	t_input *clean;

	temp = heart->input;
	clean = NULL;
	while (temp)
	{
		if (temp->roomnode)
			addcleannode(&clean, temp->roomnode);
		temp = temp->next;
	}
	freeinputlist(heart->input);
	heart->input = clean;
	// fetchstartend(heart);
}