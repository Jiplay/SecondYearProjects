/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyAudioE
*/

#ifndef MYAUDIOE_HPP_
#define MYAUDIOE_HPP_

#include "raylib.h"
#include <iostream>

class MyAudioE
{
private:
public:
    MyAudioE(/* args */);
    ~MyAudioE();
    Sound my_LoadSound(const char *fileName);
    Music my_LoadMusicStream(const char *fileName);
    void my_PlayMusicStream(Music music);
    void my_SetSoundVolume(Sound sound, float volume);
    void my_SetMusicVolume(Music music, float volume);
    void my_UpdateMusicStream(Music music);
    void my_PlaySound(Sound sound);
    void my_PauseMusicStream(Music music);
    void my_ResumeMusicStream(Music music);
    void my_UnloadSound(Sound sound);
    void my_UnloadMusicStream(Music music);
};

#endif /* !MYAUDIOE_HPP_ */