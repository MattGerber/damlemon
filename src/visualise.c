/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:47:52 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/25 20:17:21 by rbolton          ###   ########.fr       */
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