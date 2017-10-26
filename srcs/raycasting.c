/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:04:49 by nboste            #+#    #+#             */
/*   Updated: 2017/10/26 23:21:57 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <math.h>
#include "drawer.h"
#include "color.h"

static void	init_raycast(t_raydata *d, t_scene *s, int x)
{
	d->camerax = 2 * x / (double)(W_WIDTH) - 1;
	d->raypos = s->p.pos;
	d->raydir.x = s->p.dir.x + s->p.plane.x * d->camerax;
	d->raydir.y = s->p.dir.y + s->p.plane.y * d->camerax;
	d->mapsquare.x = (int)(d->raypos.x);
	d->mapsquare.y = (int)(d->raypos.y);
	d->deltadist.x = sqrt(1 +
			(d->raydir.y * d->raydir.y) / (d->raydir.x * d->raydir.x));
	d->deltadist.y = sqrt(1 +
			(d->raydir.x * d->raydir.x) / (d->raydir.y * d->raydir.y));
	d->hit = 0;
	d->step.x = d->raydir.x < 0 ? -1 : 1;
	d->step.y = d->raydir.y < 0 ? -1 : 1;
	d->sidedist.x = d->step.x == -1 ? (d->raypos.x - d->mapsquare.x)
		* d->deltadist.x : (d->mapsquare.x + 1 - d->raypos.x) * d->deltadist.x;
	d->sidedist.y = d->step.y == -1 ? (d->raypos.y - d->mapsquare.y)
		* d->deltadist.y : (d->mapsquare.y + 1 - d->raypos.y) * d->deltadist.y;
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
		d->dist = (d->mapsquare.y - d->raypos.y + (1 - d->step.y) / 2)
			/ d->raydir.y;
	else
		d->dist = (d->mapsquare.x - d->raypos.x + (1 - d->step.x) / 2)
			/ d->raydir.x;
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
	pos.y = st_nd.x - 1;
	c = getcolor(d->mapsquare, env->game.current->p.pos, d);
	while (pos.y++ <= st_nd.y - 1)
		drawer_putpixel(env, pos, c);
	while (pos.y < W_HEIGHT)
	{
		c = getcolor_floor(pos.y);
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
	SDL_UpdateTexture(
			env->rend.texture_sdl,
			NULL,
			env->rend.pixels,
			env->rend.size.x * sizeof(t_uint32));
	SDL_RenderCopy(
			env->rend.rend_sdl,
			env->rend.texture_sdl,
			NULL,
			NULL);
}
