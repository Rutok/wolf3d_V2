/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:23:45 by nboste            #+#    #+#             */
/*   Updated: 2017/10/24 03:55:40 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"
#include "player_event.h"
#include "raycasting.h"
#include "background.h"
#include "map_reader.h"

static void		escape_handle(t_env *env)
{
	static int	pushed;

	if (env->event.keys[SDL_SCANCODE_ESCAPE] && pushed == 0)
		pushed = 1;
	if (!env->event.keys[SDL_SCANCODE_ESCAPE] && pushed == 1)
	{
		pushed = 0;
		ft_putstr("SC - BASIC->INTRO\n");
		env->game.old = env->game.current;
		env->game.current = init_sc_intro();
		SDL_RenderClear(env->rend.rend_sdl);
	}
}

static void		basic_process(void *e)
{
	t_env		*env;
	t_map		*m;
	t_player	*p;

	env = (t_env *)e;
	m = &env->game.current->m;
	p = &env->game.current->p;
	//draw_background(env);
	raycast_scene(env->game.current, env);
	process_basic_mvt(env);
	escape_handle(env);
	if (p->pos.x < 0 || p->pos.x > m->size.x
			|| p->pos.y < 0 || p->pos.y > m->size.y)
	{
		env->game.current->p.pos.x = 2;
		env->game.current->p.pos.y = 2;
	}
}

t_scene			*init_sc_basic(void)
{
	t_scene	*s;

	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		ft_exit("Malloc failed.");
	s->process = basic_process;
	s->p.pos.x = 1.5;
	s->p.pos.y = 1.5;
	s->p.dir.x = 0;
	s->p.dir.y = 1;
	s->p.plane.x = .8;
	s->p.plane.y = 0;
	s->e = 0;
	s->m = get_map("rcs/maps/sc_maze.map");
	ft_putstr("SC - BASIC\n");
	return (s);
}
