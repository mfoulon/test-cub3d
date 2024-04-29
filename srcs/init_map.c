#include "cub3d.h"

void	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_map(t_program *data) // needs argv inside data
{
	int	i;
	int y;

	check_map(); // to do 
	data->map = malloc(sizeof(t_map));
	if (!map)
		ft_puterror("Error: Map allocation failed\n");
	map = ft_garbage_collector(map, false);
	get_map_size(data);
	i = 0;
	while (i < data->map->total_height)
	{
		y = data->map->total_width;
		data->map->map[i] = malloc((y + 1) * sizeof(char));
		data->map->map[i][j] = '\0';
		ft_garbage_collector(&data->map->map[i], false);
		i++;
	}
	get_map(data);
	init_map_textures(); // to do
	data->map->filepath = ft_strjoin("maps/", data->argv[1]);
	ft_garbage_collector(data->map->filepath, false);
	
	// still have unused members?
	// i think they'll moove to an img part
	// if don't to do here

}