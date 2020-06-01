/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:36:33 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/19 16:29:11 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

/*
** Modified Lem-in file to reuse structure formatted for vis
*/

int		addinputnode(t_input **inputList, char *line)
{
	t_input *curnode;
	t_input *newnode;

	curnode = *inputList;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = malloc(sizeof(t_input))))
		return (0);
	newnode->line = line;
	newnode->roomnode = NULL;
	newnode->next = NULL;
	if (*inputList)
		curnode->next = newnode;
	else
		*inputList = newnode;
	return (1);
}

void	freeinputlist(t_input *inputlist)
{
	if (inputlist)
	{
		if (inputlist->next)
			freeinputlist(inputlist->next);
		if (inputlist->line)
			free(inputlist->line);
		if (inputlist->roomnode)
			freeroom(inputlist->roomnode);
		free(inputlist);
	}
}

void	initchecks(t_inputchecks *checks)
{
	checks->ants = 0;
	checks->end = NULL;
	checks->links = 0;
	checks->rooms = 0;
	checks->start = NULL;
}

int		runinputchecks(t_heart *heart)
{
	t_input *inputnode;
	t_inputchecks *inputchecks;

	inputnode = heart->input;
	inputchecks =  heart->inputchecks;
	if (ft_strequ(inputnode->line,"ERROR"))
		erexit(heart, 1);
	else if (ft_strequ(inputnode->line ,"ERROR: Memory allocation failure."))
		erexit(heart, 2);
	while (inputnode)
	{
		
		if (ft_strequ(inputnode->line, "##start") == 1)
		{
			if ((!inputnode->next) || (!isroom(inputnode->next->line, heart)) || inputchecks->start)
				return (0);
			inputchecks->start = &inputnode->next->roomnode;
		}
		else if (ft_strequ(inputnode->line, "##end") == 1)
		{
			if ((!inputnode->next) || (!isroom(inputnode->next->line, heart)) || inputchecks->end)
				return (0);
			inputchecks->end = &inputnode->next->roomnode;
		}
		inputnode = inputnode->next;
	}
	return (1);
}

int		validateinput(t_heart *heart)
{
	if (!(heart->inputchecks = malloc(sizeof(t_inputchecks))))
		erexit(heart, 2);
	initchecks(heart->inputchecks);
	return (runinputchecks(heart));
	//dupe links
}