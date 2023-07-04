/*
** EPITECH PROJECT, 2023
** audio.h
** File description:
** -> Audio library to handle sounds and musics.
*/

#pragma once

#include <stdbool.h>
#include <SFML/Audio.h>
#include "../lib/audio/audio_play.h"
#include "../lib/audio/audio_play.h"

#ifdef AUDIO_DEFAULT_VOLUME
    #undef AUDIO_DEFAULT_VOLUME
#endif
// To be used with init_audio as init_audio(audio_ptr, DEFAULT_VOLUME)
#define AUDIO_DEFAULT_VOLUME AUDIO_DONT_CHANGE_VOLUME, AUDIO_DONT_CHANGE_VOLUME

/*
    Enum to get the current state of a BGM / SFX, used in audio_t structure:
        audio.[bgm/sfx]_state.
    Beware, members order matters ! Must be the same as audio_control_t with
        AUDIO_NOT_YET_STARTED at the end !
*/
typedef enum {
    AUDIO_PLAYING,
    AUDIO_PAUSED,
    AUDIO_STOPPED,
    AUDIO_NOT_YET_STARTED
} audio_state_t;

/*
    Structure to represent a SFX.
    Is not meant to be directly used, as it's properly handled in audio_t.
*/
typedef struct {
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

/*
    Structure for BGM and SFX.
    Beware, members order matters !
        -> At the top come the BGM
        -> Then the SFX
        -> And the current pointers (BGM firstly, followed by SFX)
        -> States at next (BGM then SFX)
        -> And volumes come at the end (BGM then SFX)
    Breaking these rules may break some functionnalities and may cause crash.
*/
typedef struct {
    sfMusic *bgm_main;
    sfMusic *bgm_boss;
    sfMusic *bgm_menu;
    sound_t sfx_quest;
    sound_t sfx_explosion;
    sound_t sfx_level_up;
    sound_t sfx_error;
    sound_t sfx_nyah;
    sound_t sfx_49_3;
    sfMusic *current_bgm;
    audio_state_t bgm_state;
    float sfx_volume;
    float bgm_volume;
} audio_t;

/*
    Enum to list BGM, meant to be used as:
        audio_control_bgm(audio_ptr, MAIN_BGM) for instance.
    MAX_BGM isn't meant to be directly used, as it's a sentinel to highlight
        the max value.
*/
typedef enum {
    BGM_MAIN,
    BGM_BOSS,
    BGM_MENU,
    BGM_MAX
} bgm_t;

/*
    Enum to list SFX, meant to be used as:
        audio_control_sfx(audio_ptr, QUEST_SFX) for instance.
    MAX_SFX isn't meant to be directly used, as it's a sentinel to highlight
        the max value.
    SFX_ERROR is a SFX which represents an error in-game, DOESN'T MEAN
        that an there's some memory-related error !
*/
typedef enum {
    SFX_QUEST,
    SFX_EXPLOSION,
    SFX_LEVEL_UP,
    SFX_ERROR,
    SFX_NYAH,
    SFX_49_3,
    SFX_MAX
} sfx_t;

/*
    Enum to represent the actions when calling audio_control_* functions.
    Beware, members order matters !
    Must be the same as audio_state_t !
    AUDIO_CONTROL_MAX is not meant to be used directly, as it is a sentinel
        to highliht the max value.
    AUDIO_RESUME = AUDIO_PLAY is intended, just for readability purpose.
*/
typedef enum {
    AUDIO_PLAY,
    AUDIO_RESUME = AUDIO_PLAY,
    AUDIO_PAUSE,
    AUDIO_STOP,
    AUDIO_CONTROL_MAX
} audio_control_t;

void audio_init_base(audio_t *audio, float bgm_volume, float sfx_volume);
bool audio_init_bgm(sfMusic **bgm, const char *path, float bgm_volume);
bool audio_init_sfx(sound_t *sound, const char *path, float volume);
bool audio_init(audio_t *audio, float bgm_volume, float sfx_volume);
void audio_free(audio_t *audio);
void audio_free_sfx(sound_t *sound);

bool audio_set_active_bgm(audio_t *audio, bgm_t bgm, bool start);
bool audio_control_bgm(audio_t *audio, audio_control_t action);
bool audio_play_sfx(audio_t *audio, sfx_t sfx);
bool audio_set_bgm_pitch(audio_t *audio, float pitch);

bool audio_is_volume_ok(float volume);
void audio_update_volume(audio_t *audio);

extern const char *const BGM_MENU_PATH;
extern const char *const BGM_BOSS_PATH;
extern const char *const BGM_MAIN_PATH;

extern const char *const SFX_QUEST_PATH;
extern const char *const SFX_EXPLOSION_PATH;
extern const char *const SFX_LEVEL_UP_PATH;
extern const char *const SFX_ERROR_PATH;
extern const char *const SFX_NYAH_PATH;
extern const char *const SFX_49_3_PATH;

extern const float AUDIO_DONT_CHANGE_VOLUME;
extern const float AUDIO_BGM_DEFAULT_VOLUME;
extern const float AUDIO_SFX_DEFAULT_VOLUME;
