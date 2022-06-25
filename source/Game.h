#pragma once
#ifndef GAME_H
#define GAME_H
#define FC_VERSION (const char *)"ForecastChannel Alpha 0.0.0"

#include <raylib.h>

class GC_Scene{ /* Main scene class. Contains initialization and deinitialization funcs as well as general in-game functions */
public:
    virtual void Init() = 0;
    virtual void Display() = 0;
    virtual void Input() = 0;
    virtual void Misc() = 0;
    virtual void Deinit() = 0;
};

extern Font vcr;

void GC_LoadScene(int m); // Load a scene
void GC_Display(); // Call the current scene's display function
void GC_Input(); // Call the current scene's input function
void GC_Misc(); // Call the current scene's miscellaneous function
void GC_InitSceneList(); // Initialize the list of scenes
#endif