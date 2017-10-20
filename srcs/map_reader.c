/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:09:06 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 18:44:46 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "error.h"

t_map	get_map(char *filename)
{
	int			fd;
	char		*line;
	t_map		map;
	t_2ipair	i;

	if (ft_strcmp(filename, "sc_basic.map") == 0)
	{
		map.size.x = 20;
		map.size.y = 20;
	}
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_exit("Error opening file.");
	if (!(map.array = (t_uint32 *)malloc(sizeof(t_uint32) * map.size.x * map.size.y)))
		ft_exit("Malloc failed.");
	i.y = 0;
	while (get_next_line(fd ,&line) > 0)
	{
		i.x = 0;
		while (i.x < map.size.x)
			map.array[i.y++] = line[i.x++] - '0';
	}
	return (map);
}
