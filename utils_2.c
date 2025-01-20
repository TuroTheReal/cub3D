/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:18:28 by artberna          #+#    #+#             */
/*   Updated: 2025/01/20 17:17:44 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_path(t_cub *cub)
{
	if (cub->nord.path)
		free(cub->nord.path);
	if (cub->sud.path)
		free(cub->sud.path);
	if (cub->est.path)
		free(cub->est.path);
	if (cub->ouest.path)
		free(cub->ouest.path);
}

char	*get_path(char *str)
{
	int		i;
	int		j;
	char	*to_ret;

	to_ret = NULL;
	i = 2;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	to_ret = ft_strdup_mo(str + i);
	if (!to_ret)
		return (NULL);
	return (to_ret);
}
