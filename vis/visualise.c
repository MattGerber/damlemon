/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:47:52 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/31 16:31:29 by bwebb            ###   ########.fr       */
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