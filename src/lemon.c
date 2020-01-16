/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/16 22:06:01 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

char	*test(char *str)
{
	str = "test";
	return (str);
}

int	main(void)
{
	t_heart	*heart;
	
	heart = (t_heart*)malloc(sizeof(t_heart));
	
	heart->input = NULL;
	while (get_next_line(0, &(heart->buff))) {
			addInputNode(&(heart->input), heart->buff);
	}
	putInputList(heart->input);
	ft_putendl(validateInput(heart->input) ? "input OK!" : "bad validation");

	initroomnodes(&heart);
	
	
	// freeInputList(&inputHead);
	// while (1);
	return (0);
}