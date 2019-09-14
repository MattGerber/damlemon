/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:01:40 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/14 17:17:36 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemon.h"

int		isroom(char *s)
{
	char	**split;
	int		bout;
	int		i;
	
	bout = 1;
	if (!s || s[0] == '\0' || s[0] == 'L' || s[0] == ' ' || ft_charcount(s, ' ') != 2)
		return (0);
	split = ft_strsplit(s, ' ');
	i = 0;
	while (split[i])
		i++;
	if (i != 3 || !ft_isonly(split[1], ft_isdigit) || !ft_isonly(split[2], ft_isdigit))
		bout = 0;;
	while (i)
		free(split[i-- - 1]);
	return (bout);
}

int		islink(char *s)
{
	char	**split;
	int		bout;
	int		i;
	
	bout = 1;
	if (!s || s[0] == '\0' || s[0] == '-' || ft_charcount(s, '-') != 2)
		return (0);
	split = ft_strsplit(s, '-');
	i = 0;
	while (split[i])
		i++;
	if (i != 2 || !ft_isonly(split[0], ft_isdigit) || !ft_isonly(split[1], ft_isdigit))
		bout = 0;
	while (i)
		free(split[i-- - 1]);
	return (bout);
}

int		isins(t_in *inlist)
{
	if (!inlist->line || inlist->line[0] == '\0' || !inlist->next || !isroom(inlist->next->line))
		return (0);
	if (ft_strequ(inlist->line, "##start"))
		return (1);
	if (ft_strequ(inlist->line, "##end"))
		return (2);
	return (0);
}

int		checkinput(t_in *inlist)
{
	char	start;
	char	end;
	char	link;

	start = 0;
	end = 0;
	link = 0;	
	if (!isonly(inlist->line, ft_isdigit))
		return (0);
	inlist = inlist->next;
	while (inlist)
	{
		if (!(islink(inlist->line) || isroom(inlist->line) || isins(inlist->line) || inlist->line[0] == '#'))
			return (0);
		if (islink(inlist->line))
			link = 1;
		if (isins(inlist->line) == 1)
			start = 1;
		if (isins(inlist->line) == 2)
			end = 1;
		inlist->next;
	}
	return ((start && end && link) ? 1 : 0);
}