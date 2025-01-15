// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   init_graphics.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/06 11:16:29 by dsindres          #+#    #+#             */
// /*   Updated: 2025/01/14 13:10:48 by artberna         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <cub3d.h>

// // void	init_map(t_cub *cub, char **tab)
// // {
// // 	(void)tab;

// // 	int	i;
// // 	int	j;

// // 	i = 0;
// // 	j = 0;
// // 	// check .cub
// // 	// recup les textures
// // 	// checker si viable
// // 	// si deux free le 1er en ecrasant
// // 	// si pas toutes les infos, on lance pas
// // 	// RGB pas possible au dessus de 255
// // 	// checker la map
// // 	// check si NSEO + orientation =
// // 	// flood fill si jouable (mur autour du joueur)
// // 	// si jouable
// // 	// calculer height et width pour malloc double_tab +
// // 	// la structure de l'autre con
// // 	// si jouable, creer une copie remplie de 1 et scanner les 0 de map
// // 	// initiale pour les remettre dans la copie

// // 	cub->map_height = nb de ligne;
// // 	cub->map_width = ligne la plus longue;
// // 	cub->map = malloc(sizeof(char *) * (cub->map_height + 1));

// // 	while (i < cub->map_height)
// // 	{
// // 		cub->map[i] = malloc(sizeof(char) * (cub->map_width + 1));
// // 		while (j < cub->map_width)
// // 		{
// // 			cub->map[i][j] = map dans le .cub[i][j];
// // 			j++;
// // 		}
// // 		cub->map[i][j] = '\0';
// // 		j = 0;
// // 		i++;
// // 	}
// // 	cub->map[i] = NULL;
// // }

// // void	init_player(t_cub *cub, char **tab)
// // {
// // 	(void)tab;

// // 	// A Arthur d'init tous ca, il y a deja les
// // 	// valeurs a rentrer suivant l'orientation du player

// // 	// char	face;
// // 	// face = 'N';

// // 	// position du joueur
// // 	cub->player.pos.x = 3;
// // 	cub->player.pos.y = 3;

// // 	// orientation
// // 	if (cub->orientation == 'N')
// // 	{
// // 		cub->player.dir.x = 0;
// // 		cub->player.dir.y = -1;
// // 		cub->player.cam.x = 0.66;
// // 		cub->player.cam.y = 0;
// // 	}
// // 	else if (cub->orientation == 'S')
// // 	{
// // 		cub->player.dir.x = 0;
// // 		cub->player.dir.y = 1;
// // 		cub->player.cam.x = -0.66;
// // 		cub->player.cam.y = 0;
// // 	}
// // 	else if (cub->orientation == 'E')
// // 	{
// // 		cub->player.dir.x = 1;
// // 		cub->player.dir.y = 0;
// // 		cub->player.cam.x = 0;
// // 		cub->player.cam.y = 0.66;
// // 	}
// // 	else if (cub->orientation == 'O')
// // 	{
// // 		cub->player.dir.x = -1;
// // 		cub->player.dir.y = 0;
// // 		cub->player.cam.x = 0;
// // 		cub->player.cam.y = -0.66;
// // 	}
// // }

// // void	init_img(t_cub *cub, char **tab)
// // {
// // 	(void)tab;

// // 	cub->nord.path = "./img/nord.xpm";
// // 	cub->sud.path = "./img/sud.xpm";
// // 	cub->est.path = "./img/est.xpm";
// // 	cub->ouest.path = "./img/ouest.xpm";
// // 	cub->nord.ptr = NULL;
// // 	cub->sud.ptr = NULL;
// // 	cub->est.ptr = NULL;
// // 	cub->ouest.ptr = NULL;
// // 	cub->frame.ptr = NULL;
// // 	cub->minimap.ptr = NULL;
// // }

static int	check_graphics(t_cub *cub)
{
	if (!cub->nord.path || !cub->sud.path
		|| !cub->est.path || !cub->ouest.path)
	{
		printf("Texture is missing, please check your file!\n");
		return (1);
	}
	if (is_openable(cub->nord.path) || is_openable(cub->sud.path)
		|| is_openable(cub->est.path) || is_openable(cub->ouest.path))
	{
		printf("Texture is not usable, please check your file!\n");
		return (1);
	}
	return (0);
}

static int	get_color(char *str, t_color *color)
{
	int	i;

	i = 1;
	while (str[i] == ' ')
		i++;
	color->r = ft_atoi(&str[i]);
	while (str[i] != ',' && str[i])
		i++;
	if (str[i] == ',')
		i++;
	color->g = ft_atoi(&str[i]);
	while (str[i] != ',' && str[i])
		i++;
	if (str[i] == ',')
		i++;
	color->b = ft_atoi(&str[i]);
	if (color->r > 255 || color->g > 255 || color->b > 255
		|| color->r < 0 || color->b < 0 || color->b < 0)
		return (printf("RGB Color not in usable!\n"), 1);
	printf("INFO : dans get color = %d, %d ,%d\n", color->r, color->g, color->b); //debug
	return (0);
}

static int	init_color(char *str, t_cub *cub)
{
	if (!ft_strncmp(str, "F", 1))
	{
		if (get_color(str, &cub->floor))
			return (1);
	}
	if (!ft_strncmp(str, "C", 1))
	{
		if (get_color(str, &cub->ceiling))
			return (1);
	}
	return (0);
}

static char	*get_path(char *str)
{
	int		i;
	int		j;
	char	*to_ret;

	to_ret = NULL;
	i = 2;
	j = 0;
	while (str[i] == ' ')
		i++;
	to_ret = ft_strdup_mo(str + i);
	return (to_ret);
}

int	init_graphics(t_cub *cub, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "NO", 2) && !cub->nord.path)
			cub->nord.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "SO", 2) && !cub->sud.path)
			cub->sud.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "EA", 2) && !cub->est.path)
			cub->est.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "WE", 2) && !cub->ouest.path)
			cub->ouest.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "F", 1) || !ft_strncmp(tab[i], "C", 1))
		{
			if (init_color(tab[i], cub))
				return (1);
		}
		i++;
	}
	if (check_graphics(cub)) // check si tous les chemins sont existants et utilisables
		return (1);
	return (0);
}
