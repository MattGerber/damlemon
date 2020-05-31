/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:19:07 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/31 12:56:56 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	erexit(t_heart *heart, int errorcode)
{
	char	*errormessages[2];

	errormessages[0] = "ERROR";
	errormessages[1] = "ERROR: Memory allocation failure.";
	if (errorcode == 3)
	{
		if (!heart->inputchecks->ants)
			ft_putendl("ERROR");
		else if (!heart->inputchecks->rooms)
			ft_putendl("ERROR");
		else if (!heart->inputchecks->links)
			ft_putendl("ERROR");
		else if (!heart->inputchecks->start)
			ft_putendl("ERROR");
		else if (!heart->inputchecks->end)
			ft_putendl("ERROR");
    else 
      ft_putendl("ERROR");
	}
	else
		ft_putendl(errormessages[errorcode - 1]);
	freeheart(heart);
	exit(1);
}