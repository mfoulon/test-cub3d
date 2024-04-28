/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:58:43 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/04/28 15:26:08 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	calculate_step(t_ray *ray, t_player player)
// {
// 	if (ray->dx < 0)
// 	{
// 		ray->sx = -1;
// 		ray->sdx = (player->x - ray->mx) * ray->ddx;
// 	}
// 	else
// 	{
// 		ray->sx = 1;
// 		ray->sdx = (ray->mx + 1.0 - player->x) * ray->ddx;
// 	}
// 	if (ray->dy < 0)
// 	{
// 		ray->sy = -1;
// 		ray->sdy = (player->y - ray->my) * ray->ddy;
// 	}
// 	else
// 	{
// 		ray->sy = 1;
// 		ray->sdy = (ray->my + 1.0 - player->y) * ray->ddy;
// 	}
// }

void	calculate_wall_distance(t_ray *ray, int **map)
{
	while (1)
	{
		if (ray->sdx < ray->sdy)
		{
			ray->sdx += ray->ddx;
			ray->mx += ray->sx;
			ray->side = 0;
		}
		else
		{
			ray->sdy += ray->ddy;
			ray->my += ray->sy;
			ray->side = 1;
		}
		if (map[ray->my][ray->mx] > '0')
		break;
	}
	if (ray->side == 0)
		ray->wd = ray->sdx - ray->ddx;
	else
		ray->wd = ray->sdy - ray->ddy;
}

void	calculate_wall_height(t_ray *ray, t_player *player)
{
	ray->h = (int)(WINDOW_HEIGHT/ ray->wd);
	ray->ds = -ray->h /  2 + WINDOW_HEIGHT / 2;
	if (ray->ds < 0)
		ray->ds = 0;
	ray->de = ray->h / 2 + WINDOW_HEIGHT / 2;
	if (ray->de >= WINDOW_HEIGHT)
		ray->de = WINDOW_HEIGHT - 1;
	if (ray->side == 0)
		ray->wx = player->y + ray->wd * ray->dy;
	else
		ray->wx = player->x + ray->wd * ray->dx;
	ray->wx -= floor(ray->wx);
}

void	cast_ray(t_program *data, t_ray *ray)
{
	int	x;

	x = 0;
	(void)ray; // A ENLEVER C POUR TEST
	(void)data; // LA MEME
	while (x < WINDOW_WIDTH)
	{
		//init_ray(ray, x, &data->player);
		//calculate_step(ray, &data->player);				JAI MIS TOUT EN COM POUR CHECK SI CA COMPILE AVEC MLX
		//calculate_wall_distance(ray, data->map->map);
		//calculate_wall_height(ray, &data->player);
		// to do >> update pixel map;
		x++; 
	}
}