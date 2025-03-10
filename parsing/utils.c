/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:27:59 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/10 23:07:04 by abdennac         ###   ########.fr       */
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
	printf("\nwalls data :\n\n");
	printf("%s\n", data->north_text);
	printf("%s\n", data->south_text);
	printf("%s\n", data->west_text);
	printf("%s\n", data->east_text);
	printf("\nfloor/ceiling data :\n\n");
	printf("%s", data->cieling_color);
	printf("%s", data->floor_color);
	
	int	i = -1;
	printf("\nmap :\n\n");
	while(data->map[++i])
		printf("%s", data->map[i]);
}
