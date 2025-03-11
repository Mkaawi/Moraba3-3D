/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:27:59 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/11 17:43:52 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count(char *arr, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_strlen2(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_free(char **ptr)
{
	int	i;

	i = -1;
	while(ptr[++i])
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
}

void	error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	free_stuff(t_data *data)
{
	free (data->north_text);
	data->north_text = NULL;
	free (data->south_text);
	data->south_text = NULL;
	free (data->west_text);
	data->west_text = NULL;
	free (data->east_text);
	data->east_text = NULL;
	ft_free(data->map);
}

void	error2(char *str, t_data *data)
{
	error (str);
	free_stuff(data);
}

void print_stuff(t_data *data)
{
// 	printf("\nwalls data :\n\n");
// 	printf("NO %s\n", data->north_text);
// 	printf("SO %s\n", data->south_text);
// 	printf("WE %s\n", data->west_text);
// 	printf("EA %s\n", data->east_text);
// 	printf("\nfloor/ceiling data :\n\n");
	printf("C : %d,%d,%d\n", data->cieling_color[0], data->cieling_color[1], data->cieling_color[2]);
	printf("F : %d,%d,%d\n", data->floor_color[0], data->floor_color[1], data->floor_color[2]);
	
// 	int	i = -1;
// 	printf("\nmap :\n\n");
// 	while(data->map[++i])
// 		printf("%s", data->map[i]);
}
