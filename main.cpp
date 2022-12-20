#pragma once
#include <Windows.h>
#include "GameOfLife.h"

#undef main
#define LIMIT_RATE 1
#define TICK_RATE 50

int main() {

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);

	unsigned long generation = 0;


	CellMap current_map(cmap_w, cmap_h);
	current_map.Init();

	SDL_Event e;

	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
			if (e.type == SDL_QUIT)
				quit = true;

		generation++;

		current_map.NextGen();

		SDL_UpdateWindowSurface(window);

		if (LIMIT_RATE)
			SDL_Delay(TICK_RATE);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "Total Generations: " << generation << "\nSeed: " << seed << std::endl;

	system("pause");

	return 0;
}