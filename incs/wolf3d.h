/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:16:42 by nboste            #+#    #+#             */
/*   Updated: 2017/10/14 22:28:43 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

//# include "types.h"
# include "libft.h"
# include <SDL.h>

# define W_WIDTH 800
# define W_HEIGHT 600
# define MAXFPS 120

typedef struct s_env	t_env;

typedef struct			s_player
{
	t_2dpair	pos;
	t_2ipair	dir;
}						t_player;

typedef struct			s_wolf3d
{
	t_player	p;
}						t_wolf3d;

typedef struct			s_win
{
	SDL_Window	*win_sdl;
	t_2ipair	size;
	char		*name;
	t_bool		focus;
}						t_win;

typedef struct			s_rend
{
	SDL_Renderer	*rend_sdl;
	SDL_Texture		*texture_sdl;
	t_uint32		*pixels;
	t_2ipair		size;
}						t_rend;

typedef struct			s_env
{
	t_wolf3d	game;
	t_win		win;
	t_rend		rend;
}						t_env;

int						wolf3d_Run();

void					init(t_env *env);

void					process(t_env *env);

void					destroy(t_env *env);

#endif
