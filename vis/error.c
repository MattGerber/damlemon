/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:19:07 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/04 14:57:14 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	erexit(t_heart *heart, int errorcode)
{
	char	*errormessages[2];

	errormessages[0] = "Error: No Paths Found";
	errormessages[1] = "Error: Malloc failed";
	if (errorcode == 3)
	{
		if (!heart->inputchecks->ants)
			ft_putendl("Error: ants missing or invalid");
		if (!heart->inputchecks->rooms)
			ft_putendl("Error: rooms missing or invalid");
		if (!heart->inputchecks->links)
			ft_putendl("Error: links missing or invalid");
		if (!heart->inputchecks->start)
			ft_putendl("Error: start missing or invalid");
		if (!heart->inputchecks->end)
			ft_putendl("Error: end missing or invalid");
	}
	else
		ft_putendl(errormessages[errorcode - 1]);
	freeheart(heart);
	exit(1);
}