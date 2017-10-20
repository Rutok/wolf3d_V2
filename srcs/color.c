/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:49:38 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 14:54:43 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static t_color	getcolor_more(t_2ipair m, t_2dpair p)
{
	t_color	c;

	c.a = 0;
	if (p.x < m.x)
	{
		c.r = 0x84;
		c.g = 0x8F;
		c.b = 0xA5;
	}
	else
	{
		c.r = 0x4C;
		c.g = 0x4C;
		c.b = 0x47;
	}
	return (c);
}

t_color			getcolor(t_2ipair m, t_2dpair p, t_raydata *d)
{
	t_color	c;

	c.a = 0;
	if (d->side)
	{
		if (p.y < m.y)
		{
			c.r = 0xE5;
			c.g = 0xDC;
			c.b = 0xC5;
		}
		else
		{
			c.r = 0xC1;
			c.g = 0x49;
			c.b = 0x53;
		}
		return (c);
	}
	else
		return (getcolor_more(m, p));
}
