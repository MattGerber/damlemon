/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/23 09:43:26 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

char	*test(char *str)
{
	str = "test";
	return (str);
}

void	initheart(t_heart **heart)
{
	(*heart)->ants= 0;
	(*heart)->artery= NULL;
	(*heart)->buff= NULL;
	(*heart)->input= NULL;
	(*heart)->inputChecks= NULL;
	(*heart)->network= NULL;
	(*heart)->queue= NULL;
	(*heart)->traffic= NULL;
}

int	main(void)
{
	t_heart	*heart;
	
	heart = (t_heart*)malloc(sizeof(t_heart));
	
	initheart(&heart);
	while (get_next_line(0, &(heart->buff))) {
			addinputnode(&(heart->input), heart->buff);
	}
	putinputlist(heart->input);
	ft_putendl(validateinput(heart->input) ? "input OK!" : "bad validation");
	initroomnodes(&heart);
	if(!bfs(&heart))
		erexit("no paths");
	beat(&heart);
	return (0);
}