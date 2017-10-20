/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 07:39:33 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 14:34:03 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"

static void	intro_process(void *e)
{
	static int	i;
	t_env		*env;

	env = (t_env *)e;
	if (env->event.keys[SDL_SCANCODE_RETURN] && i == 0)
		i = 1;
	if (!env->event.keys[SDL_SCANCODE_RETURN] && i == 1)
	{
		ft_putstr("SC - INTRO->BASIC\n");
		env->game.old = env->game.current;
		env->game.current = init_sc_basic();
		i = 0;
		SDL_Delay(100);
	}
	if (env->event.keys[SDL_SCANCODE_ESCAPE])
		env->event.exit = 1;
	SDL_Delay(100);
}

t_scene		*init_sc_intro(void)
{
	t_scene	*s;

	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		ft_exit("Malloc failed.");
	s->process = intro_process;
	s->m.array = 0;
	ft_putstr("SC - INTRO\n");
	return (s);
}
