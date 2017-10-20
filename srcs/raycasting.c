/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:04:49 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 05:10:45 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <math.h>
#include "drawer.h"

static void	init_raycast(t_raydata *d, t_scene *s, int x)
{
	d->camerax = 2 * x / (double)(W_WIDTH) - 1;
	d->raypos = s->p.pos;
	d->raydir.x = s->p.dir.x + s->p.plane.x * d->camerax;
	d->raydir.y = s->p.dir.y + s->p.plane.y * d->camerax;
	d->mapsquare.x = (int)(d->raypos.x);
	d->mapsquare.y = (int)(d->raypos.y);
	d->deltadist.x = sqrt(1 + (d->raydir.y * d->raydir.y) / (d->raydir.x * d->raydir.x));
	d->deltadist.y = sqrt(1 + (d->raydir.x * d->raydir.x) / (d->raydir.y * d->raydir.y));
	d->hit = 0;
	d->step.x = d->raydir.x < 0 ? -1 : 1;
	d->step.y = d->raydir.y < 0 ? -1 : 1;
	d->sidedist.x = d->step.x == -1 ? (d->raypos.x - d->mapsquare.x) * d->deltadist.x : (d->mapsquare.x + 1 - d->raypos.x) * d->deltadist.x;
	d->sidedist.y = d->step.y == -1 ? (d->raypos.y - d->mapsquare.y) * d->deltadist.y : (d->mapsquare.y + 1 - d->raypos.y) * d->deltadist.y;
}

static void	ray_dda(t_raydata *d, t_scene *s)
{
	while (!d->hit)
	{
		if (d->sidedist.x < d->sidedist.y)
		{
			d->sidedist.x += d->deltadist.x;
			d->mapsquare.x += d->step.x;
			d->side = 0;
		}
		else
		{
			d->sidedist.y += d->deltadist.y;
			d->mapsquare.y += d->step.y;
			d->side = 1;
		}
		if (s->m.array[d->mapsquare.x + s->m.size.x * d->mapsquare.y] != 0)
			d->hit = 1;
	}
	if (d->side)
		d->dist = (d->mapsquare.y - d->raypos.y + (1 - d->step.y) / 2) / d->raydir.y;
	else
		d->dist = (d->mapsquare.x - d->raypos.x + (1 - d->step.x) / 2) / d->raydir.x;
}

static t_color	getcolor(int n)
{
	t_color	c;

	c.a = 0;
	c.r = 0xE5;
	c.g = 0xDC;
	c.b = 0xC5;
	if (n == 2)
	{
		c.r = 0xC1;
		c.g = 0x49;
		c.b = 0x53;
	}
	if (n == 3)
	{
		c.r = 0x84;
		c.g = 0x8F;
		c.b = 0xA5;
	}
	if (n == 4)
	{
		c.r = 0x4C;
		c.g = 0x4C;
		c.b = 0x47;
	}
	return (c);
}

static void	draw_stripe(t_raydata *d, t_env *env, int x)
{
	int			height;
	t_2ipair	st_nd;
	t_2ipair	pos;
	t_color		c;

	height = (int)(W_HEIGHT / d->dist);
	st_nd.x = -height / 2 + W_HEIGHT / 2;
	if (st_nd.x < 0)
		st_nd.x = 0;
	st_nd.y = height / 2 + W_HEIGHT / 2;
	if (st_nd.y >= W_HEIGHT)
		st_nd.y = W_HEIGHT - 1;
	pos.x = x;
	pos.y = st_nd.x;
	c = getcolor(env->game.current->m.array[d->mapsquare.x + 20 * d->mapsquare.y]);
	while (pos.y <= st_nd.y)
	{
		drawer_putpixel(env, pos, c);
		pos.y++;
	}
}

void		raycast_scene(t_scene *s, t_env *env)
{
	int			x;
	t_raydata	raydata;

	x = 0;
	while (x < W_WIDTH)
	{
		init_raycast(&raydata, s, x);
		ray_dda(&raydata, s);
		draw_stripe(&raydata, env, x);
		x++;
	}

}
