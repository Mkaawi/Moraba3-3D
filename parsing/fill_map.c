/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:36:07 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/08 21:28:01 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void print_stuff(t_data *data)
{
	printf("\nwalls data :\n\n");
	printf("%s", data->north_text);
	printf("%s", data->south_text);
	printf("%s", data->west_text);
	printf("%s", data->east_text);
	printf("\nfloor/ceiling data :\n\n");
	printf("%s", data->cieling_color);
	printf("%s", data->floor_color);
	
	int	i = -1;
	printf("\nmap :\n\n");
	while(data->map[++i])
		printf("%s", data->map[i]);
}

void get_map_info(char **tmp, t_data *data)
{
	int	i;
	
	i = -1;
	while (tmp[++i])
	{
		if(ft_strnstr(tmp[i], "NO", 2))
			data->north_text = ft_strdup(tmp[i]);
		else if(ft_strnstr(tmp[i], "SO", 2))
			data->south_text = ft_strdup(tmp[i]);
		else if(ft_strnstr(tmp[i], "WE", 2))
			data->west_text = ft_strdup(tmp[i]);
		else if(ft_strnstr(tmp[i], "EA", 2))
			data->east_text = ft_strdup(tmp[i]);
		else if(ft_strnstr(tmp[i], "F ", 2))
			data->floor_color = ft_strdup(tmp[i]);
		else if(ft_strnstr(tmp[i], "C ", 2))
			data->cieling_color = ft_strdup(tmp[i]);
	}
}

int get_map_line_count(char **tmp)
{
	int	i;
	int map_line_count;
	
	map_line_count = 0;
	i = -1;
	while (tmp[++i])
	{
		// if (ft_strchr(tmp[i], '1'))
		if (tmp[i][0] == '1')
			map_line_count++;
	}
	return (map_line_count);
}
void get_map(char **tmp, t_data *data)
{
	int	i;
	int	j;
	int map_line_count;
	
	i = -1;
	j = -1;
	map_line_count = get_map_line_count(tmp);
	data->map = malloc(sizeof(char *) * (map_line_count + 1));
	if (!data->map)
		return;
	while (tmp[++i])
	{
		if (tmp[i][0] == '1')
			data->map[++j] = ft_strdup(tmp[i]);
	}
	if (j >= 0)
		data->map[j + 1] = NULL;
}


void	fill_map(t_data *data, char *name)
{
	int	fd;
	int	i;
	char **tmp;
	
	i = -1;
	tmp = malloc(sizeof(char *));
	fd = open(name, O_RDONLY);
	while (1)
	{
		tmp[++i] = get_next_line(fd);
		if (!tmp[i])
			break;
	}
	i = -1;
	while(tmp[++i])
	printf("%s", tmp[i]);
	printf("\n\n\n");
	close(fd);
	get_map_info(tmp, data);
	get_map(tmp, data);
	print_stuff(data);
}
