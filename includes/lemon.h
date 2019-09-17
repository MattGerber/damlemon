/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:12:06 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 16:37:17 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMON_H
# define LEMON_H
# include "../Libft/libft.h"

typedef struct		s_cluster
{
	struct s_input	*input;
	struct s_links	*links;
	struct s_routes	*routes;
	struct s_room	*rooms;
}					t_cluster;

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_in;

typedef struct		s_links
{
	struct s_room			*from;
	struct s_room			*to;
	struct s_links	*next;
}					t_links;

typedef struct 		s_path
{
	struct s_room			*room;
	struct	s_path	*next;
}					t_path;

typedef struct		s_routes
{
	int				moves;
	struct s_path			*path;
	struct s_routes	*next;
}					t_routes;

typedef struct		s_room
{
	char			*rname;
	int				xcord;
	int				ycord;
	int				bant;
	int				bstart;
	int				bend;
	struct s_room	*next;
}					t_room;

void				erexit(void);
void				putinput(t_in *listin);
void				putrooms(t_room *rooms);
void				initroom(t_room **room, char **line, int bstart, int bend);
int					nodeaddin(t_in **node, char *buff);
int					checkinput(t_in *inlist);
void				initroomlist(t_cluster **cluster);
void    			initcluster(t_cluster **cluster);
int					isins(t_in *inlist);
int					islink(char *s);
t_room				*findroom(t_room *roomlist, char *name);
void				putlinks(t_links *linkslist);
void				putallthethings(t_cluster *cluster);
void				initlinkslist(t_cluster **cluster);


#endif