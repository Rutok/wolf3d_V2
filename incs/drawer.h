/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 22:03:24 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 04:30:23 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

# include "wolf3d.h"

void	drawer_init(t_env *env);

void	drawer_process(t_env *env);

void	drawer_destroy(t_env *env);

void	drawer_putpixel(t_env *env, t_2ipair p, t_color c);

#endif
