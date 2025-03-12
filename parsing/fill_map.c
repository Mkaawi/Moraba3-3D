/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:36:07 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/12 19:16:50 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_ints(int *arr)
{
	if (arr[0] > 255 || arr[0] < 0)
		return (1);
	if (arr[1] > 255 || arr[1] < 0)
		return (1);
	if (arr[2] > 255 || arr[2] < 0)
		return (1);
	return (0);
}

int	parse_ints2(char *str)
{
	int	i;

	i = -1;
	if (count(str, ',') > 2)
		return (1);
	while (str[++i])
	{
		if (str[i] == ',' && (str[i - 1] == ',' || str[i + 1] == ','))
			return (1);
	}
	return (0);
}

int *split_info3(char *str, t_data *data)
{
	char **split;
	char **tmp;
	int *arr;

	if (parse_ints2(str) != 0)
		error2("ceiling/floor error", data);
	split = ft_split(str, ' ');
	tmp = ft_split(split[1], ',');
	arr = malloc(ft_strlen2(tmp) * sizeof(int));
	arr[0] = ft_atoi(tmp[0]);
	arr[1] = ft_atoi(tmp[1]);
	arr[2] = ft_atoi(tmp[2]);
	ft_free(split);
	ft_free(tmp);
	if (parse_ints(arr) != 0)
		error2("ceiling/floor error", data);
	return (arr);
}

void split_info2(t_data *data)
{
	char **split;

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
	split_info2(data);
}

void get_map_info(char **tmp, t_data *data)
{
	int i;
	char *C;
	char *F;

	i = -1;
	while (tmp[++i])
	{
		if (ft_strnstr(tmp[i], "NO", 2))
			data->north_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "SO", 2))
			data->south_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "WE", 2))
			data->west_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "EA", 2))
			data->east_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "F ", 2))
			F = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "C ", 2))
			C = ft_strdup_no_newline(tmp[i]);
	}
	split_info(data);
	data->cieling_color = split_info3(C, data);
	data->floor_color = split_info3(F, data);
	free (C);
	free (F);
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

void	init(t_data *data)
{
	data->map = NULL;
	data->cieling_color = NULL;
	data->floor_color = NULL;
	data->east_text = NULL;
	data->north_text = NULL;
	data->south_text = NULL;
	data->west_text = NULL;
}

void fill_map(t_data *data, char *name)
{
	int fd;
	int i;
	char **tmp;

	i = -1;
	init(data);
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
	// ft_free(tmp);
	// change_space_to_wall(data);
	// print_stuff(data);
}
