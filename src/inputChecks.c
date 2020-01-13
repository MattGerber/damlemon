/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputChecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:05 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/13 17:34:12 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isAnts(char *line)
{
	while (line[0])
		if (!ft_isdigit(line[0]++))
			return (0);
	return (1);
}//test lines if only contains digits and therefore is ants

int	isRoom(char *line)
{
	char **arr;
	
	arr = ft_strsplit(line, ' ');
	if ((ft_arrlen(arr) != 3) || (arr[1] == 'L') || !(ft_isonly(arr[1], ft_isdigit())) || !(ft_isonly(arr[2], ft_isdigit())))
		return (0);
	while (arr)
		free(arr++);
	return (1);
}//tests if line is a valid room

int	isLink(char *line)
{
	char **arr;
	
	arr = ft_strsplit(line, '-');
	if ((ft_arrlen(arr) != 2) || !(ft_isonly(arr[0], ft_isdigit())) || !(ft_isonly(arr[1], ft_isdigit())))
		return (0);//checks for 1 dash in link
	while (arr)
		free(arr++);
	return (1);
}