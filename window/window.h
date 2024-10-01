#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int create_window(const char *title, int width, int height);
void destroy_window();
void render_text(const char *text, int x, int y);

#endif
