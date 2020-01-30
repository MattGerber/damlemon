/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:47:52 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/30 13:52:14 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	putinputlist(t_input *curnode, int putnetwork)
{
	while (curnode)
	{
		ft_putendl(curnode->line);
		if (putnetwork && curnode->roomnode)
			putnetworknode(curnode->roomnode);
		curnode = curnode->next;
	};
}

void	putinputchecks(t_inputchecks *checks)
{
	ft_putnbr(checks->ants);
	ft_putendl(" ants");
	ft_putnbr(checks->end ? 1: 0);
	ft_putendl(" end");
	ft_putnbr(checks->links);
	ft_putendl(" links");
	ft_putnbr(checks->rooms);
	ft_putendl(" rooms");
	ft_putnbr(checks->start ? 1 : 0);
	ft_putendl(" start");
}

void	putnetworknode(t_network *node)
{
	int	i;

	i = 0;
	ft_putendl("");
	ft_putstr(node->name);
	ft_putendl(" {name}");
	ft_putnbr(node->end);
	ft_putendl(" {end}");
	ft_putnbr(node->id);
	ft_putendl(" {id}");
	ft_putendl("{links:}");
	while (node->links[i])
	{	
		ft_putstr(node->links[i]->name);
		ft_putstr(" {link ");
		ft_putnbr(i++);
		ft_putendl("}");
	}
	ft_putnbr(node->start);
	ft_putendl(" {start}");
	ft_putnbr(node->visited);
	ft_putendl(" {visited}");
	ft_putnbr(node->x);
	ft_putendl(" {x}");
	ft_putnbr(node->y);
	ft_putendl(" {y}");
	ft_putendl("");
}

void	putnetwork(t_network *node)
{
	int	i;

	i = 0;
	putnetworknode(node);
	while (node->links[i])
		putnetwork(node->links[i++]);
}

void	putinputnetwork(t_input *input)
{
	while(input)
	{
		if (input->roomnode)
			putnetworknode(input->roomnode);
		input = input->next;
	}
}