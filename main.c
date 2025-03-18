/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:16:58 by abdennac          #+#    #+#             */
/*   Updated: 2025/03/15 19:49:38 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WAAAAAAAAAAAAAAA3

#include "cube.h"

void ff()
{
	system("leaks moraba3");
}
int main(int ac, char **av)
{
	t_data	*data;
	
	atexit(ff);
	data = malloc(sizeof(t_data));
	parse(data, ac, av);
	free_stuff(data);
}