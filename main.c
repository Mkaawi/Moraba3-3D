/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:16:58 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/10 19:36:00 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WAAAAAAAAAAAAAAA3

#include "cube.h"

int main(int ac, char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	parse(data, ac, av);
}