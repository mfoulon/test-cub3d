/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:23:22 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/04/29 14:32:39 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_game(t_program *game, int argc, char **argv)
{
	*game = malloc(sizeof(t_program));
	if (!game)
		ft_puterror("Error: init game malloc failed\n");
	ft_garbage_collector(game, false);
	game->argv = argv;
	game->argc = argc;
	init_map(game);
}