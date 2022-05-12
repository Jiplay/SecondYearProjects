/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyAudioE
*/

#include "MyAudioE.hpp"

MyAudioE::MyAudioE()
{
    InitAudioDevice();
}

MyAudioE::~MyAudioE()
{
    CloseAudioDevice();
}

Sound MyAudioE::my_LoadSound(const char *fileName)
{
    Sound fxButton = LoadSound(fileName);
    return fxButton;
}

Music MyAudioE::my_LoadMusicStream(const char *fileName)
{
    Music music = LoadMusicStream(fileName);
    return music;
}

void MyAudioE::my_PlayMusicStream(Music music)
{
    PlayMusicStream(music);
}

void MyAudioE::my_SetSoundVolume(Sound sound, float volume)
{
    SetSoundVolume(sound, volume);
}

void MyAudioE::my_SetMusicVolume(Music music, float volume)
{
    SetMusicVolume(music, volume);
}

void MyAudioE::my_UpdateMusicStream(Music music)
{
    UpdateMusicStream(music);
}

void MyAudioE::my_PlaySound(Sound sound)
{
    PlaySound(sound);
}

void MyAudioE::my_PauseMusicStream(Music music)
{
    PauseMusicStream(music);
}

void MyAudioE::my_ResumeMusicStream(Music music)
{
    ResumeMusicStream(music);
}

void MyAudioE::my_UnloadSound(Sound sound)
{
    UnloadSound(sound);
}

void MyAudioE::my_UnloadMusicStream(Music music)
{
    UnloadMusicStream(music);
}