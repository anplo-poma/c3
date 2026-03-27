/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:32:34 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/27 22:42:35 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    render_frame(t_game *game)
{
	t_ray   ray;
	int     x;

	x = 0;
	while (x < game->screen_width)
	{
		ray.map_x = (int)game->player.player_x;
		ray.map_y = (int)game->player.player_y;
		find_wall(&ray, &game->player, game->map, x, game->screen_width);
		calcu_wall_dist(&ray);
		calcu_line_height(&ray, game->screen_height);
		draw_column(&game->img, &ray, game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
}