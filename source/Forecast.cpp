#include "Forecast.h"
#include <iostream>
#include <vector>
#include "FC.h"
#include "Audio.h"
#include <raylib.h>
#include <chrono>
#include <ctime>




time_t currentTime; // Stores the current time
int frame = 0; // Stores the frame you're on
int town = 0; // Stores the town number
std::vector<TownForecast> forecasts; // Vector of forecasts


void Forecast::Init(){
    FC_PlayMusic();
    currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    vcr = LoadFontEx("data/vcr.ttf", 180, 0, 360);
    // Create and push Covonia's forecast
    TownForecast covonia = {"Covonia", "Did you know:\nA dictionary\ncontains words.", {25, 27, 26, 23, 24, 28, 19}, celsius};
    forecasts.push_back(covonia);

    // Create and push Puppetville's forecast
    TownForecast puppetville = {"Puppetville", "Did you know:\nPuppets can\neasily travel\nfrom the US to\nUSSR.", {21, 22, 21, 20, 23, 24, 18}, celsius};
    forecasts.push_back(puppetville);

    // Create and push Aqueusetown's forecast
    TownForecast aqueusetown = {"Aqueusetown", "Did you know:\nThe game crashed.\n@aqueuse", {20, 21, 22, 23, 24, 25, 20}, celsius};
    forecasts.push_back(aqueusetown);
    
}

void Forecast::Display(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(0, 0, (int)(GetScreenWidth() * 0.21), GetScreenHeight(), BLUE);
    DrawRectangle(0, (GetScreenHeight()-GetScreenHeight()*0.17), GetScreenWidth(), (int)(GetScreenHeight()*0.17), WHITE);
    
    DrawRectangle(0, (GetScreenHeight()-GetScreenHeight()*0.17), (int)(GetScreenWidth() * 0.21), (int)(GetScreenHeight()*0.17)+1, BLACK);
    DrawTextEx(vcr, std::ctime(&currentTime), {3, (float)(GetScreenHeight()-(GetScreenHeight()*0.17)/2)-12}, 24, 0, WHITE);
    DrawTextEx(vcr, forecasts.at(town).funFact.c_str(), {3, 3}, 30, 0, YELLOW);

    DrawTextEx(vcr, forecasts.at(town).townName.c_str(), {(float)(GetScreenWidth() * 0.21) + 3, 3}, 72, 0, GREEN);

    DrawTextEx(vcr, "Sunday", {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*0, (float)(GetScreenHeight()/3-15)}, 30, 0, YELLOW);
    DrawTextEx(vcr, "Monday", {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*1, (float)(GetScreenHeight()/3-15)}, 30, 0, YELLOW);
    DrawTextEx(vcr, "Tuesday", {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*2, (float)(GetScreenHeight()/3-15)}, 30, 0, YELLOW);
    DrawTextEx(vcr, "Wednesday", {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*3, (float)(GetScreenHeight()/3-15)}, 30, 0, YELLOW);
    DrawTextEx(vcr, "Thursday", {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*4, (float)(GetScreenHeight()/3-15)}, 30, 0, YELLOW);
    DrawTextEx(vcr, "Friday", {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*5, (float)(GetScreenHeight()/3-15)}, 30, 0, YELLOW);
    DrawTextEx(vcr, "Saturday", {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*6, (float)(GetScreenHeight()/3-15)}, 30, 0, YELLOW);

    switch(forecasts.at(town).mode){
        case celsius:
            for(int i = 0; i < 7; i++){
                DrawTextEx(vcr, TextFormat("%i °c", forecasts.at(town).temperatures.at(i)), {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*i, (float)(GetScreenHeight()/3+17)}, 30, 0, YELLOW);
            }
            break;
        case fahrenheit:
            for(int i = 0; i < 7; i++){
                DrawTextEx(vcr, TextFormat("%i °f", forecasts.at(town).temperatures.at(i)), {(float)(GetScreenWidth() * 0.21) + (float)(GetScreenWidth() * 0.11)*i, (float)(GetScreenHeight()/3+17)}, 30, 0, YELLOW);
            }
            break;break;
    }


    EndDrawing();
}

void Forecast::Input(){
    
}

void Forecast::Misc(){
    currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    frame++;
    if(frame % 1200 == 0){
        //frame = 0;
        town++;
        if(town >= forecasts.size()) town = 0;
        printf("%i", town);
    }
}

void Forecast::Deinit(){
    UnloadFont(vcr);
}