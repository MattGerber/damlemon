/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:12:06 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/14 17:58:58 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMON_H
# define LEMON_H
# include "../Libft/libft.h"

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_in;


typedef struct		s_room
{
	char			*rname;
	int				xcord;
	int				ycord;
	int				bant;
	char			bstart : 1;
	char			bend : 1;
	struct s_room	**links;
	struct s_room	*next
}					t_room;

void				erexit(void);
void				putinput(t_in *listin);
void				putrooms(t_room *rooms);
void				initroom(t_room **room, char **line, char bstart, char bend);
char				**nodeaddin(t_in **node);
int					checkinput(t_in *inlist);

#endif