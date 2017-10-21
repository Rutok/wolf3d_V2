/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:09:06 by nboste            #+#    #+#             */
/*   Updated: 2017/10/21 14:17:19 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "error.h"

static t_2ipair	get_size(char *filename)
{
	t_2ipair	s;

	if (ft_strcmp(filename, "rcs/maps/sc_maze.map") == 0)
	{
		s.x = 40;
		s.y = 40;
	}
	else if (ft_strcmp(filename, "rcs/maps/sc_basic.map") == 0)
	{
		s.x = 20;
		s.y = 20;
	}
	else if (ft_strcmp(filename, "rcs/maps/sc_intro.map") == 0)
	{
		s.x = 11;
		s.y = 11;
	}
	else
	{
		s.x = 0;
		s.y = 0;
	}
	return (s);
}

t_map			get_map(char *filename)
{
	int			fd;
	char		*line;
	t_map		map;
	t_2ipair	i;

	map.size = get_size(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_exit("Error opening file.");
	if (!(map.array = (t_uint32 *)
				malloc(sizeof(t_uint32) * map.size.x * map.size.y)))
		ft_exit("Malloc failed.");
	i.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i.x = 0;
		while (i.x < map.size.x)
			map.array[i.y++] = line[i.x++] - '0';
		free(line);
	}
	return (map);
}
