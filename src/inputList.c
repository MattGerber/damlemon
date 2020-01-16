/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputList.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:36:33 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/16 16:34:03 by bwebb            ###   ########.fr       */
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
	newNode->next = NULL;
	if (*inputList)
		curNode->next = newNode;
	else
		*inputList = newNode;
	// *((*inputList) ? inputList : &(curNode->next)) = newNode;
	return (1);
}

void	freeInputList(t_input **inputList)
{
	if (*inputList)
	{
		if ((*inputList)->next != NULL)
			freeInputList(&((*inputList)->next));
		free(*inputList);
	}
}

void	initChecks(t_inputChecks **checks)
{
	(*checks)->ants = 0;
	(*checks)->end = 0;
	(*checks)->links = 0;
	(*checks)->rooms = 0;
	(*checks)->start = 0;
}

int		runInputChecks(t_input *inputNode, t_inputChecks **inputChecks)
{
	t_input	*roomNames;
	
	roomNames = NULL;
	while (inputNode)
	{
		if (isAnts(inputNode->line))
		{
			if ((*inputChecks)->links || (*inputChecks)->rooms)
				return (0);
			(*inputChecks)->ants = 1;	
		}
		else if (isRoom(inputNode->line))
		{
			if (!(*inputChecks)->ants || (*inputChecks)->links || ((inputNode->line)[0] == 'L'))
				return (0);
			(*inputChecks)->rooms = 1;
			addInputNode(&roomNames, ft_strsub(inputNode->line, 0, ft_strnchr(inputNode->line, ' ')));
		}
		else if (isLink(inputNode->line, roomNames))
		{
			if (!(*inputChecks)->ants || !(*inputChecks)->rooms)
				return (0);
			(*inputChecks)->links = 1;
		}
		else if (ft_strcmp(inputNode->line, "##start") || ft_strcmp(inputNode->line, "##end"))
		{
			if ((!inputNode->next) || (!isRoom(inputNode->next->line)))
				return (0);
			if (ft_strcmp(inputNode->line, "##start"))
				(*inputChecks)->start = 1;
			else
				(*inputChecks)->end = 1;
		}
		else if ((inputNode->line)[0] != '#')
			return (0);
		inputNode = inputNode->next;
	}
	freeInputList(&roomNames);
	return ((*inputChecks)->ants && (*inputChecks)->rooms && (*inputChecks)->links && (*inputChecks)->start && (*inputChecks)->end);
}

int		validateInput(t_input *inputNode)
{
	t_inputChecks	*checks;
	int				ret;

	checks = (t_inputChecks*)malloc(sizeof(t_inputChecks));
	initChecks(&checks);
	ret = runInputChecks(inputNode, &checks);
	putInputChecks(checks);
	free (checks);
	return (ret);
}