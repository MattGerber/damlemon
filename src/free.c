/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:08:09 by ben               #+#    #+#             */
/*   Updated: 2020/05/04 13:16:04 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void    freetraffic(t_traffic *traffic)
{
    if (traffic)
    {
        if (traffic->next)
            freetraffic(traffic->next);
        free(traffic);
    }
}