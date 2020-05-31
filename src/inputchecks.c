/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:05 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/31 18:13:45 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int	isants(char *line)
{
	return (ft_isonly(line, ft_isdigit));
}

int	isroom(char *line, t_heart *heart)
{
	char	**arr;
	int		ret;

	ret = 1;
	if (!(arr = ft_strsplit(line, ' ')))
		erexit(heart, 2);
	if ((ft_arrlen(arr) != 3) || (arr[0][0] == 'L') || !(ft_isonly(arr[1], ft_isdigit)) || !(ft_isonly(arr[2], ft_isdigit)))
		ret = 0;
	freearr(arr);
	return (ret);
}

int	roomnameexists(char *name, t_input *roomNames)
{
	while (roomNames)
	{
		if (ft_strcmp(name, roomNames->line))
			return (1);
		roomNames = roomNames->next;
	}
	return (0);
}

int	islink(char *line, t_input *roomNames, t_heart *heart)
{
	char	**arr;
	int		ret;

	ret = 1;
	if (!(arr = ft_strsplit(line, '-')))
		erexit(heart, 2);
	if ((ft_arrlen(arr) != 2) || (roomNames && ((!(roomnameexists(arr[0], roomNames))) || (!roomnameexists(arr[1], roomNames)))) || ft_strequ(arr[0], arr[1]))
		ret = 0;
	freearr(arr);
	return (ret);
}

int	roomdupes(t_input *roomnames)
{
	t_input	*temp;
  t_input *start;
  int coordsdupe;

  start = roomnames;
	while (roomnames->next)
	{
		temp = roomnames->next;
		while (temp)
		{
			if (ft_strequ(roomnames->line, temp->line))
				return (0);
			temp = temp->next;
		}
		roomnames = roomnames->next;
	}
  coordsdupe = roomcoorddupes(start);
	return ((1 && (coordsdupe)) ? 1 : 0);
}

int roomcoorddupes(t_input *rooms)
{
  t_input *tmp;

	while (rooms->next)
	{
		tmp = rooms->next;
		while (tmp)
		{
			if ((rooms->roomnode->x == tmp->roomnode->x) && (rooms->roomnode->y == tmp->roomnode->y))
				return (0);
			tmp = tmp->next;
		}
		rooms = rooms->next;
	}
	return (1);
}