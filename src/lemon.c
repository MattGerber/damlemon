/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:04 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/16 14:35:58 by bwebb            ###   ########.fr       */
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
	char	*buff;
	t_input	*inputHead;
	
	inputHead = NULL;
	while (get_next_line(0, &buff)) {
			addInputNode(&inputHead, buff);
	}
	putInputList(&inputHead);
	// freeInputList(&inputHead);
	ft_putendl(validateInput(inputHead) ? "input OK!" : "bad validation");
		// erexit("Bad map file");
	// while (1);
	return (0);
}