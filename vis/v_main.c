#include "../includes/visualiser.h"

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

int		main()
{
	t_vis		*visualiser;
	t_heart		*heart;


	heart = malloc(sizeof(t_heart));
	initheart(heart);
	while (get_next_line(0, &(heart->buff)))
		if (!addinputnode(&heart->input, heart->buff))
			erexit(heart, 2);
	if (!validateinput(heart))
		erexit(heart, 3);
	initroomnodes(heart);
	if (!(visualiser = (t_vis*)malloc(sizeof(t_vis))))
		vis_error_free(NULL, "vis failed to init");
	init_vis(visualiser);
	populate_vis(visualiser);
	init_loop(visualiser, heart);
	vis_free(visualiser);
	freeheart(heart);
	return (0);
}