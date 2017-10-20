/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:04:57 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 14:44:53 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_event.h"
#include <stdio.h>
#include <math.h>

t_2dpair	get_speeds(void)
{
	static int	time;
	static int	old;
	double		frame_time;
	t_2dpair	p;

	if (time == 0)
	{
		time = SDL_GetTicks();
		p.x = 0;
		p.y = 0;
		return (p);
	}
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

static void	process_trans(t_player *p, t_map *m, double s)
{
	if (m->array[(int)(p->pos.x + p->dir.x * s)
			+ (int)(m->size.x * (int)(p->pos.y))] == 0)
		p->pos.x += p->dir.x * s;
	if (m->array[(int)(p->pos.x)
			+ (int)(m->size.x * (int)(p->pos.y + p->dir.y * s))] == 0)
		p->pos.y += p->dir.y * s;
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
		process_trans(p, m, speeds.x);
	if (env->event.keys[SDL_SCANCODE_S])
		process_trans(p, m, -speeds.x);
	if (env->event.keys[SDL_SCANCODE_A])
		process_rotation(p, speeds.y);
	if (env->event.keys[SDL_SCANCODE_D])
		process_rotation(p, -speeds.y);
}
