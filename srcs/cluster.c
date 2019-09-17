/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:01:40 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 15:05:54 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void    initcluster(t_cluster **cluster)
{
    (*cluster)->input = NULL;
    (*cluster)->links = NULL;
    (*cluster)->routes = NULL;
    (*cluster)->rooms = NULL;
}