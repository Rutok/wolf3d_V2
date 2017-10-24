/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 07:39:33 by nboste            #+#    #+#             */
/*   Updated: 2017/10/24 03:44:34 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sc_intro.h"
#include "scene.h"
#include "error.h"
#include "SDL_image.h"
#include "raycasting.h"
#include "background.h"
#include "map_reader.h"
#include "player_event.h"

static void	draw_images(t_env *env, t_scintro *d, int destroy)
{
	static int	init;
	SDL_Rect	r;

	if (destroy && init == 1)
	{
		SDL_DestroyTexture(d->logo);
		SDL_DestroyTexture(d->enter);
		init = 0;
		return ;
	}
	if (!init)
	{
		d->logo = IMG_LoadTexture(
				env->rend.rend_sdl, "rcs/imgs/title_screen.png");
		d->enter = IMG_LoadTexture(env->rend.rend_sdl, "rcs/imgs/press.png");
		init = 1;
	}
	SDL_QueryTexture(d->logo, NULL, NULL, &r.w, &r.h);
	r.x = (env->rend.size.x - r.w) / 2;
	r.y = 0;
	SDL_RenderCopy(env->rend.rend_sdl, d->logo, NULL, &r);
	SDL_QueryTexture(d->enter, NULL, NULL, &r.w, &r.h);
	r.x = (env->rend.size.x - r.w) / 2;
	r.y = W_HEIGHT - r.h - 50;
	SDL_RenderCopy(env->rend.rend_sdl, d->enter, NULL, &r);
}

static void	intro_process(void *e)
{
	static int			i;
	t_env				*env;
	static t_scintro	d;

	env = (t_env *)e;
	SDL_RenderClear(env->rend.rend_sdl);
	raycast_scene(env->game.current, env);
	draw_images(env, &d, 0);
	process_intro_mvt(env);
	if (env->event.keys[SDL_SCANCODE_RETURN] && i == 0)
		i = 1;
	if (!env->event.keys[SDL_SCANCODE_RETURN] && i == 1)
	{
		ft_putstr("SC - INTRO->BASIC\n");
		env->game.old = env->game.current;
		env->game.current = init_sc_basic();
		draw_images(env, &d, 1);
		i = 0;
	}
	if (env->event.keys[SDL_SCANCODE_ESCAPE])
		env->event.exit = 1;
}

t_scene		*init_sc_intro(void)
{
	t_scene	*s;

	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		ft_exit("Malloc failed.");
	s->process = intro_process;
	s->p.pos.x = 6;
	s->p.pos.y = 6;
	s->p.dir.x = 0;
	s->p.dir.y = 1;
	s->p.plane.x = 0.66;
	s->p.plane.y = 0;
	s->e = 0;
	s->m = get_map("rcs/maps/sc_intro.map");
	ft_putstr("SC - INTRO\n");
	return (s);
}
