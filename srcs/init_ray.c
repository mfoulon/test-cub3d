/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:04:20 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/04/28 14:12:14 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_ray(t_ray *ray, int x, t_player *player)
{
    ray->cx = 2 * x / (double)(WINDOW_WIDTH);
    ray->dx = player->dx + player->px * ray->cx;
    ray->dy = player->dy + player->py * ray->cx;
    ray->mx = (int)player->x;
    ray->my = (int)player->y;
    ray->ddx = fabs(1 / ray->dx);
    ray->ddy = fabs(1 / ray->dy);
}