/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:04:16 by artberna          #+#    #+#             */
/*   Updated: 2025/01/15 16:25:26 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_tab(char **src, char **dest)
{
	int	i;
	int	j;

	i = 0;
	while (src[i + 6])
	{
		j = 0;
		while (src[i + 6][j])
		{
			dest[i][j] = src[i + 6][j];
			j++;
		}
		i++;
	}
}

static char	**create_tab(t_cub *cub)
{
	char	**to_ret;
	int		i;
	int		j;

	i = 0;
	to_ret = ft_calloc(sizeof(char *), cub->map_height + 1);
	if (!to_ret)
		return (NULL);
	while (i < cub->map_height)
	{
		j = -1;
		to_ret[i] = ft_calloc(sizeof(char), cub->map_width + 1);
		if (!to_ret[i])
			return (free_double_index(to_ret, i), NULL);
		while (++j < cub->map_width)
			to_ret[i][j] = '1';
		to_ret[i][j] = '\0';
		i++;
	}
	to_ret[i] = NULL;
	return (to_ret);
}

static int	flood_fill(t_cub *cub, char **tab, int i, int j)
{
	if (j < 0 || i < 0 || i >= cub->map_height || j >= cub->map_width)
		return (printf("-----1---"), 1); //debug
	if (tab[i][j] == '1' || tab[i][j] == '.')
		return (0);
	if (tab[i][j] == ' ')
		return (printf("-----2---"), 1); //debug
	tab[i][j] = '.';
	if (!flood_fill(cub, tab, i + 1, j)
		&& !flood_fill(cub, tab, i - 1, j)
		&& !flood_fill(cub, tab, i, j + 1)
		&& !flood_fill(cub, tab, i, j - 1))
		return (0);
	return (printf("---3-----"),1); //debug
}

static char	**copy_tab(t_cub *cub, char **tab)
{
	char	**to_ret;
	int		i;
	int		j;

	i = 0;
	to_ret = ft_calloc(sizeof(char *), cub->map_height + 1);
	if (!to_ret)
		return (NULL);
	while (tab[i + 6])
	{
		j = 0;
		to_ret[i] = ft_calloc(sizeof(char), cub->map_width + 1);
		if (!to_ret[i])
			return (free_double_index(to_ret, i), NULL);
		while (tab[i + 6][j])
		{
			to_ret[i][j] = tab[i + 6][j];
			j++;
		}
		to_ret[i][j] = '\0';
		i++;
	}
	to_ret[i] = NULL;
	return (to_ret);
}

int	is_playable(t_cub *cub, char **tab)
{
	char	**to_ret;
	char	**to_test;

	to_test = NULL;
	to_ret = NULL;
	to_test = copy_tab(cub, tab);
	// to_test = create_tab(cub);  //debug
	if (!to_test)
		return (printf("Memory allocation failed!\n"), 1);
	// fill_tab(tab, to_test);  //debug
	printf("INFO : DOUBLE TAB COPY\n");  //debug
	print_double(to_test);  //debug
	if (flood_fill(cub, to_test, \
		(int)cub->player.pos.y, (int)cub->player.pos.x))
		return (printf("Map not closed!\n"), free_double(to_test), 1);
	free_double(to_test);
	to_ret = create_tab(cub);
	if (!to_ret)
		return (printf("Memory allocation failed!\n"), 1);
	fill_tab(tab, to_ret);
	cub->map = to_ret;
	return (0);
}
