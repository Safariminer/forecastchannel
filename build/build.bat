@echo off

REM Change "G:/cpp/mingw64/include" and "G:/cpp/mingw64/lib" to your include and lib paths.

g++ ../source/main.cpp ../source/Game.cpp ../source/Splash.cpp ../source/Forecast.cpp ../source/Audio.cpp -o forecast.exe -I"G:/cpp/mingw64/include" -L"G:/cpp/mingw64/lib" -lraylib -lm -lwinmm -lgdi32
