/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:24:36 by nboste            #+#    #+#             */
/*   Updated: 2017/10/25 01:01:02 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.h"
#include "drawer.h"

void	draw_background(t_env *env)
{
	t_2ipair	i;
	t_color		sky;

	sky.a = 0;
	sky.r = 0x20;
	sky.g = 0x20;
	sky.b = 0x20;
	i.x = 0;
	while (i.x < env->rend.size.x)
	{
		i.y = 0;
		while (i.y < env->rend.size.y)
		{
			if (i.y < env->rend.size.y / 2)
				drawer_putpixel(env, i, sky);
			i.y++;
		}
		i.x++;
	}
}
