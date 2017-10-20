/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:23:45 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 16:29:36 by nboste           ###   ########.fr       */
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
		SDL_Delay(100);
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
	draw_background(env);
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

/*static t_map	get_basic_map(void)
{
	t_map	m;
	int		i;

	m.size.x = 20;
	m.size.y = 20;
	if (!(m.array = (t_uint32 *)malloc(sizeof(t_uint32) * 20 * 20)))
		ft_exit("Malloc Failed.");
	i = 0;
	while (i < 20)
		m.array[i++] = 1;
	while (i < (20 * 20 - 20))
	{
		if (i % 20 == 0 || i % 20 == 19)
			m.array[i] = 1;
		else
			m.array[i] = 0;
		i++;
	}
	m.array[44] = 2;
	m.array[72] = 3;
	m.array[125] = 4;
	m.array[203] = 1;
	while (i < (20 * 20))
		m.array[i++] = 1;
	return (m);
}*/

t_scene			*init_sc_basic(void)
{
	t_scene	*s;

	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		ft_exit("Malloc failed.");
	s->process = basic_process;
	s->p.pos.x = 2;
	s->p.pos.y = 2;
	s->p.dir.x = 0;
	s->p.dir.y = 1;
	s->p.plane.x = 0.66;
	s->p.plane.y = 0;
	s->e = 0;
	s->m = get_map("sc_basic.map");
	ft_putstr("SC - BASIC\n");
	return (s);
}
