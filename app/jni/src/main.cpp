#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <glm.hpp>

#include <android/log.h>

#define LOG(...) __android_log_print(ANDROID_LOG_DEBUG, "sdldemo", __VA_ARGS__)

int SDL_main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;

    int running = 1;

    LOG("started");

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL Hello World",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bitmapSurface = IMG_Load("images/portrait.png");
    if( bitmapSurface == NULL )
    {
        SDL_Log( "x713 : IMAGE NOT LOADED. Error code : %s", IMG_GetError() );
    }
    else
    {
        SDL_Log( "x713 : IMAGE LOADED" );
    }
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    //IMAGES
    while (running) {
        SDL_Event event;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_AC_BACK) {
                LOG("x713 :  pressed back button, terminating");
                running = 0;
            }
        }
    }

    LOG("finished");

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}