/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 22:03:07 by nboste            #+#    #+#             */
/*   Updated: 2017/10/14 22:30:45 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "error.h"

void	drawer_init(t_env *env)
{
	if (!(env->rend.rend_sdl = SDL_CreateRenderer(env->win.win_sdl,
					-1,
					SDL_RENDERER_ACCELERATED)))
		ft_exit("SDL REND INIT FAILED");
	if (!(env->rend.texture_sdl = SDL_CreateTexture(env->rend.rend_sdl,
					SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STREAMING,
					env->win.size.x,
					env->win.size.y)))
		ft_exit("SDL TEXTURE INIT FAILED");
	if (!(env->rend.pixels = (t_uint32 *)
				malloc(sizeof(t_uint32) * env->win.size.x * env->win.size.y)))
		ft_exit("RENDERER ARRAY INIT FAILED");
	env->rend.size = env->win.size;
}

void	drawer_process(t_env *env)
{
	SDL_UpdateTexture(
			env->rend.texture_sdl,
			NULL,
			env->rend.pixels,
			env->rend.size.x * sizeof(t_uint32)
	);
	SDL_RenderCopy(
			env->rend.rend_sdl,
			env->rend.texture_sdl,
			NULL,
			NULL
	);
	SDL_RenderPresent(env->rend.rend_sdl);
	ft_memset(
			env->rend.pixels,
			0,
			sizeof(t_uint32) * env->rend.size.x * env->rend.size.y
	);
}

void	drawer_destroy(t_env *env)
{
	free(env->rend.pixels);
	SDL_DestroyRenderer(env->rend.rend_sdl);
	SDL_DestroyTexture(env->rend.texture_sdl);
}
