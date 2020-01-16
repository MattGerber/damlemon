/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputChecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:05 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/16 16:47:51 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int	isAnts(char *line)
{
	return (ft_isonly(line, ft_isdigit) ? 1 : 0);
}//test lines if only contains digits and therefore is ants

int	isRoom(char *line)
{
	char **arr;
	
	arr = ft_strsplit(line, ' ');
	if ((ft_arrlen(arr) != 3) || (arr[0][0] == 'L') || !(ft_isonly(arr[1], ft_isdigit)) || !(ft_isonly(arr[2], ft_isdigit)))
		return (0);
	while (arr[0])
    	free((arr++)[0]);
	return (1);
}//tests if line is a valid room

int	roomNameExists(char *name, t_input *roomNames)
{
	while (roomNames)
	{
		if (ft_strcmp(name, roomNames->line))
			return (1);
		roomNames = roomNames->next;
	}
	return (0);
}

int	isLink(char *line, t_input *roomNames)
{
	char **arr;
	
	arr = ft_strsplit(line, '-');
	if ((ft_arrlen(arr) != 2) || !(roomNameExists(arr[0], roomNames)) || !(roomNameExists(arr[1], roomNames)))
		return (0);//checks for 1 dash in link
	while (arr[0])
    	free((arr++)[0]);
	return (1);
}