/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:23:45 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 05:16:44 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"
#include "player_event.h"
#include "raycasting.h"

static void		escape_handle(t_env *env)
{
	static int	pushed;

	if (env->event.keys[SDL_SCANCODE_ESCAPE] && pushed == 0)
		pushed = 1;
	if (!env->event.keys[SDL_SCANCODE_ESCAPE] && pushed == 1)
	{
		pushed = 0;
		ft_putstr("SC - BASIC->INTRO\n");
		free(env->game.current);
		env->game.current = init_sc_intro();
	}
}

static void		draw_map(t_map map)
{
	t_2ipair	c;

	for (c.x = 0; c.x < 20 * 20; c.x++)
	{
		if (c.x % 20 == 0 && c.x != 0)
			ft_putchar('\n');
		ft_putnbr((int)map.array[c.x]);
	}
	ft_putchar('\n');
}

static void		basic_process(void *e)
{
	t_env	*env;

	env = (t_env *)e;
	escape_handle(env);
	process_basic_mvt(env);
	raycast_scene(env->game.current, env);
}

static t_map	get_basic_map()
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
	m.array[352] = 2;
	while (i < (20 * 20))
		m.array[i++] = 1;
	draw_map(m);
	return (m);
}

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
	s->m = get_basic_map();
	ft_putstr("SC - BASIC\n");
	return (s);
}
