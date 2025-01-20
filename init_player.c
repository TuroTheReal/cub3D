/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:31:46 by artberna          #+#    #+#             */
/*   Updated: 2025/01/20 15:39:20 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_player_ew(t_cub *cub)

{
	if (cub->orient == 'E')
	{
		cub->player.dir.x = 1;
		cub->player.dir.y = 0;
		cub->player.cam.x = 0;
		cub->player.cam.y = 0.66;
	}
	else if (cub->orient == 'W')
	{
		cub->player.dir.x = -1;
		cub->player.dir.y = 0;
		cub->player.cam.x = 0;
		cub->player.cam.y = -0.66;
	}
}

static void	init_player_ns(t_cub *cub)
{
	if (cub->orient == 'N')
	{
		cub->player.dir.x = 0;
		cub->player.dir.y = -1;
		cub->player.cam.x = 0.66;
		cub->player.cam.y = 0;
	}
	else if (cub->orient == 'S')
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
	cub->player.pos.y = i;
	if (cub->orient == 'N' || cub->orient == 'S')
		init_player_ns(cub);
	else if (cub->orient == 'E' || cub->orient == 'W')
		init_player_ew(cub);
}
