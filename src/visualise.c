/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:47:52 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/22 17:40:51 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	putinputlist(t_input *curnode)
{
	while (curnode)
	{
		ft_putendl(curnode->line);
		curnode = curnode->next;
	};
}

void	putinputchecks(t_inputchecks *checks)
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