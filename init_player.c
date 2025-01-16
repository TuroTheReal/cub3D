/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:31:46 by artberna          #+#    #+#             */
/*   Updated: 2025/01/16 18:20:34 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_player_ew(t_cub *cub)

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

static void	init_player_ns(t_cub *cub)
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

static void	init_start_position(t_cub *cub, int i, int j, char **tab)
{
	// si vers le N celle du dessus == 1, alors cub->player.pos.y = i * 1.05 Y
	// si vers le S * 0.95 Y i
	// si vers le E * 0.95 X j
	// si vers le W * 1.05 X j
	cub->player.pos.x = j;
	cub->player.pos.y = i; // -6
	if (i - 1 >= 0 && tab[i - 1][j] == '1' && cub->orientation == 'N')
	{
		cub->player.pos.y = (i) * 1.1;
		printf(" pos y = i * 1.1/n");
	}
	if (i + 1 < cub->map_height && cub->orientation == 'S'
		&& tab[i + 1] && tab[i + 1][j] == '1')
	{
		cub->player.pos.y = (i) * 0.9;
		printf(" pos y = i * 0.9/n");
	}
	if (j - 1 >= 0 && tab[i][j - 1] == '1' && cub->orientation == 'E')
	{
		cub->player.pos.x = (j) * 1.1;
		printf(" pos x = j * 1.1/n");
	}
	if (j + 1 < cub->map_height && cub->orientation == 'W'
		&& tab[i][j + 1] && tab[i][j + 1] == '1')
	{
		cub->player.pos.x = (j) * 0.9;
		printf(" pos x = j * 0.9/n");
	}
	printf("orientation done\n");
}

void	init_player(t_cub *cub, int i, int j, char **tab)
{
	init_start_position(cub, i, j, tab);
	if (cub->orientation == 'N' || cub->orientation == 'S')
		init_player_ns(cub);
	else if (cub->orientation == 'E' || cub->orientation == 'W')
		init_player_ew(cub);
}
