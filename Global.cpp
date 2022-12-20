#pragma once
#include "Global.h"
#include <ctime>


SDL_Surface* surface = NULL;
SDL_Window* window = NULL;

unsigned int seed = (unsigned)time(NULL);

unsigned int cell_size = 2;
unsigned int cmap_w = 450;
unsigned int cmap_h = 300;
unsigned int screen_w = cmap_w * cell_size;
unsigned int screen_h = cmap_h * cell_size;

void DrawCell(unsigned int x, unsigned int y, unsigned int color)
{
	Uint8* pixel_ptr = (Uint8*)surface->pixels + (y * cell_size * screen_w + x * cell_size) * 4;

	for (unsigned int i = 0; i < cell_size; i++)
	{
		for (unsigned int j = 0; j < cell_size; j++)
		{
			*(pixel_ptr + j * 4) = color;
			*(pixel_ptr + j * 4 + 1) = color;
			*(pixel_ptr + j * 4 + 2) = color;
		}
		pixel_ptr += screen_w * 4;
	}
} 
