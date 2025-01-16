/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:31:46 by artberna          #+#    #+#             */
/*   Updated: 2025/01/16 11:27:37 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_player_ew(t_cub *cub)
{
	if (cub->orientation == 'E')
	{
		cub->player.dir.x = 1;
		cub->player.dir.y = 0;
		cub->player.cam.x = 0;
		cub->player.cam.y = 0.66;
	}
	else if (cub->orientation == 'W')
	{
		cub->player.dir.x = -1;
		cub->player.dir.y = 0;
		cub->player.cam.x = 0;
		cub->player.cam.y = -0.66;
	}
}

void	init_player_ns(t_cub *cub)
{
	if (cub->orientation == 'N')
	{
		cub->player.dir.x = 0;
		cub->player.dir.y = -1;
		cub->player.cam.x = 0.66;
		cub->player.cam.y = 0;
	}
	else if (cub->orientation == 'S')
	{
		cub->player.dir.x = 0;
		cub->player.dir.y = 1;
		cub->player.cam.x = -0.66;
		cub->player.cam.y = 0;
	}
}

void	init_player(t_cub *cub, int i, int j)
{
	cub->player.pos.x = j;
	cub->player.pos.y = i - 6;
	if (cub->orientation == 'N' || cub->orientation == 'S')
		init_player_ns(cub);
	else if (cub->orientation == 'E' || cub->orientation == 'W')
		init_player_ew(cub);
}
