/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:49:45 by nboste            #+#    #+#             */
/*   Updated: 2017/10/24 00:43:06 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "raycasting.h"

t_color		getcolor(t_2ipair m, t_2dpair p, t_raydata *d);

t_color		getcolor_floor(t_raydata *d, t_2ipair pos, int posy);

#endif
