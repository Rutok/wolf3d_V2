/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:49:38 by nboste            #+#    #+#             */
/*   Updated: 2017/10/26 23:20:16 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static t_color	getcolor_more(t_2ipair m, t_2dpair p, double l)
{
	t_color	c;

	c.a = 0;
	if (p.x < m.x)
	{
		c.r = 0x7F * l;
		c.g = 0xB0 * l;
		c.b = 0x69 * l;
	}
	else
	{
		c.r = 0xFF * l;
		c.g = 0xFB * l;
		c.b = 0xBD * l;
	}
	return (c);
}

t_color			getcolor(t_2ipair m, t_2dpair p, t_raydata *d)
{
	t_color	c;
	double	l;

	l = d->dist > 6 ? 0 : (double)((1.0 - (d->dist / 6)));
	c.a = 0;
	if (d->side)
	{
		if (p.y < m.y)
		{
			c.r = 0xE6 * l;
			c.g = 0xAA * l;
			c.b = 0x68 * l;
		}
		else
		{
			c.r = 0x83 * l;
			c.g = 0x75 * l;
			c.b = 0x69 * l;
		}
		return (c);
	}
	else
		return (getcolor_more(m, p, l));
}

t_color			getcolor_floor(int posy)
{
	t_color	c;
	double	l;

	l = W_HEIGHT / (2.0 * posy - W_HEIGHT);
	l = l > 6 ? 0 : (double)((1.0 - (l / 6)));
	c.a = 0;
	c.r = 0xCA * l;
	c.g = 0x3C * l;
	c.b = 0x25 * l;
	return (c);
}
