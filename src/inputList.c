/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputList.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:36:33 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/14 16:21:44 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addInputNode(t_input **inputList, char *line)
{
	t_input *curNode;
	t_input *newNode;

	curNode = *inputList;
	while (curNode && curNode->next)
		curNode = curNode->next;
	if (!(newNode = (t_input*)malloc(sizeof(t_input))))
		return (0);
	newNode->line = line;
	(*inputList) ? curNode->next = newNode : *inputList = newNode;
	return (1);
}

// void	freeInputList(t_input *inputList)
// {
// 	if (inputList->next)
// 		freeInputList(inputList->next);
// 	free(inputList->next);
// 	free(inputList);
// }

void	initChecks(t_inputChecks *checks)
{
	checks->ants = 0;
	checks->end = 0;
	checks->links = 0;
	checks->rooms = 0;
	checks->start = 0;
}

int		validateInput(t_input *inputNode)
{
	t_inputChecks *checks;

	initChecks(checks);
	while (inputNode)
	{
		if (isAnts(inputNode->line))
		{
			if (checks->links || checks->rooms)
				return (0);
			checks->ants = 1;	
		}
		else if (isRoom(inputNode->line))
		{
			if (!checks->ants || checks->links || ((inputNode->line)[0] == 'L'))
				return (0);
			checks->rooms = 1;
		}
		else if (isLink(inputNode->line))
		{
			if (!checks->ants || !checks->rooms)
				return (0);
			checks->links = 1;
		}
		else if (ft_strcmp(inputNode->line, "##start") || ft_strcmp(inputNode->line, "##end"))
		{
			if ((!inputNode->next) || (!isRoom(inputNode->next->line)))
				return (0);
			if (ft_strcmp(inputNode->line, "##start"))
				checks->start = 1;
			else
				checks->end = 1;
		}
		else if ((inputNode->line)[0] != '#')
			return (0);
		inputNode = inputNode->next;
	}
	return (checks->ants && checks->rooms && checks->links && checks->start && checks->end);
}