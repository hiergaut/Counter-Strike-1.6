#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <SDL2/SDL_syswm.h>

SDL_Window* window = NULL;
const int WIDTH = 640;
const int HEIGHT = 480;
int main (int argc, char* args[]) {

  // Initialize SDL systems
  if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n",
           SDL_GetError());
  }
  else {
    //Create a window
     window = SDL_CreateWindow("BGFX Tutorial",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                WIDTH, HEIGHT,
                                SDL_WINDOW_SHOWN);
    if(window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n",
             SDL_GetError());
    }
  }

   // Collect information about the window from SDL
  SDL_SysWMinfo wmi;
  SDL_VERSION(&wmi.version);
  if (!SDL_GetWindowWMInfo(window, &wmi)) {
    return 1;
  }

  bgfx::PlatformData pd;
  // and give the pointer to the window to pd
  pd.ndt = wmi.info.x11.display;
  pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;

  // Tell bgfx about the platform and window
  bgfx::setPlatformData(pd);

  // Render an empty frame
  bgfx::renderFrame();

  // Initialize bgfx
  bgfx::init();

  // Reset window
  bgfx::reset(WIDTH, HEIGHT, BGFX_RESET_VSYNC);

  // Enable debug text.
  bgfx::setDebug(BGFX_DEBUG_TEXT /*| BGFX_DEBUG_STATS*/);

  // Set view rectangle for 0th view
  bgfx::setViewRect(0, 0, 0, uint16_t(WIDTH), uint16_t(HEIGHT));

  // Clear the view rect
  bgfx::setViewClear(0,
                     BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH,
                     0x443355FF, 1.0f, 0);

  // Set empty primitive on screen
  bgfx::touch(0);


  // Poll for events and wait till user closes window
  bool quit = false;
  SDL_Event currentEvent;
  while(!quit) {
    while(SDL_PollEvent(&currentEvent) != 0) {
      if(currentEvent.type == SDL_QUIT) {
        quit = true;
      }
    }

	bgfx::frame();
  }

  // Free up window
  SDL_DestroyWindow(window);
  // Shutdown SDL
  bgfx::shutdown();
  SDL_Quit();


  return 0;
}
