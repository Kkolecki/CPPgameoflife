#pragma once
#include <SDL.h>
extern SDL_Surface* surface;
extern SDL_Window* window;
extern unsigned int seed;

extern unsigned int cell_size;
extern unsigned cmap_w;
extern unsigned cmap_h;

extern unsigned int screen_w;
extern unsigned int screen_h;

extern void DrawCell(unsigned int x, unsigned int y, unsigned int color);

