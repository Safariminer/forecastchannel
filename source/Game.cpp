#include "Game.h"
#include "Forecast.h"
#include "Splash.h"
#include <vector>


int Scene = 0;

std::vector<GC_Scene*> SceneList;

void GC_LoadScene(int m){
    SceneList.at(Scene)->Deinit();
    Scene = m;
    SceneList.at(Scene)->Init();
}

void GC_InitSceneList(){
    SceneList.push_back(new Splash());
    SceneList.push_back(new Forecast());
    //SceneList.push_back(new MainMenu());
    //SceneList.push_back(new SoloLevel1());
}

void GC_Display(){
    SceneList.at(Scene)->Display();
}

void GC_Input(){
    SceneList.at(Scene)->Input();
}

void GC_Misc(){
    SceneList.at(Scene)->Misc();
}