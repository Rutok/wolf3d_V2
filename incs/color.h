/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:49:45 by nboste            #+#    #+#             */
/*   Updated: 2017/10/26 23:14:06 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "raycasting.h"

t_color		getcolor(t_2ipair m, t_2dpair p, t_raydata *d);

t_color		getcolor_floor(int posy);

#endif
