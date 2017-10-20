/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:04:57 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 05:54:20 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_event.h"
#include <stdio.h>
#include <math.h>

t_2dpair	get_speeds()
{
	static int	time;
	static int	old;
	double		frame_time;
	t_2dpair	p;

	old = time;
	time = SDL_GetTicks();
	frame_time = (time - old) / 1000.0;
	p.x = frame_time * 5.0;
	p.y = frame_time * 3.0;
	return (p);
}

static void	process_rotation(t_player *p, double s)
{
	double	oldx;
	double	oldp;

	oldx = p->dir.x;
	p->dir.x = p->dir.x * cos(s) - p->dir.y * sin(s);
	p->dir.y = oldx * sin(s) + p->dir.y * cos(s);
	oldp = p->plane.x;
	p->plane.x = p->plane.x * cos(s) - p->plane.y * sin(s);
	p->plane.y = oldp * sin(s) + p->plane.y * cos(s);
}

void		process_basic_mvt(t_env *env)
{
	t_2dpair	speeds;
	t_map		*m;
	t_player	*p;

	speeds = get_speeds();
	m = &env->game.current->m;
	p = &env->game.current->p;
	if (env->event.keys[SDL_SCANCODE_W])
	{
		if (m->array[(int)(p->pos.x + p->dir.x * speeds.x) + (int)(m->size.x * (int)(p->pos.y))] == 0)
			p->pos.x += p->dir.x * speeds.x;
		if (m->array[(int)(p->pos.x) + (int)(m->size.x * (int)(p->pos.y + p->dir.y * speeds.x))] == 0)
			p->pos.y += p->dir.y * speeds.x;
	}
	if (env->event.keys[SDL_SCANCODE_S])
	{
		if (m->array[(int)(p->pos.x - p->dir.x * speeds.x) + (int)(m->size.x * (int)(p->pos.y))] == 0)
			p->pos.x -= p->dir.x * speeds.x;
		if (m->array[(int)(p->pos.x) + (int)(m->size.x * (int)(p->pos.y - p->dir.y * speeds.x))] == 0)
			p->pos.y -= p->dir.y * speeds.x;
	}
	if (env->event.keys[SDL_SCANCODE_A])
		process_rotation(p, speeds.y);
	if (env->event.keys[SDL_SCANCODE_D])
		process_rotation(p, -speeds.y);
}
