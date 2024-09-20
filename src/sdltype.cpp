#include <iostream>
#include "../inc/sdltype.hpp"
#include "../const/graph.hpp"
#include "flags.hpp"

sch::SDL::SDL(const char* appName)
{
    if (!appName) const char* appName {"Scheme Observer"};
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ||
        (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")))
    {
        status = false;
        return;
    }

    window = SDL_CreateWindow(appName,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            w_w,
            w_h,
            SDL_WINDOW_SHOWN);

    if (!window)
    {
#ifdef LOGTOSCREEN
        std::cout << "Cannot create window, abort.\n";
#endif
        status = false;
        return;
    }

    render = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);

    if (!render)
    {
#ifdef LOGTOSCREEN
        std::cout << "Cannot create render, abort.\n";
#endif
        status = false;
        return;
    }

 

}
