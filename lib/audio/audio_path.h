/*
** EPITECH PROJECT, 2023
** audio_path.h
** File description:
** -> Paths for audio assets.
*/

#pragma once

#ifdef BGM
    #undef BGM
#endif
/*
    Macro to ease BGM path handling.
    path must be an HARDCODED literal string which only contains the title,
    then BGM("Bonetrousle") will be "musics/Bonetrousle.ogg"
*/
#define BGM(path) "musics/" path ".ogg"

#ifdef SFX
    #undef SFX
#endif
/*
    Macro to ease SFX path handling.
    path must be an HARDCODED literal string which only contains the title,
    then SFX("explosion") will be "musics/explosion.ogg"
*/
#define SFX(path) "sounds/" path ".ogg"

const char *const BGM_MENU_PATH = BGM("Kevin MacLeod - Happy Bee");
const char *const BGM_BOSS_PATH = BGM("Bonetrousle");
const char *const BGM_MAIN_PATH = BGM("Dalle Béton 49.3");

const char *const SFX_QUEST_PATH = SFX("Discord Notification");
const char *const SFX_EXPLOSION_PATH = SFX("Explosion");
const char *const SFX_LEVEL_UP_PATH = SFX("Level Up");
const char *const SFX_ERROR_PATH = SFX("Error");
const char *const SFX_NYAH_PATH = SFX("Nyah");
const char *const SFX_49_3_PATH = SFX("49.3");
