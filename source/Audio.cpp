#include "Audio.h"
#include <windows.h>
#include <winuser.h>

void FC_PlayMusic(){
    PlaySound("data/song.wav", NULL, SND_LOOP | SND_ASYNC);
}

void FC_StopMusic(){
    PlaySound(NULL, 0, 0);
}