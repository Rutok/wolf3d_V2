/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:40:50 by nboste            #+#    #+#             */
/*   Updated: 2017/10/14 22:34:20 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "drawer.h"
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

int			wolf3d_Run()
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
	int	time;
	int	etime;
	int	fps;

	fps = 1000 / MAXFPS;
	time = SDL_GetTicks();
	etime = 0;
	while (1)
	{
		if (etime < fps)
			SDL_Delay(fps - etime);
		time += fps;
		print_fps();
		drawer_process(env);
	}
	destroy(env);
}

void	destroy(t_env *env)
{
	drawer_destroy(env);
	SDL_DestroyWindow(env->win.win_sdl);
	SDL_Quit();
}
