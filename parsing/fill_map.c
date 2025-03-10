/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:36:07 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/10 23:10:40 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void change_space_to_wall(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t' || data->map[i][j] == '\r' || data->map[i][j] == '\v' || data->map[i][j] == '\f')
			j++;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ' ' && j != data->map[i][ft_strlen(data->map[i]) - 1])
				data->map[i][j] = '1';
		}
		i++;
	}
}

// void	split_info(t_data *data)
// {
// 	char **split;

// 	split = ft_split(data->north_text, ' ');
// 	free(data->north_text);
// 	data->north_text = ft_strdup(split[1]);
// 	data->north_text[ft_strlen(data->north_text) - 1] = '\0';
// 	ft_free(split);

// 	split = ft_split(data->south_text, ' ');
// 	free(data->south_text);
// 	data->north_text = ft_strdup(split[1]);
// 	data->north_text[ft_strlen(data->south_text) - 1] = '\0';
// 	ft_free(split);

// 	split = ft_split(data->west_text, ' ');
// 	free(data->west_text);
// 	data->north_text = ft_strdup(split[1]);
// 	data->north_text[ft_strlen(data->west_text) - 1] = '\0';
// 	ft_free(split);

// 	split = ft_split(data->east_text, ' ');
// 	free(data->east_text);
// 	data->north_text = ft_strdup(split[1]);
// 	data->north_text[ft_strlen(data->south_text) - 1] = '\0';
// 	ft_free(split);
// }

void split_info(t_data *data)
{
	char **split;

	split = ft_split(data->north_text, ' ');
	if (split && split[1])
	{
		free(data->north_text);
		data->north_text = ft_strdup(split[1]);
	}
	ft_free(split);
	split = ft_split(data->south_text, ' ');
	if (split && split[1])
	{
		free(data->south_text);
		data->south_text = ft_strdup(split[1]);
	}
	ft_free(split);
	split = ft_split(data->west_text, ' ');
	if (split && split[1])
	{
		free(data->west_text);
		data->west_text = ft_strdup(split[1]);
	}
	ft_free(split);
	split = ft_split(data->east_text, ' ');
	if (split && split[1])
	{
		free(data->east_text);
		data->east_text = ft_strdup(split[1]);
	}
	ft_free(split);
}

void get_map_info(char **tmp, t_data *data)
{
	int i;

	i = -1;
	while (tmp[++i])
	{
		if (ft_strnstr(tmp[i], "NO", 2))
			data->north_text = ft_strdup(tmp[i]);
		else if (ft_strnstr(tmp[i], "SO", 2))
			data->south_text = ft_strdup(tmp[i]);
		else if (ft_strnstr(tmp[i], "WE", 2))
			data->west_text = ft_strdup(tmp[i]);
		else if (ft_strnstr(tmp[i], "EA", 2))
			data->east_text = ft_strdup(tmp[i]);
		else if (ft_strnstr(tmp[i], "F ", 2))
			data->floor_color = ft_strdup(tmp[i]);
		else if (ft_strnstr(tmp[i], "C ", 2))
			data->cieling_color = ft_strdup(tmp[i]);
	}
	split_info(data);
}

int get_map_line_count(char **tmp)
{
	int i;
	int map_line_count;

	map_line_count = 0;
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i][0] == '1')
			map_line_count++;
	}
	return (map_line_count);
}

void get_map(char **tmp, t_data *data)
{
	int i;
	int j;
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

void fill_map(t_data *data, char *name)
{
	int fd;
	int i;
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
	close(fd);
	get_map_info(tmp, data);
	get_map(tmp, data);
	ft_free(tmp);
	// change_space_to_wall(data);
	print_stuff(data);
}
