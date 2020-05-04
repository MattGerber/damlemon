/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:19:07 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/04 14:45:38 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	erexit(t_heart *heart, int errorcode)
{
	char	*errormessages[2];
	
	errormessages[0] = "Error: No Paths Found";
	errormessages[1] = "Error: Malloc failed";
	ft_putendl(errormessages[errorcode - 1]);
	freeheart(heart);
	exit(1);
}