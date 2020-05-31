/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:36:33 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/31 15:36:34 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

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
	t_input	*roomnames;
	t_input *inputnode;
	t_inputchecks *inputchecks;

	inputnode = heart->input;
	inputchecks =  heart->inputchecks;
	roomnames = NULL;
  if(inputnode->line[0] == '0' || !(ft_isdigit(inputnode->line[0])))
    erexit(heart, 3);  
	while (inputnode)
	{
		if (isants(inputnode->line))
		{
			if (inputchecks->links || inputchecks->rooms || inputchecks->ants )
				return (0);
			inputchecks->ants = 1;
		}
		else if (isroom(inputnode->line, heart))
		{
			if (!inputchecks->ants || inputchecks->links)
				return (0);
			inputchecks->rooms = 1;
			if (!(addinputnode(&roomnames, ft_strsub(inputnode->line, 0, ft_strnchr(inputnode->line, ' ')))))
				erexit(heart, 2);
		}		
      else if (islink(inputnode->line, roomnames, heart))
		{
			if (!inputchecks->ants || !inputchecks->rooms)
				return (0);
			inputchecks->links = 1;
		}
		else if (ft_strequ(inputnode->line, "##start") == 1)
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
		else if (!inputnode->line || (inputnode->line)[0] != '#')
			return (0);//maybe rewrite these last 3 into 1
		inputnode = inputnode->next;
	}
	inputchecks->rooms = roomdupes(roomnames);
	freeinputlist(roomnames);
	return (inputchecks->ants && inputchecks->rooms && inputchecks->links && inputchecks->start && inputchecks->end);
}

int		validateinput(t_heart *heart)
{
	if (!(heart->inputchecks = malloc(sizeof(t_inputchecks))))
		erexit(heart, 2);
	initchecks(heart->inputchecks);
	return (runinputchecks(heart));
	//dupe links
}