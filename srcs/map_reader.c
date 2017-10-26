/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:09:06 by nboste            #+#    #+#             */
/*   Updated: 2017/10/26 23:14:29 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "error.h"

static void		get_maze_array(t_map *m)
{
	char	*b;
	int		i;

	if (!(b = (char*)malloc(sizeof(char) * m->size.x * m->size.y)))
		ft_exit("Malloc failed.");
	ft_strcpy(b, "11111111111111111111111101000000000100000000111010101111101");
	ft_strcpy(b + ft_strlen(b), "00111100111000101000001001001001111110010001");
	ft_strcpy(b + ft_strlen(b), "11001001001110000010000000000010011111111100");
	ft_strcpy(b + ft_strlen(b), "01001111110011100000000010010000000011111111");
	ft_strcpy(b + ft_strlen(b), "11110011111100011000000000100000001000110000");
	ft_strcpy(b + ft_strlen(b), "00000111111111000110000000000000000000001111");
	ft_strcpy(b + ft_strlen(b), "11111111111111111111");
	i = 0;
	while (i < m->size.x * m->size.y)
	{
		m->array[i] = b[i] - '0';
		i++;
	}
	free(b);
}

static void		get_intro_array(t_map *m)
{
	char	*b;
	int		i;

	if (!(b = (char*)malloc(sizeof(char) * m->size.x * m->size.y)))
		ft_exit("Malloc failed.");
	ft_strcpy(b, "1111111111111010101011100000000011100000000110000000001100");
	ft_strcpy(b + ft_strlen(b), "0000001110000000001100000000011001000000110");
	ft_strcpy(b + ft_strlen(b), "00000011111111111111");
	i = 0;
	while (i < m->size.x * m->size.y)
	{
		m->array[i] = b[i] - '0';
		i++;
	}
	free(b);
}

static void		fill_map(char *filename, t_map *m)
{
	if (ft_strcmp(filename, "sc_maze.map") == 0)
	{
		m->size.x = 23;
		m->size.y = 13;
		if (!(m->array = (t_uint32 *)
					malloc(sizeof(t_uint32) * m->size.x * m->size.y)))
			ft_exit("Malloc failed.");
		get_maze_array(m);
	}
	else if (ft_strcmp(filename, "sc_intro.map") == 0)
	{
		m->size.x = 11;
		m->size.y = 11;
		if (!(m->array = (t_uint32 *)
					malloc(sizeof(t_uint32) * m->size.x * m->size.y)))
			ft_exit("Malloc failed.");
		get_intro_array(m);
	}
	else
		ft_exit("Bad Map!");
}

t_map			get_map(char *filename)
{
	t_map		map;

	fill_map(filename, &map);
	return (map);
}
