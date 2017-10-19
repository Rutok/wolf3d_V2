/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 07:39:33 by nboste            #+#    #+#             */
/*   Updated: 2017/10/19 08:55:21 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"

static void	intro_process(void *e)
{
	t_env	*env;

	env = (t_env *)e;
	if (env->event.keys[SDL_SCANCODE_W])
		ft_putstr("forward\n");
}

t_scene		*init_sc_intro(void)
{
	t_scene	*s;

	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		ft_exit("Malloc failed.");
	s->process = intro_process;
	return (s);
}
