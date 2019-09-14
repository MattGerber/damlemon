/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:12:06 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/14 15:39:38 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMON_H
# define LEMON_H
# include "../Libft/libft.h"

typedef struct	s_input
{
	char		*line;
	t_in		*next;
}				t_in;


typedef struct	s_room
{
	char		*rname;
	int			xcord;
	int			ycord;
	int			bant;
	char		bstart : 1;
	char		bend : 1;
	t_room		**links;
	t_room		*next
}				t_room;


#endif