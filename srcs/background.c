/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:24:36 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 15:37:49 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.h"
#include "drawer.h"

void	draw_background(t_env *env)
{
	t_2ipair	i;
	t_color		sky;
	t_color		floor;

	floor.a = 0;
	floor.r = 0x1B;
	floor.g = 0x99;
	floor.b = 0x8B;
	sky.a = 0;
	sky.r = 0xC9;
	sky.g = 0xDA;
	sky.b = 0xEA;
	i.x = -1;
	while (++i.x < env->rend.size.x)
	{
		i.y = 0;
		while (i.y < env->rend.size.y)
		{
			if (i.y < env->rend.size.y / 2)
				drawer_putpixel(env, i, sky);
			else
				drawer_putpixel(env, i, floor);
			i.y++;
		}
	}
}
