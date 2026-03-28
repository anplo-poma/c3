/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:03:30 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/28 00:41:44 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


static int	is_wall(t_game *game, double x, double y)
{
	return (game->map.matrix[(int)y][(int)x] == '1');
}


static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x + game->player.player_dir_x * MOVESPEED;
	new_y = game->player.player_y + game->player.player_dir_y * MOVESPEED;
	if (!is_wall(game, new_x, game->player.player_y))
		game->player.player_x = new_x;
	if (!is_wall(game, game->player.player_x, new_y))
		game->player.player_y = new_y;
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x - game->player.player_dir_x * MOVESPEED;
	new_y = game->player.player_y - game->player.player_dir_y * MOVESPEED;
	if (!is_wall(game, new_x, game->player.player_y))
		game->player.player_x = new_x;
	if (!is_wall(game, game->player.player_x, new_y))
		game->player.player_y = new_y;
}

static void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x - game->player.player_dir_y * MOVESPEED;
	new_y = game->player.player_y + game->player.player_dir_x * MOVESPEED;
	if (!is_wall(game, new_x, game->player.player_y))
		game->player.player_x = new_x;
	if (!is_wall(game, game->player.player_x, new_y))
		game->player.player_y = new_y;
}

static void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x + game->player.player_dir_y * MOVESPEED;
	new_y = game->player.player_y - game->player.player_dir_x * MOVESPEED;
	if (!is_wall(game, new_x, game->player.player_y))
		game->player.player_x = new_x;
	if (!is_wall(game, game->player.player_x, new_y))
		game->player.player_y = new_y;
}


void	move_player(t_game *game)
{
	if (game->move_y == 1)
		move_forward(game);
	if (game->move_y == -1)
		move_backward(game);
	if (game->move_x == -1)
		move_right(game);
	if (game->move_x == 1)
		move_left(game);
}
	