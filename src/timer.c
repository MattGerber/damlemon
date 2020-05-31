/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:19:13 by rbolton           #+#    #+#             */
/*   Updated: 2020/05/31 17:12:42 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>	// for time()
#include <unistd.h>	// for sleep()
#include "../includes/lemon.h"

void	initheart(t_heart *heart)
{
	heart->ants = 0;
	heart->artery = malloc(sizeof(t_artery **));
	*heart->artery = NULL;
	heart->input = NULL;
	heart->inputchecks = NULL;
	heart->network = NULL;
	heart->queue = NULL;
	heart->traffic = NULL;
	heart->buff = NULL;
}

int	main(void)
{
	t_heart	*heart;

  double time_spent = 0.0;
  time_t begin = time(NULL);
  clock_t start = clock();
  
	heart = malloc(sizeof(t_heart));
	initheart(heart);
	while (get_next_line(0, &(heart->buff)))
		if (!addinputnode(&heart->input, heart->buff))
			erexit(heart, 2);
	if (!validateinput(heart))
		erexit(heart, 3);
	initroomnodes(heart);
	heart->network = *heart->inputchecks->start;
	if(!bfs(heart))
		erexit(heart, 1);
	reinitartery(heart);
  putinputlist(heart->input, 0);
	qants(heart, initants(heart));
	freeheart(heart);

  time_t end = time(NULL);
  clock_t finish = clock();
  time_spent += (double)(finish - start) / CLOCKS_PER_SEC;
  printf("\n[Real time elpased: %ld seconds]\n[CPU time elapsed: %f seconds]\n", (end - begin), time_spent);
  return (0);
}