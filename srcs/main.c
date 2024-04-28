/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:25:12 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/25 11:57:54 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_free(t_program *game, char *msg)
// {
// 	int	i;

// 	i = 0;
// 	while (game->map.map[i])
// 		free(game->map.map[i++]);
// 	free(game->map.map);
// 	free(game->map.filename);
// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 	printf("%s\n", msg);
// 	exit(EXIT_SUCCESS);
// }

// int	ft_close(t_program *game)
// {
// 	ft_free(game, "WINDOW CLOSED");
// 	return (0);
// }

// void	ft_new_window(t_program *game)
// {
// 	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w, game->screen_h, "cub3D");
// 	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
// }

int	main(int argc, char **argv)
{
	t_program	*game_data;

    (void)argc;
    game_data = malloc(sizeof(t_program));
    game_data->map = NULL;
	game_data->map->filepath = NULL;
	game_data->map->filepath = ft_strjoin("../../maps/", argv[1]);
	get_map_size(game_data);
	get_map(game_data);

	game_data->mlx_ptr = mlx_init();
    if (game_data->mlx_ptr == NULL)
        return (MLX_ERROR);
    game_data->win_ptr = mlx_new_window(game_data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
                                "my window");
    if (game_data->win_ptr == NULL)
    {
        free(game_data->win_ptr);
        return (MLX_ERROR);
    }

	display_2d(game_data);
	
}

// int	main(int ac, char **av)
// {
// 	t_program	game_ptr;

// 	if (ac != 2)
// 		ft_puterror("Usage: ./cub3D ./path_to_map\n");
// 	init_game(&game_ptr);
// 	game_ptr.map.filename = ft_strdup(av[1]);
// 	parse_map(&game_ptr);
// 	start_game(&game_ptr);
// 	mlx_hook (game_ptr.win_ptr, 2, 0, &press, &game_ptr);
// 	mlx_hook (game_ptr.win_ptr, 3, 0, &release, &game_ptr);
// 	mlx_loop_hook(game_ptr.mlx, lunch_game, &game_ptr);
// 	mlx_loop(game_ptr.mlx);
// 	return (0);
// }
