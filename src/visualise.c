/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:47:52 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/16 17:25:08 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	putInputList(t_input **inputList)
{
	t_input *curNode;

	curNode = *inputList;
	while (curNode)
	{
		ft_putendl(curNode->line);
		curNode = curNode->next;
	};
}

void	putInputChecks(t_inputChecks *checks)
{
	ft_putnbr(checks->ants);
	ft_putendl(" ants");
	ft_putnbr(checks->end);
	ft_putendl(" end");
	ft_putnbr(checks->links);
	ft_putendl(" links");
	ft_putnbr(checks->rooms);
	ft_putendl(" rooms");
	ft_putnbr(checks->start);
	ft_putendl(" start");
}