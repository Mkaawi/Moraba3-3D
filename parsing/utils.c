/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:27:59 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/07 23:55:18 by abdennac         ###   ########.fr       */
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

void	error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}
