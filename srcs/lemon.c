/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:14:27 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 17:20:01 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int main(void)
{
	t_cluster	*cluster;
	char		**buff;

	cluster = (t_cluster*)malloc(sizeof(t_cluster));
	initcluster(&cluster);
	buff = malloc(0);
	while (get_next_line(0, buff) > 0)
		if (!nodeaddin(&(cluster->input), *buff))
			erexit();
	if (!checkinput(cluster->input))
		erexit();
	initroomlist(&cluster);
	initlinkslist(&cluster);
	putallthethings(cluster);
	return (1);
}
//check that ive used the isrooms function for initrooms
//dups in links