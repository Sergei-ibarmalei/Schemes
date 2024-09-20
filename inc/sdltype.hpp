#pragma once

#include <SDL2/SDL.h>

namespace sch
{
    class SDL
    {
        private:
            SDL_Window*     window {nullptr};
            SDL_Renderer*   render {nullptr};
            SDL_Event e;

            bool status {true};
        public:
            SDL(const char* appName);
            ~SDL();
            SDL(const SDL&) = delete;
            SDL& operator=(const SDL&) = delete;
            SDL_Renderer* Render() {return render;}
            SDL_Event&    Event()  {return e;}
            bool Status() const {return status;}
    };
}
