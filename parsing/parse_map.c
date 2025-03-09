/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:27:59 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/09 23:46:20 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_map_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || !map[i + 1] || j == 0 || map[i][j + 1] == '\0' ||
					(map[i - 1][j] != '0' && map[i - 1][j] != '1' && map[i - 1][j] != 'N') ||
					(map[i + 1][j] != '0' && map[i + 1][j] != '1' && map[i + 1][j] != 'N') ||
					(map[i][j - 1] != '0' && map[i][j - 1] != '1' && map[i][j - 1] != 'N') ||
					(map[i][j + 1] != '0' && map[i][j + 1] != '1' && map[i][j + 1] != 'N'))
					error("map borders error");
			}
			j++;
		}
		i++;
	}
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'E' 
				|| map[i][j] == 'W' || map[i][j] == 'N')
				count++;
		}
	}
	if (count != 1)
		return (1);
	return (0);
}

void	parse_map(t_data *data)
{
	if (check_player(data->map) != 0)
		error ("player count error");
	// printf("checking map borders\n");
	// check_map_borders(data->map);
}
