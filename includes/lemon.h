/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:12:06 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/23 15:07:28 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMON_H
# define LEMON_H
# include "../Libft/libft.h"

typedef	struct		s_input
{
	char					*line;
	struct s_network		*roomnode;
	struct s_input			*next;
}							t_input;

typedef struct				s_veinids
{
	int						id;
	struct s_veinids		*next;
}							t_veinids;

typedef struct				s_network
{
	int						id;
	int						visited;
	char					*name;
	struct s_network		**links;
	int						x;
	int						y;
	int						start;
	int						end;
}							t_network;

typedef struct				s_inputchecks
{
	struct s_network		**start;
	struct s_network		**end;
	int						ants;
	int						rooms;
	int						links;
}							t_inputchecks;

typedef struct				s_vein
{
	struct s_network		*node;
	struct s_vein			*next;
}							t_vein;

typedef struct				s_artery
{
	int						id;
	int						ants;
	struct s_vein			*vein;
	struct s_artery			*next;
}							t_artery;


typedef struct				s_heart
{
	int						ants;
	char					*buff;
	struct s_input			*input;
	struct s_inputchecks	*inputchecks;
	struct s_network		*network;
	struct s_artery			*artery;
	struct s_traffic		*traffic;
	struct s_queue			*queue;
}							t_heart;

typedef struct				s_traffic
{
	int						id;
	struct s_traffic		*parent;
	struct s_vein			*veinnode;
	struct s_traffic		*next;
}							t_traffic;

typedef struct				s_queue
{
	struct s_network		*node;
	struct s_queue			*parent;
	struct s_queue			*next;
}							t_queue;

int							addinputnode(t_input **inputlist, char *line);
void						freeinputlist(t_input **inputlist);
int							isants(char *line);
int							isroom(char *line);
int							islink(char *line, t_input *roomNames);
int							validateinput(t_heart **heart);
void						erexit(char *errMsg);
void						putinputlist(t_input *inputlist);
void						putinputchecks(t_inputchecks *checks);
int							veinlen(t_vein *vein);
int							addant(t_traffic **traffic, int	id, t_vein	*veinnode);
int							pushq(t_queue **queue, t_queue **parent, t_network **node);
int							addveinnode(t_vein **vein, t_network *room);
void						freeq(t_queue *queue, t_veinids *veinids, t_vein **curvein);
t_artery					*addarterynode(t_artery **artery, int id);
int							veinlen(t_vein *vein);
void						popart(t_artery *artery);
void						resetvisits(t_heart **heart);
int							bfs(t_heart **heart);
void						beat(t_heart **heart);
void						initroomnodes(t_heart **heart);
void						putnetworknode(t_network *node);
void						putnetwork(t_network *node);
void						cleaninput(t_heart **heart);

#endif