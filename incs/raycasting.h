/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:05:04 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 04:40:16 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "wolf3d.h"

typedef struct		s_raydata
{
	double		camerax;
	t_2dpair	raypos;
	t_2dpair	raydir;
	t_2ipair	mapsquare;
	t_2dpair	sidedist;
	t_2dpair	deltadist;
	double		dist;
	t_2ipair	step;
	int			hit;
	int			side;
}					t_raydata;

void	raycast_scene(t_scene *s, t_env *env);

#endif
