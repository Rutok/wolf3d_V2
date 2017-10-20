/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:40:50 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 05:56:37 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "drawer.h"
#include "scene.h"
#include "error.h"

static void	print_fps(void)
{
	static int	time;
	static int	fps;
	t_uint32	t;

	fps++;
	if (!time)
		time = SDL_GetTicks();
	if ((t = SDL_GetTicks()) >= (t_uint32)time + 1000)
	{
		ft_putstr("fps : ");
		ft_putnbr(fps);
		ft_putchar('\n');
		fps = 0;
		time = t;
	}
}

int			wolf3d_run(void)
{
	t_env env;

	init(&env);
	process(&env);
	destroy(&env);
	return (0);
}

void		init(t_env *env)
{
	env->win.name = "Wolf3D";
	env->win.size.x = W_WIDTH;
	env->win.size.y = W_HEIGHT;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_exit("SDL INIT FAILED");
	if (!(env->win.win_sdl = SDL_CreateWindow(env->win.name,
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					env->win.size.x,
					env->win.size.y,
					SDL_WINDOW_SHOWN)))
		ft_exit("SDL WINDOW INIT FAILED");
	drawer_init(env);
}

void		process(t_env *env)
{
	env->game.current = init_sc_intro();
	env->game.old = 0;
	event_reset(&env->event);
	while (!env->event.exit)
	{
		if (env->game.old)
		{
			if (env->game.old->m.array)
				free(env->game.old->m.array);
			free(env->game.old);
			env->game.old = 0;
		}
		print_fps();
		event_process(&env->event);
		env->game.current->process(env);
		drawer_process(env);
	}
}

void		destroy(t_env *env)
{
	free(env->game.current);
	drawer_destroy(env);
	SDL_DestroyWindow(env->win.win_sdl);
	SDL_Quit();
}
