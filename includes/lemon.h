/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:12:06 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/21 17:48:30 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMON_H
# define LEMON_H
# include "../Libft/libft.h"

/* old lemons
typedef struct		s_cluster
{
	struct s_input	*input;
	struct s_links	*links;
	struct s_artery	*artery;
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
	struct s_room	*room;
	struct s_room	*start;
	struct	s_path	*next;
}					t_path;

typedef struct		s_artery
{
	int				moves;
	struct s_path	*path;
	struct s_artery	*next;
}					t_artery;

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
int  				pathaddnode(t_path **path, t_room *room);
void				delpath(t_path **path);
*/
typedef	struct		s_input
{
	char			*line;
	t_network			*roomnode;
	struct s_input	*next;
}					t_input;

typedef struct		s_veinids
{
	int				id;
	struct s_veinids	*next;
}					t_veinids;


typedef struct		s_inputChecks
{
	int				start;
	int				end;
	int				ants;
	int				rooms;
	int				links;
}					t_inputChecks;

typedef struct		s_network
{
	int				id;
	int				visited;
	char			*name;
	t_network		**links;
	int				x;
	int				y;
	int				start;
	int				end;
}					t_network;

typedef struct		s_vein
{
	struct s_network	*node;
	struct s_vein	*next;
}					t_vein;

typedef struct		s_artery
{
	int				id;
	int				ants;
	struct s_vein	*vein;
	struct s_artery	*next;
}					t_artery;


typedef struct		s_heart
{
	int				ants;
	char			*buff;
	struct s_input	*input;
	struct s_inputChecks	*inputChecks;
	struct s_network	*network;
	struct s_artery	*artery;
	struct s_traffic	*traffic;
	struct s_queue			*queue;
}					t_heart;

typedef struct		s_traffic
{
	int				id;
	struct s_traffic	*parent;
	struct s_vein	*veinnode;
	struct s_traffic	*next;
}					t_traffic;

typedef struct			s_queue
{
	struct s_network	*node;
	struct s_queue		*parent;
	struct s_queue		*next;
}						t_queue;






int					addInputNode(t_input **inputList, char *line);
void				freeInputList(t_input **inputList);
int	isAnts(char *line);
int	isRoom(char *line);
int	isLink(char *line, t_input *roomNames);
int		validateInput(t_input *inputNode);
void	erexit(char *errMsg);
void	putInputList(t_input *inputList);
void	putInputChecks(t_inputChecks *checks);
int		veinlen(t_vein *vein);
int		addant(t_traffic **traffic, int	id, t_vein	*veinnode);
int		pushq(t_queue **queue, t_queue **parent, t_network **node);


#endif