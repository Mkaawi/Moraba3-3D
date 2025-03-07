/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:32:37 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/07 23:55:28 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "../cube.h"

typedef struct s_data
{
	char	**map;
	char	*cieling_color;
	char	*floor_color;
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
} t_data;

void	parse(t_data *data, int ac, char **av);

/***************  Utils  ***************/

int	count(char *arr, char c);
void	error(char *msg);


#endif