/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:09:31 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/25 11:43:11 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, t_program *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void	display_2d(t_program *data)
{
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
										&data->img->len, &data->img->endian);
	mlx_loop_hook(data->mlx_ptr, &render_2d, &data);

	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	
	mlx_loop(data->mlx_ptr);


	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	draw_tile(t_program *data, int	col, int row, int color)
{
	int	tile_width;
	int	tile_height;
	int	pix_x;
	int	pix_y;

	tile_height = WINDOW_HEIGHT / data->map->total_height;
	tile_width = WINDOW_WIDTH / data->map->total_width;
	pix_y = row * tile_height;
	while (pix_y < (row + 1) * tile_height)
	{
		pix_x = 0;
		while (pix_x < (col + 1) * tile_width)
		{
			img_pix_put(data->img, pix_x, pix_y, color);
			pix_x++;
		}
		pix_y++;
	}
}

int	render_2d(t_program *data)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return (1);
	i = 0;
	while (i < data->map->total_height)
	{
		j = 0;
		while (j < data->map->total_width)
		{
			if (data->map->map[i][j] == 1)
				draw_tile(data, j, i, BLUE);
			else
				draw_tile(data, j, i, RED);
		}
	}
	return (0);
}