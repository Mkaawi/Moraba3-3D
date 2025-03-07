/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:32:18 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/07 23:55:11 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"



int	check_map_name(char	*name)
{
	if (!ft_strnstr(name, ".cub", ft_strlen(name)) || count(name, '.') != 1)
		return (1);
	return (0);
}

void	fill_map(t_data *data, char *name)
{
	int	fd;
	int	i;
	char **tmp;
	(void)data;

	i = -1;
	tmp = malloc(sizeof(char *));
	fd = open(name, O_RDONLY);
	while (1)
	{
		tmp[++i] = get_next_line(fd);
		if (!tmp[i])
			break;
	}
	close(fd);
}

void	parse(t_data *data, int ac, char **av)
{
	if (ac != 2)
		error("invalid argument number");
	if (check_map_name(av[1]) == 1)
		error("invalid map name");
	fill_map(data, av[1]);
}