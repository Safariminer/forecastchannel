#include <raylib.h>
#include "Splash.h"
#include <iostream>
#include "Game.h"

const char * bigtitle = "ForecastChannel";
Vector2 titlepos;
Font vcr;
Color Textcolor = {255,255,255,255};
void Splash::Init(){
    vcr = LoadFontEx("data/vcr.ttf", 180, 0, 360);
    titlepos = MeasureTextEx(vcr, bigtitle, 72, 0);
    titlepos.x = GetScreenWidth()/2 - titlepos.x/2;
    titlepos.y = GetScreenHeight()/2 - titlepos.y/2;
    Textcolor = {255,255,255,255};
}


void Splash::Display(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTextEx(vcr, bigtitle, titlepos, 72, 0, Textcolor);
    DrawTextEx(vcr, FC_VERSION, {0,0}, 30, 0, WHITE);
    EndDrawing();
}

void Splash::Input(){

}
void Splash::Misc(){
    if(Textcolor.a > 0) Textcolor.a--;
    
    if(Textcolor.a == 0) GC_LoadScene(1);

}
void Splash::Deinit(){

    UnloadFont(vcr);
}

/* CODE TO PORT TO GRILLED CHEESE ENGINE:
#include <raylib.h>
#include <iostream>
#include <cstdio>

int main(){
    const char * bigtitle = "ForecastChannel";
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), bigtitle);
    SetTargetFPS(120);
    SetWindowState(FLAG_FULLSCREEN_MODE);
    //ToggleFullscreen();
    Font vcr = LoadFontEx("data/vcr.ttf", 180, 0, 360);
    Vector2 titlepos = MeasureTextEx(vcr, bigtitle, 72, 0);
    titlepos.x = GetScreenWidth()/2 - titlepos.x/2;
    titlepos.y = GetScreenHeight()/2 - titlepos.y/2;
    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(vcr, bigtitle, titlepos, 72, 0, WHITE);
        EndDrawing();
    }
    UnloadFont(vcr);
    CloseWindow();
}
*/
