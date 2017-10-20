/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:16:42 by nboste            #+#    #+#             */
/*   Updated: 2017/10/20 05:36:06 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <SDL.h>
# include "event.h"

# define W_WIDTH 800
# define W_HEIGHT 600

typedef unsigned char	t_uchar;

typedef struct			s_color
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;
	t_uchar		a;
}						t_color;

typedef struct			s_player
{
	t_2dpair	pos;
	t_2dpair	dir;
	t_2dpair	plane;
}						t_player;

typedef struct			s_enemy
{
	void			(*process)(void *);
	t_2dpair		pos;
	t_2ipair		dir;
	struct s_enemy	*next;
}						t_enemy;

typedef struct			s_map
{
	t_uint32	*array;
	t_2ipair	size;
}						t_map;

typedef struct			s_scene
{
	void		(*process)(void *);
	t_map		m;
	t_player	p;
	t_enemy		*e;
}						t_scene;

typedef struct			s_wolf3d
{
	t_scene		*current;
	t_scene		*old;
	t_scene		*scenes;
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
	t_event		event;
	t_win		win;
	t_rend		rend;
}						t_env;

int						wolf3d_run();

void					init(t_env *env);

void					process(t_env *env);

void					destroy(t_env *env);

#endif
