/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:47:52 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/31 13:29:02 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	putinputlist(t_input *curnode, int putnetwork)
{
	while (curnode)
	{
		// ft_putstr("{Line:}");
		ft_putendl(curnode->line ? curnode->line : "NULL");
		if (putnetwork && curnode->roomnode)
			putnetworknode(curnode->roomnode);
		curnode = curnode->next;
	};
	ft_putendl("");
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
	ft_putendl("~~~~~~~~~~~~~~~~~~~");
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
	ft_putendl("~~~~~~~~~~~~~~~~~~~~~");
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

void	putvein(t_vein *vein)
{
	if (vein)
	{
		ft_putstr(vein->node->name);
		if (vein->next)
			ft_putstr(" --> ");
		vein = vein->next;
	}
}

void	putartery(t_artery *artery, int showvein)
{
	while (artery)
	{
		ft_putendl("~~~~~~~~~~");
		ft_putnbr(artery->id);
		ft_putendl("{artery ID}");
		ft_putnbr(artery->ants);
		ft_putendl("{ants}");
		if (showvein)
		{
			ft_putstr("{vein} ");
			putvein(artery->vein);
			ft_putendl("");
		}
		ft_putendl("~~~~~~~~~~");
		artery = artery->next;
	}
}