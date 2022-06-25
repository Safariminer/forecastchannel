#include <raylib.h>
#include <iostream>
#include "Game.h"

int main(){
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "ForecastChannel"); // Initialize Window
    SetTargetFPS(120); // Set Target FPS
    SetWindowState(FLAG_FULLSCREEN_MODE);
    InitAudioDevice();
    GC_InitSceneList(); // Initialize list of all Grilled Cheese scenes
    GC_LoadScene(0); // Load scene 0
    while(!WindowShouldClose()){
        SetExitKey(0);
        GC_Display();
        GC_Input();
        GC_Misc();
    }

}